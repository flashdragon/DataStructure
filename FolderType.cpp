#include "FolderType.h"
#include "SortedLinkedList.h"
FolderType::FolderType(FolderType& data)
{
	this->mName = data.mName;
	this->m_fAddress = data.m_fAddress;
	this->date = data.date;
	this->subFolderNum = data.subFolderNum;
	this->subFileNum = data.subFileNum;
	if (data.down != NULL)
		this->down = new SortedLinkedList<FolderType>(*data.down);
	else
		this->down = NULL;

	if (data.filelist != NULL)
		this->filelist = new SortedLinkedList<FileType>(*data.filelist);
	else
		this->filelist = NULL;
}

FolderType& FolderType::operator=(const FolderType& data)
{
	this->mName = data.mName;
	this->parent = data.parent;
	this->m_fAddress = data.m_fAddress;
	this->date = data.date;
	this->subFolderNum = data.subFolderNum;
	if (data.down != NULL)
		this->down = new SortedLinkedList<FolderType>(*data.down);
	else
		this->down = NULL;

	if (data.filelist != NULL)
		this->filelist = new SortedLinkedList<FileType>(*data.filelist);
	else
		this->filelist = NULL;

	return (*this);
}
void FolderType::GenCreateTime()
{
	time_t tt;
	struct tm * ti;
	time(&tt);
	ti = localtime(&tt);
	stringstream ss;
	ss << setw(4) << ti->tm_year + 1900 << setfill('0') << setw(2) << ti->tm_mon + 1 << setfill('0') << setw(2) << ti->tm_mday << setfill('0') << ti->tm_hour << setfill('0') << setw(2) << ti->tm_min << setfill('0') << setw(2) << ti->tm_sec << "\0";
	date = ss.str();
}
// Set folder name from keyboard.
void FolderType::SetNameFromKB()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\tName : ";
	cin >> mName;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
}

// Set folder Data from keyboard.
void FolderType::SetDataFromKB()
{
	cout << "\tData : ";
	cin >> data;
}




//�����߰�
int FolderType::AddFolder()
{
	//���� ������ ������ �迭�� �Ҵ�
	if (subFolderNum == 0)
	{
		down = new SortedLinkedList<FolderType>;
	}
	/*getFolderTypeFromkeyboard*/
	FolderType temp;
	setFolderTypeProperty(temp);
	cout << endl;
	if (temp.mName.find('/') != -1)
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t�̸��� \'/\'�� �� �� �����ϴ�" << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		return 0;
	}
	//���� �߰��� �����ϸ� �������� ������ 1�����ϰ� 1�� ����, �ƴϸ� 0�� ����
	if (down->Add(temp))
	{
		subFolderNum++;
		return 1;
	}
	return 0;
}
int FolderType::AddFile()
{
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//���� ������ ������ �迭�� �Ҵ�
	if (subFileNum == 0)
	{
		filelist = new SortedLinkedList<FileType>;
	}

	/*getFolderTypeFromkeyboard*/
	FileType temp;
	temp.setFileTypeProperty();
	cout << endl;
	if (temp.GetName().find('/') != -1)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t�̸��� \'/\'�� �� �� �����ϴ�" << endl << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		return 0;
	}
	//���� �߰��� �����ϸ� �������� ������ 1�����ϰ� 1�� ����, �ƴϸ� 0�� ����
	if (filelist->Add(temp))
	{
		subFileNum++;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t=======================\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\tComplete...\n";
		system("pause");
		return 1;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\wFail..." << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	return 0;
}

//���� ����
int FolderType::DeleteFolder(FolderType temp)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int pre = down->GetLength();
	down->Delete(temp);
	if (pre > down->GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		subFolderNum--;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t=======================\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\tComplete...\n";
		system("pause");
		return 1;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "<========DELETE FAIL !=======>" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	system("pause");
	return 0;
}

int FolderType::DelFile(FileType temp)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int pre = filelist->GetLength();
	filelist->Delete(temp);
	if (pre > filelist->GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		subFileNum--;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t=======================\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\tComplete...\n";
		system("pause");
		return 1;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "<========DELETE FAIL !=======>" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	system("pause");
	return 0;
}

int FolderType::ReplaceFolderName()
{
	
	FolderType temp;
	temp.SetNameFromKB();
	
	if (down->Replace(temp))
	{
		down->cur()->info.SetAddress(m_fAddress + "/" + down->cur()->info.GetName());
		return 1;
	}
	return 0;
}

