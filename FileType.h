#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

#include"FolderLinkedList.h"

using namespace std;


class FileType
{
public:
	/**
	*	default constructor.
	*/
	FileType()
	{
		data = 0;
	}

	/**
	*	destructor.
	*/
	~FileType()
	{

	}
	/**
	*	@brief	Get file name.
	*	@pre	file name is set.
	*	@post	none.
	*	@return	file name.
	*/
	string GetName()
	{
		return mName;
	}

	/**
	*	@brief	Get file address
	*	@pre	file address is set.
	*	@post	none.
	*	@return	file address.
	*/
	string GetAddress()
	{
		return m_fAddress;
	}

	/**
	*	@brief	Get file data
	*	@pre	file data is set.
	*	@post	none.
	*	@return	file data.
	*/
	int GetData()
	{
		return data;
	}

	/**
	*	@brief	Get file date
	*	@pre	file date is set.
	*	@post	none.
	*	@return	file date.
	*/
	string GetDate()
	{
		return date;
	}
	/**
	*	@brief	파일의 정보를 넣는다
	*	@pre	none.
	*	@post	none
	*/
	void setFileTypeProperty()
	{
		this->SetFileNameFromKB();
		this->SetAddress(m_fAddress + "/" + this->mName);
		this->GenCreateTime();
	}

	/**
	*	@brief	Set file name.
	*	@pre	none.
	*	@post	file name is set.
	*	@param	inName	file name.
	*/
	void SetName(string inName)
	{
		mName = inName;
	}

	/**
	*	@brief	Set file DATA.
	*	@pre	none.
	*	@post	file name is set.
	*	@param	inName	file name.
	*/
	void SetData(int indata)
	{
		data = indata;
	}
	/**
	*	@brief	Set file address.
	*	@pre	none.
	*	@post	file address is set.
	*	@param	address	file address.
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
	*	@brief	Set file record.
	*	@pre	none.
	*	@post	file record is set.
	*	@param	inName	 file name.
	*	@param	indata	 file data.
	*	@param	indate 	 file date.
	*	@param	innumber file's subFile.
	*/
	void SetRecord(string inName)
	{
		SetName(inName);
	}


	/**
	*	@brief	Display file name on screen.
	*	@pre	file name is set.
	*	@post	file name is on screen.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << mName << endl;
	};

	/**
	*	@brief	Display file address on screen.
	*	@pre	file address is set.
	*	@post	file address is on screen.
	*/
	void DisplayAddressOnScreen()
	{
		cout << "\tAddress : " << m_fAddress << endl;
	};

	/**
	*	@brief	Display file address on screen.
	*	@pre	file address is set.
	*	@post	file address is on screen.
	*/
	void DisplayDataOnScreen()
	{
		cout << "\tData : " << data << endl;
	};

	/**
	*	@brief	Display file address on screen.
	*	@pre	file address is set.
	*	@post	file address is on screen.
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tDate : " << date << endl;
	};

	/**
	*	@brief	Display an file record on screen.
	*	@pre	file record is set.
	*	@post	file record is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayDataOnScreen();
		DisplayDateOnScreen();
	};

	/**
	*	@brief	Set file name from keyboard.
	*	@pre	none.
	*	@post	file name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	파일의 이름을 찾는다.
	*	@pre	none.
	*	@post   파일이 검색된다.
	*/
	void SetFileNameFromKB();

	/**
	*	@brief	Set file name from keyboard.
	*	@pre	none.
	*	@post	file name is set.
	*/
	void SetDataFromKB();



	/**
	*	@brief	폴더를 연다
	*	@pre	none.
	*	@post	none
	*	@return 폴더의 주소값.
	*/
	void Open();

	/**
	*	@brief	이름으로 파일을 비교한다.
	*	@pre	none.
	*	@post	none.
	*   @param  FileType 비교할 파일.
	*   @return 높으면 1, 같으면 2, 낮으면 0.
	*/
	int CompareByName(FileType data);

protected:
	string mName;					///< file name.
	string m_fAddress;				///< file address.
	int data;						///< file data.
	string date;					///< file date.
	string indata;					///< 파일의 안에 내용

};