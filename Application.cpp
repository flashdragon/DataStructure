#include "Application.h"


// Program driver.
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		// read a record and add to list.
			NewFolder();
			break;
		case 2:		//delete
			DeleteFolder();
			break;
		case 3:
			OpenFolder();
			break;
		case 4:		//search by name.
			RetriveFolderByName();
			break;
		case 5:
			LatelyFolder();
			break;
		case 6:		// display all the records in list on screen.
			DisplayThisfolder();
			break;
		case 7:
			GoToUpFolder();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t   Current Path:"<<cur_Folder->GetAddress();
	cout << endl;
	cout << "\t   --- Current Folder List ---" << endl;
	DisplaySubfolder();
	cout << "\t   ---- Menu ---- " << endl;
	cout << "\t   1 : 폴더 생성" << endl;
	cout << "\t   2 : 폴더 삭제" << endl;
	cout << "\t   3 : 폴더 열기" << endl;
	cout << "\t   4 : 검색" << endl;
	cout << "\t   5 : 최근 열어본 폴더" << endl;
	cout << "\t   6 : 현재 폴더의 속성" << endl;
	cout << "\t   7 : 상위 폴더로 이동" << endl;
	cout << "\t   0 : 종료" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::NewFolder()
{
	// 파일 추가
	cur_Folder->AddFolder();
	return 1;
}

//이름을 입력받은 item으로 리스트에서 파일을 찾아서 출력한다.
int Application::RetriveFolderByName()
{
	FolderType item;
	item.SetNameFromKB(); //name을 입력받는다.

	if(SearchListByMemberName(item)) //0이 아니면(찾으면)
		return 1;	//성공(1)을 리턴
	return 0;	//실패(0)을 리턴
}

//이름으로 파일을 찾아서 출력한다.
int Application::SearchListByMemberName( FolderType &inData )
{
	return cur_Folder->SearchListByMemberName(inData);
}

//이름으로 파일을 찾아서 제거한다.
int Application::DeleteFolder()
{
	return cur_Folder->DeleteFolder();
}

int Application::OpenFolder()
{
	FolderType* temp = cur_Folder->Open();
	if (temp != 0)
	{
		cur_Folder = temp;
		return 1;
	}
	return 0;
}

int Application::LatelyFolder()
{
	return 0;
}

int Application::GoToUpFolder()
{
	if (cur_Folder->GetAddress() != "root")
	{
		cur_Folder = cur_Folder->getParent();
		return 1;
	}
	cout << "\t최상위 폴더입니다" << endl;
	return 0;
}



// Display all records in the list on screen.
void Application::DisplaySubfolder()
{
	cur_Folder->DisplayProperty();
}

void Application:: DisplayThisfolder()
{
	if (cur_Folder->GetAddress() != "root")
	{
		cur_Folder->DisplayRecordOnScreen();
	}
	root.DisplayNameOnScreen();
	root.DisplayDataOnScreen();
	root.DisplayFolderNumberOnScreen();
}