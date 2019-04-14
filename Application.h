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
		stacknum = 0;
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
	int DeleteFile();

	/**
	*	@brief	리스트에서 해당 이름을 가진 파일을 찾아 제거한다.
	*	@pre	입력하는 이름이 리스트에 존재해야 한다.
	*	@post	리스트에 해당 파일을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void ReplaceFile();

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
	/**
	*	@brief  큐가 비었는지 확인
	*	@pre	none.
	*	@post	none.
	*	@return 비었으면 1리턴.
	*/
	bool isEmpty() 
	{
		return !cnt;
	};
	/**
	*	@brief  큐가 꽉찼는지 확인
	*	@pre	none.
	*	@post	none.
	*	@return 꽉찼으면 1리턴.
	*/
	bool isFull() 
	{
		return cnt == MAXFOLDERSIZE;
	};

	/**
	*	@brief  큐에 집어넣는다.
	*	@pre	none.
	*	@post	큐가 채워진다.
	*	@pram   temp 집어넣는것.
	*/
	void push(string temp);
	/**
	*	@brief  큐에서 뺀다.
	*	@pre	none.
	*	@post	큐에서 하나가 사라진다..
	*/
	void pop();

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

private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	FolderType root;		///< root folder.
	FolderType* cur_Folder;	///< curent folder.
	string queue[MAXFOLDERSIZE]; ///최근 열어본폴더의 주소배열
	int front;						///큐의 앞
	int back;				///큐의 뒤
	int cnt;				///큐의 갯수
	int m_Command;			///< current command number.
	FolderType* stack[100];
	int stacknum;
};

#endif	// _APPLICATION_H