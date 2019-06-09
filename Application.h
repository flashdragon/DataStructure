#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>

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


	void RunFolder();

	int GetFolderCommand();

	void RunFile();

	int GetFileCommand();

	void RunMove();

	int GetMoveCommand();

	

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
	*	@brief	리스트에서 해당 이름을 가진 파일을 찾아 출력한다.
	*	@pre	없음.
	*	@post	찾은 파일이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int RetriveFolderByName();

	/**
	*	@brief	리스트에서 해당 이름을 가진 파일을 찾아 반환한다.
	*	@pre	인자로 받는 FolderType에 이름이 입력되어 있어야 한다.
	*	@post	찾은 파일이 인자로 들어온다.
	*	@param	inData	이름이 입력되 있는 FolderType값.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchListByMemberName( FolderType &inData );

	/**
	*	@brief	리스트에서 해당 이름을 가진 폴더를 찾아 제거한다.
	*	@pre	입력하는 이름이 리스트에 존재해야 한다.
	*	@post	리스트에 해당 폴더를 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int DeleteFolder();

	/**
	*	@brief	리스트에서 해당 이름을 가진 파일을 찾아 제거한다.
	*	@pre	입력하는 이름이 리스트에 존재해야 한다.
	*	@post	리스트에 해당 파일을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int DelFile();

	/**
	*	@brief	리스트에서 해당 이름을 가진 파일을 찾아 제거한다.
	*	@pre	입력하는 이름이 리스트에 존재해야 한다.
	*	@post	리스트에 해당 파일을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void ReFile();

	/**
	*	@brief	리스트에서 해당 이름을 가진 파일을 찾아 제거한다.
	*	@pre	입력하는 이름이 리스트에 존재해야 한다.
	*	@post	리스트에 해당 파일을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int OpenFile();

	/**
	*	@brief	폴더를 연다.
	*	@pre	none.
	*	@post	none.
	*	@return 폴더의 주소를 리턴.
	*/
	FolderType* OpenFolder();
	
	/**
	*	@brief	상위폴더로 간다.
	*	@pre	none.
	*	@post	none.
	*	@return 상위폴더의 주소값을 리턴.
	*/

	FolderType*	GoToUpFolder();
	


	void CopyFolder();



	void CutFolder();

	void PasteFolder();


	void CopFile();

	void CutFile();

	void PasteFile();

	/**
	*	@brief  큐에 폴더를 집어넣는다.
	*	@pre	none.
	*	@post	큐가 채워진다.
	*	@pram   temp 집어넣는것.
	*/
	void FolderPushQue(FolderType* temp);

	/**
	*	@brief  큐에 파일을 집어넣는다.
	*	@pre	none.
	*	@post	큐가 채워진다.
	*	@pram   temp 집어넣는것.
	*/
	void FilePushQue(FileType* temp);
	

	/**
	*	@brief  최근열어본 폴더를 보여준다.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayCurrentFolder();
	/**
	*	@brief	폴더에 이름을 바꾼다.
	*	@pre	폴더가 있다.
	*	@post	폴더의 이름이 바뀐다.
	*/
	void Replace();

	/**
	*	@brief	스택에 폴더의 이름을 넣는다.
	*	@pre	폴더가 있다.
	*	@post	스택의 갯수가 증가한다.
	*/
	void AddStack(FolderType* temp);

	/**
	*	@brief	스택에서 스택의 갯수가 준다.
	*	@pre	폴더가 있다.
	*	@post	스택의 갯수가 준다.
	*/
	void PopStack();

	/**
	*	@brief	전에 있었던 곳으로 간다.
	*	@pre	none.
	*	@post	뒤로간다.
	*/
	void GoToBack();

	/**
	*	@brief	앞으로 간다.
	*	@pre	none.
	*	@post	앞으로 간다.
	*/
	void GoToFront();

	/**
	*	@brief	입력한 주소로 간다.
	*	@pre	none.
	*	@post	입력한 주소로 간다.
	*/
	void GoToAddress();


	void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

private:
	FolderType root;				///< root folder.
	FolderType* cur_Folder;			///< curent folder.
	int m_Command;					///< current command number.
	int Folder_Command;
	int File_Command;
	int Move_Command;
	Stack back;						///< 뒤로가기 기능을 위한 스택
	Queue<FolderType> fol;			///< 최근 열어본 폴더를 위한 큐
	Queue<FileType> fil;			///< 최근 열어본 파일을 위한 큐
	string ad[100];					///< 입력한 주소 자르고 넣은거
	int adnum;						///< 들어갈 주소의 갯수
	FolderType* copy;
	FileType* copyfile;
};

#endif	// _APPLICATION_H