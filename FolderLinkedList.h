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
	*	@brief	�̸��� ��ġ�ϴ� ������ ã�Ƽ� �ش� ������ �̸��� �ٲ۴�.
	*	@pre	�μ� data�� �ִ� �̸��� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� ������ �̸��� ���Ѵ�.
	*	@param	data	�ٲٰ��� �ϴ� �̸��� �Էµ� FolderType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Replace(T data);

	/**
	*	@brief	������ ���� ����.
	*	@pre	������ �־���Ѵ�.
	*	@post	none
	*	@return ������������ �ּҸ� ����.
	*/
	T* Open();

	int Openfile(T temp);

	/**
	*	@brief	���� ��ġ�� ��Ÿ����.
	*	@pre	none.
	*	@post	none
	*	@return ���� ��ġ�� ����.
	*/
	Node<T>* cur()
	{
		return cur_pointer;
	}


private:
	Node<T> * cur_pointer;		///< ���� ������
	Node<T> * f_list;			///< ó�� ������
	Node<T> * pre;				///< ���� ������
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
					cout << "\t�ߺ��� �̸��� �ֽ��ϴ�." << endl;
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

//�̸��� ��ġ�ϴ� ������ ã�Ƽ� ��ȯ��
template<class T>
int FolderLinkedList<T>::Get(T& data)
{
	T CurItem;

	ResetList();	//iterator �ʱ�ȭ
	GetNextItem(CurItem);	//ù���� ������
	while (cur_pointer!=NULL)	//ó������ ������
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
int FolderLinkedList<T>::Delete(T data)
{
	if (Get(data))	//�̸��� ��ġ�ϴ� ������ �߰��Ѵٸ�(1)
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
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//�̸��� ��ġ�ϴ� ������ ã�� ���Ѵٸ� ����(0)�� ����
}

template<class T>
int FolderLinkedList<T>::Replace(T data)
{
	if (Get(data))	//�̸��� ��ġ�ϴ� ������ �߰��Ѵٸ�(1)
	{
		cout << "\t�ٲ� �̸�" << endl;
		cur_pointer->info.SetNameFromKB();
		

		return 1;	//����(1)�� ����
	}
	return 0;	//�̸��� ��ġ�ϴ� ������ ã�� ���Ѵٸ� ����(0)�� ����
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