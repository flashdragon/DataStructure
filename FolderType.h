
#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

#include"FolderLinkedList.h"
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
		return subFolderNum;
	}

	/**
	*	@brief	��� ������ �ִ´�.
	*	@pre	none.
	*	@post	���� ����, �̸�, �ð� �ּҸ� �ִ´�.
	*   @param  FolderType ���� ���� ����
	*/
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

	/**
	*	@brief	�ð��� �����Ѵ�.
	*	@pre	none.
	*	@post	���� �ð��� ��Ÿ����.
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
	*	@brief	Display folder address on screen.
	*	@pre	folder address is set.
	*	@post	folder address is on screen.
	*/
	void DisplayFolderNumberOnScreen()
	{
		cout << "\tSubFolderNumber : " << subFolderNum << endl;
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
	*	@brief	����Ʈ�� ������ �߰��Ѵ�.
	*	@pre	none.
	*	@post	����Ʈ�� ������ �߰�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/

	int AddFolder();

	/**
	*	@brief	����Ʈ�� ������ �߰��Ѵ�.
	*	@pre	none.
	*	@post	����Ʈ�� ������ �߰�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/

	int AddFile();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� ������ ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� ������ �̸��� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� ������ �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/

	int DeleteFolder();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� ���ϸ� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� ������ �̸��� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� ������ �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/

	int DeleteFile();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� ������ ã�� �̸��� �ٲ۴�.
	*	@pre	�Է��ϴ� ������ �̸��� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� ������ �̸��� �ٲ۴�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/

	int ReplaceFolderName();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� ���ϸ� ã�� �̸��� �ٲ۴�.
	*	@pre	�Է��ϴ� ������ �̸��� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� ������ �̸��� �ٲ۴�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/

	int ReplaceFileName();

	/**
	*	@brief	��� ������ ������ ���
	*	@pre	none.
	*	@post	��� ������ ������ ��µȴ�.
	*/

	void DisplayProperty();

	/**
	*	@brief	��� ������ ������ ���
	*	@pre	none.
	*	@post	��� ������ ������ ��µȴ�.
	*/

	void Displayfile();

	/**
	*	@brief	�̸����������� �˻��Ѵ�.
	*	@pre	������ �ִ�
	*	@post	������ �˻��ȴ�.
	*	@param	FolderType ã�� ������ġ.
	*	@return	ã���� 1�� ����.
	*/

	int SearchListByMemberName(FolderType &inData);

	/**
	*	@brief	�̸����������� �˻��Ѵ�.
	*	@pre	������ �ִ�
	*	@post	������ �˻��ȴ�.
	*	@param	FolderType ã�� ������ġ.
	*	@return	ã���� 1�� ����.
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
	*	@brief	������ ����
	*	@pre	none.
	*	@post	none
	*	@return ������ �ּҰ�.
	*/
	FolderType* Open(FolderType temp);

	/**
	*	@brief	������ ����
	*	@pre	none.
	*	@post	none
	*	@return ������ �̸�.
	*/
	string openfile();

	/**
	*	@brief	���������� ����Ų��.
	*	@pre	none.
	*	@post	none.
	*	@return ���������� �ּҸ� ����.
	*/
	FolderType* getParent();


protected:
	string mName;							///< folder name.
	string m_fAddress;						///< folder address.
	int data;								///< folder data.
	string date;							///< folder date.
	int subFolderNum;						///< folder number.
	FolderLinkedList<FolderType>* down;		///< folder array.
	FolderType* parent = NULL;				///< ������ ���� ����.
	int result = 0;							///< ���� ã���� ���.
	FolderLinkedList<FileType>* filelist;	///< ������ ����Ʈ.
	int subFileNum;							///< ���ϸ���Ʈ�� ���� ����.
};

#endif	// _ITEMTYPE_H
