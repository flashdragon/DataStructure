#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "FolderType.h"
#define MAXFOLDERSIZE 5 

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		cnt = 0;
		m_Command = 0;
		root.SetAddress("root");
		root.SetName("rootfolder");
		cur_Folder = &root;
		stacknum = 0;
		frontnum = 0;
	}
	
	/**
	*	destructor.
	*/
	~Application()	{}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int NewFolder();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int NewFile();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplaySubfolder();

	/**
	*	@brief	Display all subfile in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplaySubfile();
	/**
	*	@brief	Display this folder's property on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayThisfolder();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� ������ ã�� ����Ѵ�.
	*	@pre	����.
	*	@post	ã�� ������ ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int RetriveFolderByName();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� ������ ã�� ��ȯ�Ѵ�.
	*	@pre	���ڷ� �޴� FolderType�� �̸��� �ԷµǾ� �־�� �Ѵ�.
	*	@post	ã�� ������ ���ڷ� ���´�.
	*	@param	inData	�̸��� �Էµ� �ִ� FolderType��.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchListByMemberName( FolderType &inData );

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� ������ ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� �̸��� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� ������ �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DeleteFolder();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� ������ ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� �̸��� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� ������ �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DeleteFile();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� ������ ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� �̸��� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� ������ �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	void ReplaceFile();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� ������ ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� �̸��� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� ������ �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int OpenFile();

	/**
	*	@brief	������ ����.
	*	@pre	none.
	*	@post	none.
	*	@return ������ �ּҸ� ����.
	*/
	FolderType* OpenFolder();
	
	/**
	*	@brief	���������� ����.
	*	@pre	none.
	*	@post	none.
	*	@return ���������� �ּҰ��� ����.
	*/

	FolderType*	GoToUpFolder();
	/**
	*	@brief  ť�� ������� Ȯ��
	*	@pre	none.
	*	@post	none.
	*	@return ������� 1����.
	*/
	bool isEmpty() 
	{
		return !cnt;
	};
	/**
	*	@brief  ť�� ��á���� Ȯ��
	*	@pre	none.
	*	@post	none.
	*	@return ��á���� 1����.
	*/
	bool isFull() 
	{
		return cnt == MAXFOLDERSIZE;
	};

	/**
	*	@brief  ť�� ����ִ´�.
	*	@pre	none.
	*	@post	ť�� ä������.
	*	@pram   temp ����ִ°�.
	*/
	void push(string temp);
	/**
	*	@brief  ť���� ����.
	*	@pre	none.
	*	@post	ť���� �ϳ��� �������..
	*/
	void pop();

	/**
	*	@brief  �ֱٿ�� ������ �����ش�.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayCurrentFolder();
	/**
	*	@brief	������ �̸��� �ٲ۴�.
	*	@pre	������ �ִ�.
	*	@post	������ �̸��� �ٲ��.
	*/
	void Replace();

	/**
	*	@brief	���ÿ� ������ �̸��� �ִ´�.
	*	@pre	������ �ִ�.
	*	@post	������ ������ �����Ѵ�.
	*/
	void AddStack(FolderType* temp);

	/**
	*	@brief	���ÿ��� ������ ������ �ش�.
	*	@pre	������ �ִ�.
	*	@post	������ ������ �ش�.
	*/
	void PopStack();

	/**
	*	@brief	���� �־��� ������ ����.
	*	@pre	none.
	*	@post	�ڷΰ���.
	*/
	void GoToBack();

	/**
	*	@brief	������ ����.
	*	@pre	none.
	*	@post	������ ����.
	*/
	void GoToFront();

private:
	FolderType root;				///< root folder.
	FolderType* cur_Folder;			///< curent folder.
	string queue[MAXFOLDERSIZE];	///< �ֱ� ��������� �ּҹ迭
	int cnt;						///< ť�� ����
	int m_Command;					///< current command number.
	FolderType* stack[100];			///< �ڷΰ��� ���
	int stacknum;					///< ������ ����
	int frontnum;					///< ������ ���� ��ɶ� �ʿ��Ѽ�
};

#endif	// _APPLICATION_H