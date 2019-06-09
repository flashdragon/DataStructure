#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "FolderType.h"
#include "Stack.h"
#include "Queue.h"
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
		m_Command = 0;
		root.SetAddress("root");
		root.SetName("rootfolder");
		cur_Folder = &root;
		back.AddStack(cur_Folder);
		adnum = 0;
		copy = NULL;
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
	


	void CopyFolder();

	void CutFolder();

	void PasteFolder();


	/**
	*	@brief  ť�� ������ ����ִ´�.
	*	@pre	none.
	*	@post	ť�� ä������.
	*	@pram   temp ����ִ°�.
	*/
	void FolderPushQue(FolderType* temp);

	/**
	*	@brief  ť�� ������ ����ִ´�.
	*	@pre	none.
	*	@post	ť�� ä������.
	*	@pram   temp ����ִ°�.
	*/
	void FilePushQue(FileType* temp);
	

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

	/**
	*	@brief	�Է��� �ּҷ� ����.
	*	@pre	none.
	*	@post	�Է��� �ּҷ� ����.
	*/
	void GoToAddress();

private:
	FolderType root;				///< root folder.
	FolderType* cur_Folder;			///< curent folder.
	int m_Command;					///< current command number.
	Stack back;						///< �ڷΰ��� ����� ���� ����
	Queue<FolderType> fol;			///< �ֱ� ��� ������ ���� ť
	Queue<FileType> fil;			///< �ֱ� ��� ������ ���� ť
	string ad[100];					///< �Է��� �ּ� �ڸ��� ������
	int adnum;						///< �� �ּ��� ����
	FolderType* copy;
};

#endif	// _APPLICATION_H