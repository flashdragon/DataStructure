
#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

#include"SortedLinkedList.h"
#include"FileType.h"
using namespace std;

#define FILENAMESIZE 1024


/**
*	Relation between two items.
*/
enum RelationType {LESS, GREATER, EQUAL};


/**
*	item information class.
*/

class FolderType
{
public:
	/**
	*	default constructor.
	*/
	FolderType()
	{
		mName = "";
		m_fAddress = "";
		data = 0;
		date = "";
		subFolderNum = 0;
		subFileNum = 0;
		down = NULL;
		filelist = NULL;
		parent = NULL;
		
	}

	/**
	*	destructor.
	*/
	~FolderType()	
	{
		if (down != NULL)
		{
			delete down;
		}
		if (filelist != NULL)
		{
			delete filelist;
		}
	}


	//복사생성자
	FolderType(FolderType& data);

	//대입연산자
	FolderType& operator= (const FolderType& data);


	/**
	*	@brief	Get folder name.
	*	@pre	folder name is set.
	*	@post	none.
	*	@return	folder name.
	*/
	string GetName()
	{
		return mName;
	}

	/**
	*	@brief	Get folder address
	*	@pre	folder address is set.
	*	@post	none.
	*	@return	folder address.
	*/
	string GetAddress()
	{
		return m_fAddress;
	}
	
	/**
	*	@brief	Get folder data
	*	@pre	folder data is set.
	*	@post	none.
	*	@return	folder data.
	*/
	int GetData()
	{
		return data;
	}

	/**
	*	@brief	Get folder date
	*	@pre	folder date is set.
	*	@post	none.
	*	@return	folder date.
	*/
	string GetDate()
	{
		return date;
	}

	/**
	*	@brief	Get folder number
	*	@pre	folder number is set.
	*	@post	none.
	*	@return	folder number.
	*/
	int GetFolderNumber()
	{
		return subFolderNum;
	}

	/**
	*	@brief	Get file number
	*	@pre	file number is set.
	*	@post	none.
	*	@return	file number.
	*/
	int GetFileNumber()
	{
		return subFileNum;
	}
	/**
	*	@brief	모든 정보를 넣는다.
	*	@pre	none.
	*	@post	상위 폴더, 이름, 시간 주소를 넣는다.
	*   @param  FolderType 새로 만든 폴더
	*/
	void setFolderTypeProperty(FolderType &temp)
	{
		temp.parent = this;
		temp.SetNameFromKB();
		temp.SetAddress(m_fAddress + "/" + temp.mName);
		temp.GenCreateTime();
	}

	/**
	*	@brief	Set folder name.
	*	@pre	none.
	*	@post	folder name is set.
	*	@param	inName	folder name.
	*/
	void SetName(string inName)
	{
		mName = inName;
	}
	
	/**
	*	@brief	Set folder DATA.
	*	@pre	none.
	*	@post	folder name is set.
	*	@param	inName	folder name.
	*/
	void SetData(int indata)
	{
		data = indata;
	}
	/**
	*	@brief	Set folder address.
	*	@pre	none.
	*	@post	folder address is set.
	*	@param	address	folder address.
	*/
	void SetAddress(string address)
	{
		m_fAddress = address;
	}

	/**
	*	@brief	시간을 생성한다.
	*	@pre	none.
	*	@post	현재 시간이 나타난다.
	*/
	void GenCreateTime();



	/**
	*	@brief	Set folder record.
	*	@pre	none.
	*	@post	folder record is set.
	*	@param	inName	 folder name.
	*	@param	indata	 folder data.
	*	@param	indate 	 folder date.
	*	@param	innumber folder's subFile.
	*/
	void SetRecord(string inName)
	{
		SetName(inName);
	}


	/**
	*	@brief	Display folder name on screen.
	*	@pre	folder name is set.
	*	@post	folder name is on screen.
	*/
	void DisplayNameOnScreen() 
	{
		cout << "\tName : " << mName << endl; 
	};

	/**
	*	@brief	Display folder address on screen.
	*	@pre	folder address is set.
	*	@post	folder address is on screen.
	*/
	void DisplayAddressOnScreen() 
	{
		cout << "\tAddress : " << m_fAddress << endl; 
	};

	/**
	*	@brief	Display folder address on screen.
	*	@pre	folder address is set.
	*	@post	folder address is on screen.
	*/
	void DisplayDataOnScreen()
	{
		cout << "\tData : " << data << endl;
	};

	/**
	*	@brief	Display folder address on screen.
	*	@pre	folder address is set.
	*	@post	folder address is on screen.
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tDate : " << date << endl;
	};

	/**
	*	@brief	Display folder number on screen.
	*	@pre	folder number is set.
	*	@post	folder number is on screen.
	*/
	void DisplayFolderNumberOnScreen()
	{
		cout << "\tSubFolderNumber : " << subFolderNum << endl;
	};

