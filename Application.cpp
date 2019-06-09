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
			CopyFolder();
			break;
		case 6:
			CutFolder();
			break;
		case 7:
			PasteFolder();
			break;
		case 8:
			NewFile();
			break;
		case 9:
			DeleteFile();
			break;
		case 10:
			ReplaceFile();
			break;
		case 11:
			OpenFile();
			break;
		case 12:		//search by name.
			RetriveFolderByName();
			break;
		case 13:
			DisplayCurrentFolder();
			break;
		case 14:	
			GoToBack();
			break;
		case 15:
			GoToFront();
			break;
		case 16:	// display all the records in list on screen.
			DisplayThisfolder();
			break;
		case 17:
			GoToUpFolder();
			break;
		case 18:
			GoToAddress();
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
	cout << "\t   --- Sub List ---" << endl;
	DisplaySubfolder();
	DisplaySubfile();
	
	cout << "\t   ---- Menu ---- " << endl;
	cout << "\t    1 : 폴더 생성" << endl;
	cout << "\t    2 : 폴더 삭제" << endl;
	cout << "\t    3 : 폴더 이름 바꾸기" << endl;
	cout << "\t    4 : 폴더 열기" << endl;
	cout << "\t    5 : 폴더 복사" << endl;
	cout << "\t    6 : 폴더 자르기" << endl;
	cout << "\t    7 : 폴더 붙여넣기" << endl;
	cout << "\t    8 : 파일 생성" << endl;
	cout << "\t    9 : 파일 삭제" << endl;
	cout << "\t   10 : 파일 이름 바꾸기" << endl;
	cout << "\t   11 : 파일 열기" << endl;
	cout << "\t   12 : 검색" << endl;
	cout << "\t   13 : 최근 열어본 폴더및 파일" << endl;
	cout << "\t   14 : 뒤로 가기" << endl;
	cout << "\t   15 : 앞으로 가기" << endl;
	cout << "\t   16 : 현재 폴더의 속성" << endl;
	cout << "\t   17 : 상위 폴더로 이동" << endl;
	cout << "\t   18 : 해당 경로로 이동" << endl;
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
	if (cur_Folder->AddFolder())
	{
		return 1;
	}
	cout << "\t파일 생성 실패" << endl;
	return 0;
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
	FolderType temp;
	temp.SetNameFromKB();
	return cur_Folder->DeleteFolder(temp);
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
	FileType* a= cur_Folder->openfile();
	if (a != NULL)
	{
		FilePushQue(a);
		return 1;
	}
	cout << "\t파일을 찾지 못했습니다." << endl;
	return 0;
}
///폴더를 연다
FolderType* Application::OpenFolder()
{
	FolderType temp;
	temp.SetNameFromKB();
	FolderType* test = cur_Folder->Open(temp);
	if (test != 0)
	{
		AddStack(test);
		cur_Folder = test;
		FolderPushQue(cur_Folder);
		return cur_Folder;
	}
	return NULL;
}

///상위폴더에 들어간다.
FolderType* Application::GoToUpFolder()
{
	if (cur_Folder->GetAddress() != "root")
	{
		cur_Folder = cur_Folder->getParent();
		AddStack(cur_Folder);
		FolderPushQue(cur_Folder);
		return cur_Folder;
	}
	cout << "\t최상위 폴더입니다" << endl;
	return 0;
}

void Application::CopyFolder()
{
	if (cur_Folder->GetFolderNumber() > 0)
	{
		FolderType temp;
		temp.SetNameFromKB();
		FolderType* test;
		test = cur_Folder->getFolderPointer(temp);
		if (test == NULL)
		{
			cout << "\t파일을 못 찾았습니다." << endl;
		}
		else
		{
			copy = test;
		}
	}
	else
		cout << "\t서브 폴더가 없습니다." << endl;
}

void Application::CutFolder()
{
	if (cur_Folder->GetFolderNumber() > 0)
	{
		FolderType temp;
		temp.SetNameFromKB();
		FolderType* test;
		test = cur_Folder->getFolderPointer(temp);
		if (test == NULL)
		{
			cout << "\t파일을 못 찾았습니다." << endl;
		}
		else
		{
			copy = test;
			cur_Folder->DeleteFolder(temp);
		}
	}
	else
		cout << "\t서브 폴더가 없습니다." << endl;

}

void Application::PasteFolder()
{
	if (copy != NULL)
	{
		FolderType* temp = new FolderType(*copy);
		cur_Folder->Paste(temp);
	}
	else
		cout << "\t복사하거나 자르기를 한 파일이 없습니다." << endl;
}


///큐에 폴더를 넣는다
void Application::FolderPushQue(FolderType* temp)
{
	fol.AddQ(temp);
}
///큐에 파일을 넣는다
void Application::FilePushQue(FileType* temp)
{
	fil.AddQ(temp);
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
		root.DisplayFileNumberOnScreen();
	}
}

void Application::DisplayCurrentFolder() 
{
	cout << "\t--- Current Folder List ---" << endl;
	fol.PrintQ();
	cout << "\t--- Current File List ---" << endl;
	fil.PrintQ();
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

void Application::AddStack(FolderType* temp)
{
	back.AddStack(temp);
}

void Application::PopStack()
{
	back.PopStack();
}

void Application::GoToBack()
{
	if (back.GetIndex() > 0)
	{
		PopStack();
		cur_Folder = back.GoBack();
		FolderPushQue(cur_Folder);
	}
	else
	{
		cout << "\t뒤로갈수가 없습니다.";
	}
}

void Application::GoToFront()
{
	if (back.CantGoFront())
	{
		cout << "\t앞으로 갈곳이 없습니다." << endl;
	}
	else 
	{
		cur_Folder = back.GoFront();
	}
}

void Application::GoToAddress()
{
	FolderType* temp = cur_Folder;
	adnum = 0;
	string address;
	cout << "\t가고싶은 경로: ";
	cin >> address;
	ad[0] = "";
	for (int i = 0; i < address.length(); i++)
	{
		if (address[i] == '/')
		{
			adnum++;
			ad[adnum] = "";
		}
		else
		{
			ad[adnum] = ad[adnum] + address[i];
		}
	}
	adnum++;
	cur_Folder = &root;
	for (int i = 1; i < adnum; i++)
	{
		FolderType ttt;
		ttt.SetName(ad[i]);
		FolderType* test = cur_Folder->Open(ttt);
		if (test != NULL)
		{
			cur_Folder = test;
		}
		else
		{
			cur_Folder = temp;
			return;
		}
	}
	AddStack(cur_Folder);
	FolderPushQue(cur_Folder);
}
