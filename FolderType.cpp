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
	cout << "\tName : ";
	cin >> mName;
}

// Set folder Data from keyboard.
void FolderType::SetDataFromKB()
{
	cout << "\tData : ";
	cin >> data;
}




//파일추가
int FolderType::AddFolder()
{
	//서브 파일이 없으면 배열을 할당
	if (subFolderNum == 0)
	{
		down = new SortedLinkedList<FolderType>;
	}
	/*getFolderTypeFromkeyboard*/
	FolderType temp;
	setFolderTypeProperty(temp);
	if (temp.mName.find('/') != -1)
	{
		cout << "\t이름에 \'/\'를 쓸 수 없습니다" << endl;
		return 0;
	}
	//파일 추가에 성공하면 서브파일 갯수를 1증가하고 1을 리턴, 아니면 0을 리턴
	if (down->Add(temp))
	{
		subFolderNum++;
		return 1;
	}
	return 0;
}
int FolderType::AddFile()
{
	//서브 파일이 없으면 배열을 할당
	if (subFileNum == 0)
	{
		filelist = new SortedLinkedList<FileType>;
	}

	/*getFolderTypeFromkeyboard*/
	FileType temp;
	temp.setFileTypeProperty();
	if (temp.GetName().find('/') != -1)
	{
		cout << "\t이름에 \'/\'를 쓸 수 없습니다" << endl;
		return 0;
	}
	//파일 추가에 성공하면 서브파일 갯수를 1증가하고 1을 리턴, 아니면 0을 리턴
	if (filelist->Add(temp))
	{
		subFileNum++;
		return 1;
	}
	return 0;
}

//파일 삭제
int FolderType::DeleteFolder(FolderType temp)
{
	int pre = down->GetLength();
	down->Delete(temp);
	if (pre > down->GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		subFolderNum--;
		cout << "<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;
	return 0;
}

int FolderType::DeleteFile()
{
	int pre = filelist->GetLength();
	FileType temp;
	string a;
	string name;
	cout << "\tname:";
	cin >> name;
	temp.SetName(name);
	filelist->Delete(temp);
	if (pre > filelist->GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		subFileNum--;
		cout << "<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;
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

//모든 파일 출력
void FolderType::DisplayProperty()
{
	if (subFolderNum == 0)
	{
		return;
	}
	FolderType data;
	// list의 모든 데이터를 화면에 출력
	down->ResetList();
	while (down->GetNextItem(data) != NULL)
	{
		cout << "\t";
		data.DisplayNameOnScreen();
	}
}

void FolderType::Displayfile()
{
	if (subFileNum == 0)
	{
		return;
	}
	FileType file;
	// list의 모든 데이터를 화면에 출력
	filelist->ResetList();
	while (filelist->GetNextItem(file) != NULL)
	{
		cout << "\t";
		file.DisplayNameOnScreen();
	}
}

//이름으로 파일을 찾아서 출력한다.
int FolderType::SearchListByMemberName(FolderType &inData)
{
	FolderType tmp;
	if (subFolderNum == 0)
	{
		return 0;
	}
	down->ResetList();//iterator 초기화
	while (down->GetNextItem(tmp) != NULL) //리스트의 마지막까지 반복
	{
		if (tmp.GetName().find(inData.GetName()) != -1) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{
			
			tmp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
		}
		tmp.SearchListByMemberName(inData);
		tmp.SearchFileByMemberName(inData);
	}
	return result;
}

int FolderType::SearchFileByMemberName(FolderType &inData)
{
	FileType tmp;
	if (subFileNum == 0)
	{
		return 0;
	}
	filelist->ResetList();//iterator 초기화
	while (filelist->GetNextItem(tmp) != NULL) //리스트의 마지막까지 반복
	{
		if (tmp.GetName().find(inData.GetName()) != -1) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{

			tmp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
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
	FileType* temp = NULL;
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


void FolderType::SetParent(FolderType* temp)
{
	parent = temp;
}


int FolderType::Paste(FolderType* temp)
{
	//서브 파일이 없으면 배열을 할당
	if (subFolderNum == 0)
	{
		down = new SortedLinkedList<FolderType>;
	}
	cout << "\t복사한 폴더의 이름을 정하세요" << endl;
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