int FolderType::ReplaceFileName()
{

	FileType temp;
	temp.SetFileNameFromKB();
	if (filelist->Replace(temp))
	{
		return 1;
	}
	return 0;
}

//��� ���� ���
void FolderType::DisplayProperty()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (subFolderNum == 0)
	{
		return;
	}
	FolderType data;
	// list�� ��� �����͸� ȭ�鿡 ���
	down->ResetList();
	while (down->GetNextItem(data) != NULL)
	{
		data.DisplayRecordOnScreen();
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t=======================" << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
}

void FolderType::Displayfile()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (subFileNum == 0)
	{
		return;
	}
	FileType file;
	// list�� ��� �����͸� ȭ�鿡 ���
	filelist->ResetList();
	while (filelist->GetNextItem(file) != NULL)
	{
		file.DisplayRecordOnScreen();
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t=======================" << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
}

//�̸����� ������ ã�Ƽ� ����Ѵ�.
int FolderType::SearchListByMemberName(FolderType &inData)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	FolderType tmp;
	if (subFolderNum == 0)
	{
		return 0;
	}
	down->ResetList();//iterator �ʱ�ȭ
	while (down->GetNextItem(tmp) != NULL) //����Ʈ�� ���������� �ݺ�
	{
		if (tmp.GetName().find(inData.GetName()) != -1) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{
			
			tmp.DisplayRecordOnScreen();
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			cout << "\t=======================\n";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			result = 1;	//����(1)
		}
		tmp.SearchListByMemberName(inData);
		tmp.SearchFileByMemberName(inData);
	}
	return result;
}

int FolderType::SearchFileByMemberName(FolderType &inData)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	FileType tmp;
	if (subFileNum == 0)
	{
		return 0;
	}
	filelist->ResetList();//iterator �ʱ�ȭ
	while (filelist->GetNextItem(tmp) != NULL) //����Ʈ�� ���������� �ݺ�
	{
		if (tmp.GetName().find(inData.GetName()) != -1) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{

			tmp.DisplayRecordOnScreen();
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			cout << "\t=======================\n";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			result = 1;	//����(1)
		}
	}
	return result;
}

// Compare two FolderTypes.
RelationType FolderType::CompareByName(const FolderType &data)
{
	if(this->mName > data.mName)
		return GREATER;
	else if(this->mName < data.mName)
		return LESS;
	else
		return EQUAL;
}

FolderType* FolderType::Open(FolderType temp)
{
	if (subFolderNum == 0)
	{
		return NULL;
	}
	FolderType* ab = down->Open(temp);
	if (ab != NULL)
	{
		return ab;
	}
	return NULL;
}

FileType* FolderType::openfile()
{
	FileType* temp = new FileType;
	temp->SetFileNameFromKB();
	if (filelist->Openfile(*temp))
	{
		return temp;
	}
	return NULL;
}

FolderType* FolderType::getParent()
{
	return parent;
	
}

FolderType* FolderType::getFolderPointer(FolderType& temp)
{
	return down->Get(temp);
}

//FileList�� GetPointer�Լ� ����
FileType* FolderType::getFilePointer(FileType& data)
{
	if (filelist == NULL)
	{
		return NULL;
	}
	return filelist->Get(data);
}

void FolderType::SetParent(FolderType* temp)
{
	parent = temp;
}


int FolderType::Paste(FolderType* temp)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//���� ������ ������ �迭�� �Ҵ�
	if (subFolderNum == 0)
	{
		down = new SortedLinkedList<FolderType>;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t������ ������ �̸��� ���ϼ���" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

	temp->SetParent(this);
	temp->SetNameFromKB();
	temp->SetAddress(m_fAddress + "/" + temp->GetName());
	temp->GenCreateTime();
	if (down->Add(*temp))
	{
		subFolderNum++;
		return 1;
	}
	return 0;
}

int FolderType::PasteFile(FileType* temp)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//���� ������ ������ �迭�� �Ҵ�
	if (subFileNum == 0)
	{
		filelist = new SortedLinkedList<FileType>;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t������ ������ �̸��� ���ϼ���" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	temp->SetNameFromKB();
	temp->SetAddress(m_fAddress + "/" + temp->GetName());
	temp->GenCreateTime();
	if (filelist->Add(*temp))
	{
		subFileNum++;
		return 1;
	}
	return 0;
}

