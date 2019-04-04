#include "FolderType.h"
#include "FolderList.h"
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
	if (subFileNum == 0)
	{
		down = new FolderList<FolderType>;
	}
	/*getFolderTypeFromkeyboard*/
	FolderType temp;
	setFolderTypeProperty(temp);

	//파일 추가에 성공하면 서브파일 갯수를 1증가하고 1을 리턴, 아니면 0을 리턴
	if (down->Add(temp))
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
		this->DisplayProperty(); //모든 파일을 출력한다.
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;
	this->DisplayProperty();//모든 파일을 출력한다.
	return 0;
}

//모든 파일 출력
void FolderType::DisplayProperty()
{
	if (subFileNum == 0)
	{
		return;
	}
	FolderType data;
	// list의 모든 데이터를 화면에 출력
	down->ResetList();
	int length = down->GetLength();
	int curIndex = down->GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		cout << "\t";
		data.DisplayNameOnScreen();
		curIndex = down->GetNextItem(data);
	}
}

//이름으로 파일을 찾아서 출력한다.
int FolderType::SearchListByMemberName(FolderType &inData)
{
	FolderType tmp;
	if (subFileNum == 0)
	{
		return 0;
	}
	down->ResetList();//iterator 초기화
	while (down->GetNextItem(tmp) != -1) //리스트의 마지막까지 반복
	{
		if (tmp.GetName().find(inData.GetName()) != -1) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{
			if (result == 0) //처음 찾는 경우라면
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
		}
		tmp.SearchListByMemberName(inData);
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
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

FolderType* FolderType::Open()
{
	if (subFileNum == 0)
	{
		return 0;
	}
	FolderType* ab = down->Open();
	if (ab != 0)
	{
		return ab;
	}
	return 0;
}

FolderType* FolderType::getParent()
{
	return parent;
	
}
