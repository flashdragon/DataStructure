#include "FolderType.h"
#include "FolderLinkedList.h"
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


// Set folder record from keyboard.

void FolderType::SetRecordFromKB()
{
	SetNameFromKB();
}

//파일추가
int FolderType::AddFolder()
{
	//서브 파일이 없으면 배열을 할당
	if (subFolderNum == 0)
	{
		down = new FolderLinkedList<FolderType>;
	}
	/*getFolderTypeFromkeyboard*/
	FolderType temp;
	setFolderTypeProperty(temp);

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
		filelist = new FolderLinkedList<FileType>;
	}

	/*getFolderTypeFromkeyboard*/
	FileType temp;
	temp.setFileTypeProperty();
	//파일 추가에 성공하면 서브파일 갯수를 1증가하고 1을 리턴, 아니면 0을 리턴
	if (filelist->Add(temp))
	{
		subFileNum++;
		return 1;
	}
	return 0;
}

//파일 삭제
int FolderType::DeleteFolder()
{
	int pre = down->GetLength();
	FolderType temp;
	temp.SetNameFromKB();
	down->Delete(temp);
	if (pre > down->GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
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
	temp.SetNameFromKB();
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
	while (down->GetNextItem(data)!=NULL)
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

string FolderType::openfile()
{
	FileType temp;
	temp.SetNameFromKB();
	if (filelist->Openfile(temp))
	{
		return temp.GetName();
	}
	return "";
}

FolderType* FolderType::getParent()
{
	return parent;
	
}
