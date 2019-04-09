#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;


#define MAXSIZE 5

/**
*	array based simple unsorted list.
*/
template<class T>
class FolderList
{
public:
	/**
	*	default constructor.
	*/
	FolderList()
	{
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~FolderList()	{
	}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized. 
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	파일을 찾아서 해당 파일을 반환한다.
	*	@pre	인수 data에 있는 이름이 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 이름이 입력된 FolderType값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Get(T& data);

	/**
	*	@brief	이름이 일치하는 파일을 찾아서 해당 파일을 제거한다.
	*	@pre	인수 data에 있는 이름이 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 이름이 입력된 FolderType값. 
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(T data);

	/**
	*	@brief	폴더를 열어 들어간다.
	*	@pre	폴더가 있어야한다.
	*	@post	none
	*	@return 오픈한폴더의 주소를 리턴.
	*/
	T* Open();


private:
	T m_Array[MAXSIZE];			///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

// Make list empty.
template<class T>
void FolderList<T>::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
template<class T>
int FolderList<T>::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
template<class T>
bool FolderList<T>::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
template<class T>
int FolderList<T>::Add(T inData)
{
	if (!IsFull())
	{
		T CurItem;
		ResetList();
		GetNextItem(CurItem);

		while (m_CurPointer <= m_Length) //처음부터 끝까지
		{
			int test = CurItem.CompareByName(inData);
			if (test == GREATER || m_CurPointer == m_Length)	//만약 CurItem>inData일경우 혹은 배열의 마지막이라서 비교대상이 없는경우
			{
				
				for (int i = m_Length; i > m_CurPointer; i--)	//맨뒤에서 부터 하나씩 땡긴다.
					m_Array[i] = m_Array[i - 1];	//배열 밀기
				m_Array[m_CurPointer] = inData;	//배열 밀은 후 현재 포인터에 아이템 넣는다.
				m_Length++;	//개수 증가
				break;
			}
			else if (test == EQUAL)
			{
				cout << "\t중복된 이름이 있습니다." << endl;
				return 0;
			}
			GetNextItem(CurItem);	//다음아이템으로
		}
	}
	else
		return 0;

	return 1;
}


// Initialize list iterator.
template<class T>
void FolderList<T>::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
template<class T>
int FolderList<T>::GetNextItem(T& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

//이름이 일치하는 파일을 찾아서 반환함
template<class T>
int FolderList<T>::Get(T& data)
{
	T CurItem;

	ResetList();	//iterator 초기화
	GetNextItem(CurItem);	//첫파일 가져옴
	while (m_CurPointer < m_Length)	//처음부터 끝까지
	{
		switch (CurItem.CompareByName(data))	//입력 아이템과 현재 아이템을 비교
		{
		case EQUAL:	//일치하면
			data = CurItem;	//파일에 현재 아이템을 반환
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 파일의 이름이 더 크면(정렬되있으므로 나머지에 찾는게 없다)
			return 0;	//실패(0)을 리턴
			break;
		default:	//현재 파일의 이름이 더 작으면
			GetNextItem(CurItem);	//다음 파일을 가져온다.(계속 탐색)
			break;
		}
	}
	return 0; //실패시0
}

//이름이 일치하는 파일을 찾아서 제거함
template<class T>
int FolderList<T>::Delete(T data)
{
	if (Get(data))	//이름이 일치하는 파일을 발견한다면(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i] = m_Array[i + 1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;	//이름이 일치하는 파일을 찾지 못한다면 실패(0)을 리턴
}

template<class T>
T* FolderList<T>::Open()
{
	T temp;
	temp.SetNameFromKB();
	if (Get(temp))
	{
		return m_Array + m_CurPointer;
	}
	return 0;
}

#endif	// _UNSORTEDLIST_H