	/**
	*	@brief	Display file number on screen.
	*	@pre	file number is set.
	*	@post	file number is on screen.
	*/
	void DisplayFileNumberOnScreen()
	{
		cout << "\tSubFileNumber : " << subFileNum << endl;
	};

	/**
	*	@brief	Display an folder record on screen.
	*	@pre	folder record is set.
	*	@post	folder record is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		parent->DisplayAddressOnScreen();
		DisplayDateOnScreen();
		DisplayFolderNumberOnScreen();
		DisplayFileNumberOnScreen();
	};

	/**
	*	@brief	Set folder name from keyboard.
	*	@pre	none.
	*	@post	folder name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set folder name from keyboard.
	*	@pre	none.
	*	@post	folder name is set.
	*/
	void SetDataFromKB();

	/**
	*	@brief	리스트에 폴더를 추가한다.
	*	@pre	none.
	*	@post	리스트에 폴더를 추가.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/

	int AddFolder();

	/**
	*	@brief	리스트에 파일을 추가한다.
	*	@pre	none.
	*	@post	리스트에 파일을 추가.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/

	int AddFile();

	/**
	*	@brief	리스트에서 해당 이름를 가진 폴더를 찾아 제거한다.
	*	@pre	입력하는 폴더의 이름이 리스트에 존재해야 한다.
	*	@post	리스트에 해당 폴더을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/

	int DeleteFolder(FolderType temp);

	/**
	*	@brief	리스트에서 해당 이름를 가진 파일를 찾아 제거한다.
	*	@pre	입력하는 파일의 이름이 리스트에 존재해야 한다.
	*	@post	리스트에 해당 파일을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/

	int DelFile(FileType temp);

	/**
	*	@brief	리스트에서 해당 이름를 가진 폴더를 찾아 이름을 바꾼다.
	*	@pre	입력하는 폴더의 이름이 리스트에 존재해야 한다.
	*	@post	리스트에 해당 폴더의 이름을 바꾼다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/

	int ReplaceFolderName();

	/**
	*	@brief	리스트에서 해당 이름를 가진 파일를 찾아 이름을 바꾼다.
	*	@pre	입력하는 파일의 이름이 리스트에 존재해야 한다.
	*	@post	리스트에 해당 파일의 이름을 바꾼다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/

	int ReplaceFileName();

	/**
	*	@brief	모든 폴더의 정보를 출력
	*	@pre	none.
	*	@post	모든 폴더의 정보가 출력된다.
	*/

	void DisplayProperty();

	/**
	*	@brief	모든 파일의 정보를 출력
	*	@pre	none.
	*	@post	모든 파일의 정보가 출력된다.
	*/

	void Displayfile();

	/**
	*	@brief	이름으로폴더를 검색한다.
	*	@pre	폴더가 있다
	*	@post	폴더가 검색된다.
	*	@param	FolderType 찾을 폴더위치.
	*	@return	찾으면 1을 리턴.
	*/

	int SearchListByMemberName(FolderType &inData);

	/**
	*	@brief	이름으로파일을 검색한다.
	*	@pre	파일이 있다
	*	@post	파일이 검색된다.
	*	@param	FolderType 찾을 폴더위치.
	*	@return	찾으면 1을 리턴.
	*/

	int SearchFileByMemberName(FolderType &inData);
	
	/**
	*	Compare two FolderTypes.
	*	@brief	Compare two item types by item name.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.name < data.name, 
	*			return GREATER if this.name > data.name then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByName(const FolderType &data);

	/**
	*	@brief	폴더를 연다
	*	@pre	none.
	*	@post	none
	*	@return 폴더의 주소값.
	*/
	FolderType* Open(FolderType temp);

	/**
	*	@brief	파일을 연다
	*	@pre	none.
	*	@post	none
	*	@return 파일의 이름.
	*/
	FileType* openfile();

	/**
	*	@brief	상위폴더를 가르킨다.
	*	@pre	none.
	*	@post	none.
	*	@return 상위폴더의 주소를 리턴.
	*/
	FolderType* getParent();

	FolderType* getFolderPointer(FolderType& temp);

	FileType* getFilePointer(FileType& data);

	void SetParent(FolderType* temp);



	int Paste(FolderType* temp);

	int PasteFile(FileType* temp);




protected:
	string mName;							///< folder name.
	string m_fAddress;						///< folder address.
	int data;								///< folder data.
	string date;							///< folder date.
	int subFolderNum;						///< folder number.
	SortedLinkedList<FolderType>* down;		///< folder array.
	FolderType* parent;						///< 폴더의 상위 폴더.
	int result = 0;							///< 폴더 찾을때 결과.
	SortedLinkedList<FileType>* filelist;	///< 파일의 리스트.
	int subFileNum;							///< 파일리스트의 파일 갯수.
};

#endif	// _ITEMTYPE_H
