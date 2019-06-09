#pragma once
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

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
class SortedLinkedList
{
public:
	/**
	*	default constructor.
	*/
	SortedLinkedList()
	{
		m_Length = 0;
		cur_pointer = NULL;
		f_list = NULL;
		pre = NULL;
	}

	//���������
	SortedLinkedList(SortedLinkedList<T>& item)
	{
		m_Length = item.m_Length;
		item.ResetList();

		if (item.m_Length == 0)
		{
			f_list = NULL;
			cur_pointer = NULL;
		}
		else
		{
			T folder;
			item.GetNextItem(folder);

			f_list = new Node<T>;
			f_list->info = folder;
			f_list->next = NULL;

			Node<T>* pre;
			pre = f_list;

			while (1)
			{
				if (item.cur_pointer->next == NULL)
				{
					break;
				}
				else
				{
					item.GetNextItem(folder);
					Node<T>* node = new Node<T>;
					node->info = folder;
					node->next = NULL;
					pre->next = node;
					pre = pre->next;
				}
			}
		}
	}


	/**
	*	destructor.
	*/
	~SortedLinkedList() 
	{
		MakeEmpty();
	}

	// ���� ������
	SortedLinkedList<T>& operator=(const SortedLinkedList<T>& item)
	{
		m_Length = item.m_Length;
		item.ResetList();

		if (item.m_Length == 0)
		{
			f_list == NULL;
			cur_pointer == NULL;
		}
		else
		{
			T folder;
			item.GetNextItem(folder);
			f_list->data = folder;
			f_list->next = NULL;

			NodeType<T>* prev;
			prev = f_list;

			while (1)
			{
				if (cur_pointer->next == NULL)
				{
					break;
				}
				else
				{
					item.GetNextItem(folder);
					NodeType<T>* node = new NodeType<T>;
					node->data = folder;
					node->next = NULL;
					pre->next = node;
					prev = prev->next;
				}
			}
		}

		return (*this);
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
	int Add(T& data);

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
	T* Get(T& data);

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
	T* Open(T temp);

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
void SortedLinkedList<T>::MakeEmpty()
{
	Node<T>* tempPtr;

	while (f_list != NULL)
	{
		tempPtr = f_list;
		f_list = f_list->next;
		delete tempPtr;
	}

	m_Length = 0;

}


// Get a number of records in current list.
template<class T>
int SortedLinkedList<T>::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
template<class T>
bool SortedLinkedList<T>::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
template<class T>
int SortedLinkedList<T>::Add(T& inData)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
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
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "\t�ߺ��� �̸��� �ֽ��ϴ�." << endl << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
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
void SortedLinkedList<T>::ResetList()
{
	if (cur_pointer != NULL)
		cur_pointer = NULL;
}


// move list iterator to the next item in list and get that item.
template<class T>
Node<T>* SortedLinkedList<T>::GetNextItem(T& data)
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
T* SortedLinkedList<T>::Get(T& data)
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
			return &(cur_pointer->info);	//�����ϸ� �ּҸ� ����
			break;
		case GREATER:	//���� ������ �̸��� �� ũ��(���ĵ������Ƿ� �������� ã�°� ����)
			return NULL;	//����(0)�� ����
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
int SortedLinkedList<T>::Delete(T data)
{
	if (Get(data)!=NULL)	//�̸��� ��ġ�ϴ� ������ �߰��Ѵٸ�
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
int SortedLinkedList<T>::Replace(T data)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (Get(data)!=NULL)	//�̸��� ��ġ�ϴ� ������ �߰��Ѵٸ�(1)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "\t�̸��� �ٲٽʽÿ�." << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cur_pointer->info.SetNameFromKB();
		

		return 1;	//����(1)�� ����
	}
	return 0;	//�̸��� ��ġ�ϴ� ������ ã�� ���Ѵٸ� ����(0)�� ����
}

template<class T>
T* SortedLinkedList<T>::Open(T temp)
{
	
	if (Get(temp)!=NULL)
	{
		return &(cur_pointer->info);
	}
	return 0;
}

template<class T>
int SortedLinkedList<T>::Openfile(T temp)
{
	if (Get(temp)!=NULL)
	{
		temp.Open();
		return 1;
	}
	return 0;
}

#endif	// _LINKED_LIST_H
