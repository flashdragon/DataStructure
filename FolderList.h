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
	*	@brief	������ ã�Ƽ� �ش� ������ ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� �̸��� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� �̸��� �Էµ� FolderType��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Get(T& data);

	/**
	*	@brief	�̸��� ��ġ�ϴ� ������ ã�Ƽ� �ش� ������ �����Ѵ�.
	*	@pre	�μ� data�� �ִ� �̸��� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� item�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� �̸��� �Էµ� FolderType��. 
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Delete(T data);

	/**
	*	@brief	������ ���� ����.
	*	@pre	������ �־���Ѵ�.
	*	@post	none
	*	@return ������������ �ּҸ� ����.
	*/
	T* Open();


private:
	T m_Array[MAXSIZE];;		///< list array.
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

		while (m_CurPointer <= m_Length) //ó������ ������
		{
			int test = CurItem.CompareByName(inData);
			if (test == GREATER || m_CurPointer == m_Length)	//���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
			{
				
				for (int i = m_Length; i > m_CurPointer; i--)	//�ǵڿ��� ���� �ϳ��� �����.
					m_Array[i] = m_Array[i - 1];	//�迭 �б�
				m_Array[m_CurPointer] = inData;	//�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
				m_Length++;	//���� ����
				break;
			}
			else if (test == EQUAL)
			{
				return 0;
			}
			GetNextItem(CurItem);	//��������������
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
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//�̸��� ��ġ�ϴ� ������ ã�Ƽ� ��ȯ��
template<class T>
int FolderList<T>::Get(T& data)
{
	T CurItem;

	ResetList();	//iterator �ʱ�ȭ
	GetNextItem(CurItem);	//ù���� ������
	while (m_CurPointer < m_Length)	//ó������ ������
	{
		switch (CurItem.CompareByName(data))	//�Է� �����۰� ���� �������� ��
		{
		case EQUAL:	//��ġ�ϸ�
			data = CurItem;	//���Ͽ� ���� �������� ��ȯ
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� ������ �̸��� �� ũ��(���ĵ������Ƿ� �������� ã�°� ����)
			return 0;	//����(0)�� ����
			break;
		default:	//���� ������ �̸��� �� ������
			GetNextItem(CurItem);	//���� ������ �����´�.(��� Ž��)
			break;
		}
	}
	return 0; //���н�0
}

//�̸��� ��ġ�ϴ� ������ ã�Ƽ� ������
template<class T>
int FolderList<T>::Delete(T data)
{
	if (Get(data))	//�̸��� ��ġ�ϴ� ������ �߰��Ѵٸ�(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i] = m_Array[i + 1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//�̸��� ��ġ�ϴ� ������ ã�� ���Ѵٸ� ����(0)�� ����
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