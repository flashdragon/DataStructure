#pragma once
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
struct Node
{
	Node* next;
	T info;

};
template<class T>
class FolderLinkedList
{
public:
	/**
	*	default constructor.
	*/
	FolderLinkedList()
	{
		m_Length = 0;
		cur_pointer = NULL;
		f_list = NULL;
		pre = NULL;
	}

	/**
	*	destructor.
	*/
	~FolderLinkedList() 
	{
		MakeEmpty();
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
	Node<T>* GetNextItem(T& data);

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
	*	@brief	이름이 일치하는 파일을 찾아서 해당 파일의 이름을 바꾼다.
	*	@pre	인수 data에 있는 이름이 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 폴더의 이름이 변한다.
	*	@param	data	바꾸고자 하는 이름이 입력된 FolderType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Replace(T data);

	/**
	*	@brief	폴더를 열어 들어간다.
	*	@pre	폴더가 있어야한다.
	*	@post	none
	*	@return 오픈한폴더의 주소를 리턴.
	*/
	T* Open();

	/**
	*	@brief	파일을 열어 들어간다.
	*	@pre	파일이 있어야한다.
	*	@post	none
	*	@param	temp	열고싶은 파일.
	*	@return 성공하면 1을 리턴 실패하면 0을 리턴.
	*/

	int Openfile(T temp);

	/**
	*	@brief	현재 위치를 나타낸다.
	*	@pre	none.
	*	@post	none
	*	@return 현재 위치를 리턴.
	*/
	Node<T>* cur()
	{
		return cur_pointer;
	}


private:
	Node<T> * cur_pointer;		///< 지금 포인터
	Node<T> * f_list;			///< 처음 포인터
	Node<T> * pre;				///< 이전 포인터
	int m_Length;				///< number of elements in list.
};

// Make list empty.
template<class T>
void FolderLinkedList<T>::MakeEmpty()
{
	NodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;

}


// Get a number of records in current list.
template<class T>
int FolderLinkedList<T>::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
template<class T>
bool FolderLinkedList<T>::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
template<class T>
int FolderLinkedList<T>::Add(T inData)
{
	ResetList();
	if (!IsFull())
	{
		Node<T>* temp =new Node<T>;
		temp->info = inData;
		temp->next = NULL;
		T dummy;
		if (f_list == NULL)
		{
			f_list = temp;
		}
		else
		{
			GetNextItem(dummy);
			while (1)
			{
				int test = dummy.CompareByName(inData);
				if (test == 1)
				{
					temp-> next = cur_pointer;
					if (cur_pointer == f_list)
					{
						f_list = temp;
						cur_pointer = temp;
					}
					else
					{
						pre->next = temp;
					}
					return 1;
				}
				else if (test == 2)
				{
					cout << "\t중복된 이름이 있습니다." << endl;
					return 0;
				}
				else if (cur_pointer->next == NULL)
				{
					cur_pointer->next = temp;
					return 1;
				}
				GetNextItem(dummy);
			}
		}
	}
	else
		return 0;

	return 1;
}


// Initialize list iterator.
template<class T>
void FolderLinkedList<T>::ResetList()
{
	cur_pointer = NULL;
}


// move list iterator to the next item in list and get that item.
template<class T>
Node<T>* FolderLinkedList<T>::GetNextItem(T& data)
{
	if (cur_pointer == NULL)
	{
		cur_pointer = f_list;
	}
	else
	{
		pre = cur_pointer;
		cur_pointer = cur_pointer->next;
	}
	if (cur_pointer == NULL)
	{
		
	}
	else
	{
		data = cur_pointer->info;
	}
	return cur_pointer;
}

//이름이 일치하는 파일을 찾아서 반환함
template<class T>
int FolderLinkedList<T>::Get(T& data)
{
	T CurItem;

	ResetList();	//iterator 초기화
	GetNextItem(CurItem);	//첫파일 가져옴
	while (cur_pointer!=NULL)	//처음부터 끝까지
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
int FolderLinkedList<T>::Delete(T data)
{
	if (Get(data))	//이름이 일치하는 파일을 발견한다면(1)
	{
		if (cur_pointer == f_list)
		{
			f_list = cur_pointer->next;
			cur_pointer = f_list;
			pre = NULL; 
		}
		else
		{
			pre->next = cur_pointer->next;
		}
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;	//이름이 일치하는 파일을 찾지 못한다면 실패(0)을 리턴
}

template<class T>
int FolderLinkedList<T>::Replace(T data)
{
	if (Get(data))	//이름이 일치하는 파일을 발견한다면(1)
	{
		cout << "\t바꿀 이름" << endl;
		cur_pointer->info.SetNameFromKB();
		

		return 1;	//성공(1)을 리턴
	}
	return 0;	//이름이 일치하는 파일을 찾지 못한다면 실패(0)을 리턴
}

template<class T>
T* FolderLinkedList<T>::Open()
{
	T temp;
	temp.SetNameFromKB();
	if (Get(temp))
	{
		return &(cur_pointer->info);
	}
	return 0;
}

template<class T>
int FolderLinkedList<T>::Openfile(T temp)
{
	if (Get(temp))
	{
		temp.Open();
		return 1;
	}
	return 0;
}

#endif	// _UNSORTEDLIST_H