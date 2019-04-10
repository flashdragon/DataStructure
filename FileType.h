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

	void setFileTypeProperty()
	{
		this->SetRecordFromKB();
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
	*	@brief	Display file address on screen.
	*	@pre	file address is set.
	*	@post	file address is on screen.
	*/
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
	*	@brief	Set file name from keyboard.
	*	@pre	none.
	*	@post	file name is set.
	*/
	void SetDataFromKB();


	/**
	*	@brief	Set file record from keyboard.
	*	@pre	none.
	*	@post	file record is set.
	*/
	void SetRecordFromKB();


	/**
	*	@brief	폴더를 연다
	*	@pre	none.
	*	@post	none
	*	@return 폴더의 주소값.
	*/
	void Open();

	int CompareByName(FileType data);

protected:
	string mName;					///< file name.
	string m_fAddress;				///< file address.
	int data;						///< file data.
	string date;					///< file date.
	string indata;

};