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
			Replace();
			break;
		case 4:
			OpenFolder();
			break;
		case 5:
			NewFile();
			break;
		case 6:
			DeleteFile();
			break;
		case 7:
			ReplaceFile();
			break;
		case 8:
			OpenFile();
			break;
		case 9:		//search by name.
			RetriveFolderByName();
			break;
		case 10:
			cout << "\t   --- Current Folder List ---" << endl;
			DisplayCurrentFolder();
			break;
		case 11:	
			GoToBack();
			break;
		case 12:
			GoToFront();
			break;
		case 13:	// display all the records in list on screen.
			DisplayThisfolder();
			break;
		case 14:
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
	cout << "\t   --- Sub Folder List ---" << endl;
	DisplaySubfolder();
	DisplaySubfile();
	
	cout << "\t   ---- Menu ---- " << endl;
	cout << "\t    1 : 폴더 생성" << endl;
	cout << "\t    2 : 폴더 삭제" << endl;
	cout << "\t    3 : 폴더 이름 바꾸기" << endl;
	cout << "\t    4 : 폴더 열기" << endl;
	cout << "\t    5 : 파일 생성" << endl;
	cout << "\t    6 : 파일 삭제" << endl;
	cout << "\t    7 : 파일 이름 바꾸기" << endl;
	cout << "\t    8 : 파일 열기" << endl;
	cout << "\t    9 : 검색" << endl;
	cout << "\t   10 : 최근 열어본 폴더및 파일" << endl;
	cout << "\t   11 : 뒤로 가기" << endl;
	cout << "\t   12 : 앞으로 가기" << endl;
	cout << "\t   13 : 현재 폴더의 속성" << endl;
	cout << "\t   14 : 상위 폴더로 이동" << endl;
	cout << "\t    0 : 종료" << endl; 

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

//이름을 입력받은 item으로 리스트에서 폴더를 찾아서 출력한다.
int Application::RetriveFolderByName()
{
	FolderType item;
	item.SetNameFromKB(); //name을 입력받는다.

	SearchListByMemberName(item); //0이 아니면(찾으면)
	return 1;		
	
}

//이름으로 파일을 찾아서 출력한다.
int Application::SearchListByMemberName( FolderType &inData )
{
	cur_Folder->SearchListByMemberName(inData);
	cur_Folder->SearchFileByMemberName(inData);
	return 1;
}

//이름으로 파일을 찾아서 제거한다.
int Application::DeleteFolder()
{
	return cur_Folder->DeleteFolder();
}
int Application::DeleteFile()
{
	return cur_Folder->DeleteFile();
}
void Application::ReplaceFile()
{
	if (cur_Folder->ReplaceFileName())
	{
		cout << "\t이름 교체 성공" << endl;
	}
	else
	{
		cout << "\t이름 교체 실패" << endl;
	}
}
int Application::OpenFile()
{
	string a= cur_Folder->openfile();
	if (a != "")
	{
		push(a);
		return 1;
	}
	cout << "\t파일을 찾지 못했습니다." << endl;
	return 0;
}
///폴더를 연다
FolderType* Application::OpenFolder()
{
	FolderType* temp = cur_Folder->Open();
	if (temp != 0)
	{
		AddStack(cur_Folder);
		cur_Folder = temp;
		push(cur_Folder->GetName());
		return cur_Folder;
	}
	return NULL;
}

///상위폴더에 들어간다.
FolderType* Application::GoToUpFolder()
{
	if (cur_Folder->GetAddress() != "root")
	{
		AddStack(cur_Folder);
		cur_Folder = cur_Folder->getParent();
		push(cur_Folder->GetName());
		return cur_Folder;
	}
	cout << "\t최상위 폴더입니다" << endl;
	return 0;
}
///큐에 넣는다
void Application::push(string temp)
{
	int change = 6;
	if (temp == "") 
	{
		return;
	}
    //
	for (int i = 0; i < cnt; i++)
	{
		if (queue[i] == temp)
		{
			change = i;
		}
	}
	if (change < 5)
	{
		for (int i = change - 1; i >= 0; i--)
		{
			queue[i + 1] = queue[i];
		}
		queue[0] = temp;
	}
	else if (cnt == 5)
	{
		for (int i = 4; i >= 0; i--)
		{
			queue[i + 1] = queue[i];
		}
		queue[0] = temp;
	}
	else
	{
		for (int i = cnt - 1; i >= 0; i--)
		{
			queue[i + 1] = queue[i];
		}
		queue[0] = temp;
		cnt++;
	}
}
///큐에서 뺀다.
void Application::pop()
{
	queue[cnt] = "";
	cnt--;
}



int Application::NewFile()
{
	cur_Folder->AddFile();
	return 1;
}

// Display all records in the list on screen.
void Application::DisplaySubfolder()
{
	cur_Folder->DisplayProperty();
}

void Application::DisplaySubfile()
{
	cur_Folder->Displayfile();
}
///폴더의 속성을 보여준다.
void Application:: DisplayThisfolder()
{
	if (cur_Folder->GetAddress() != "root")
	{
		cur_Folder->DisplayRecordOnScreen();
	}
	else
	{
		root.DisplayNameOnScreen();
		root.DisplayDataOnScreen();
		root.DisplayFolderNumberOnScreen();
	}
}

void Application::DisplayCurrentFolder() 
{
	for (int i = 0; i < cnt; i++)
	{
		cout << "\t    " << queue[i] << endl;
	}
}

void Application::Replace()
{
	if (cur_Folder->ReplaceFolderName())
	{
		cout << "\t이름 교체 성공" << endl;
	}
	else 
	{
		cout << "\t이름 교체 실패" << endl;
	}
}

void Application::AddStack(FolderType * temp)
{
	stack[stacknum] = temp;
	stacknum++;
	frontnum = stacknum;
}

void Application::PopStack()
{
	stacknum--;
}

void Application::GoToBack()
{
	if (stacknum > 0)
	{
		stack[stacknum] = cur_Folder;
		PopStack();
		cur_Folder = stack[stacknum];
	}
	else
	{
		cout << "\t뒤로갈수가 없습니다.";
	}
}

void Application::GoToFront()
{
	if (stacknum == frontnum)
	{
		cout << "\t앞으로 갈곳이 없습니다." << endl;
	}
	else 
	{
		stacknum++;
		cur_Folder = stack[stacknum];
	}
}
