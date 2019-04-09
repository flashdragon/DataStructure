
#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

#include"FolderLinkedList.h"
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
		subFileNum = 0;
		
	}

	/**
	*	destructor.
	*/
	~FolderType()	
	{
	}

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
		return subFileNum;
	}

	void setFolderTypeProperty(FolderType &temp)
	{
		temp.parent = this;
		temp.SetRecordFromKB();
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
	*	@brief	Display folder address on screen.
	*	@pre	folder address is set.
	*	@post	folder address is on screen.
	*/
	void DisplayFolderNumberOnScreen()
	{
		cout << "\tSubFolderNumber : " << subFileNum << endl;
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
		DisplayDataOnScreen();
		DisplayDateOnScreen();
		DisplayFolderNumberOnScreen();
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
	*	@brief	Set folder record from keyboard.
	*	@pre	none.
	*	@post	folder record is set.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	리스트에 폴더를 추가한다.
	*	@pre	none.
	*	@post	리스트에 폴더를 추가.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/

	int AddFolder();

	/**
	*	@brief	리스트에서 해당 이름를 가진 폴더를 찾아 제거한다.
	*	@pre	입력하는 폴더의 이름이 리스트에 존재해야 한다.
	*	@post	리스트에 해당 폴더을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/

	int DeleteFolder();

	/**
	*	@brief	모든 파일의 정보를 출력
	*	@pre	none.
	*	@post	모든 파일의 정보가 출력된다.
	*/

	void DisplayProperty();

	/**
	*	@brief	이름으로 파일을 검색한다.
	*	@pre	파일이 있다
	*	@post	파일이 검색된다.
	*	@return	찾으면 1을 리턴.
	*/

	int SearchListByMemberName(FolderType &inData);

	
	
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
	FolderType* Open();

	/**
	*	@brief	상위폴더를 가르킨다.
	*	@pre	none.
	*	@post	none.
	*	@return 상위폴더의 주소를 리턴.
	*/
	FolderType* getParent();
protected:
	string mName;					///< file name.
	string m_fAddress;				///< file address.
	int data;						///< file data.
	string date;					///< file date.
	int subFileNum;					///< file number.
	FolderLinkedList<FolderType>* down;	///< file array.
	FolderType* parent = NULL;
	int result = 0;
};

#endif	// _ITEMTYPE_H
