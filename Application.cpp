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
			push(OpenFolder());
			break;
		case 4:		//search by name.
			RetriveFolderByName();
			break;
		case 5:
			cout << "\t   --- Current Folder List ---" << endl;
			DisplayCurrentFolder();
			break;
		case 6:		// display all the records in list on screen.
			DisplayThisfolder();
			break;
		case 7:
			push(GoToUpFolder());
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
///폴더를 연다
FolderType* Application::OpenFolder()
{
	FolderType* temp = cur_Folder->Open();
	if (temp != 0)
	{
		return cur_Folder = temp;
	}
	return NULL;
}

///상위폴더에 들어간다.
FolderType* Application::GoToUpFolder()
{
	if (cur_Folder->GetAddress() != "root")
	{
		return cur_Folder = cur_Folder->getParent();
	}
	cout << "\t최상위 폴더입니다" << endl;
	return 0;
}
///큐에 넣는다
void Application::push(FolderType* temp)
{
	if (temp == NULL) 
	{
		return;
	}
    //
	for (int i = front; i < back; i++)
	{
		if (queue[i] == temp)
		{
			for (int j = i; j < back; j++)
			{
				queue[j] = queue[j + 1];
			}
			back--;
			cnt--;
			break;
		}
	}
	queue[back] = temp;
	back++;
	back %= MAXFOLDERSIZE;
	cnt++;
}
///큐에서 뺀다.
void Application::pop()
{
	cnt--;
	queue[front] = NULL;
	front++;
	front %= MAXFOLDERSIZE;
}



// Display all records in the list on screen.
void Application::DisplaySubfolder()
{
	cur_Folder->DisplayProperty();
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
	for (int i = back-1; i>=0; i--)
	{
		cout << queue[i]->GetName() << endl;
	}
}