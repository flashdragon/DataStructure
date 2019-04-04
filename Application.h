#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "FolderType.h"

#define FILENAMESIZE 1024
#define MAXFOLDERSIZE 1<<15

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
		front = 0;
		back = 0;
		cnt = 0;
		m_Command = 0;
		root.SetAddress("root");
		root.SetName("rootfolder");
		cur_Folder = &root;
		
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
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplaySubfolder();

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
	void push(FolderType* temp);
	/**
	*	@brief  ť���� ����.
	*	@pre	none.
	*	@post	ť���� �ϳ��� �������..
	*/
	void pop();

	/**
	*	@brief  �ֱٿ�� ������ ����.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayCurrentFolder();

private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	FolderType root;		///< root folder.
	FolderType* cur_Folder;	///< curent folder.
	FolderType* queue[MAXFOLDERSIZE]; ///�ֱ� ��������� �ּҹ迭
	int front;						///ť�� ��
	int back;				///ť�� ��
	int cnt;				///ť�� ����
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H