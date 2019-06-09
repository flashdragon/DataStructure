#include "Application.h"


// Program driver.
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 2:		// read a record and add to list.
			RunFolder();
			break;
		case 3:		//delete
			RunFile();
			break;
		case 4:
			RunMove();
			break;
		case 5:
			RetriveFolderByName();
			break;
		case 6:
			DisplayCurrentFolder();
			break;
		case 7:
			DisplayThisfolder();
			break;
		case 8:
			break;
		}
		if (m_Command == 8)
		{ 
			system("cls");
			break;
		}
			
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	int command;
	system("cls");
	cout << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t       ---- Menu ---- " << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t       Folder Option " << endl;
	cout << "\t       File Option" << endl;
	cout << "\t       Move Option" << endl;
	cout << "\t       Search" << endl;
	cout << "\t       Visited List" << endl;
	cout << "\t       Current Property" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t       Quit(Space Bar)" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n\t       Address:" << cur_Folder->GetAddress() << endl << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	cout << "\t\tSub List" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	DisplaySubfolder();
	DisplaySubfile();
	
	int x = 11;
	int y = 2;
	while (1)
	{
		gotoxy(x, y);
		cout << "▶";

		command = _getch();
		switch (command)
		{
				//위
			case 72:
			{
				if (y > 1 && y < 9)
				{
					gotoxy(x, y);
					cout << "  ";
				}
				y--;
				if (y < 2)
				{
					y = 8;
				}
				break;
			}
			//아래쪽
			case 80:
			{
				if (y > 1 && y < 9)
				{
					gotoxy(x, y);
					cout << "  ";
				}
				y++;
				if (y > 8)
				{
					y = 2;
				}
				break;
			}
			case 13:
			{
				return y;
			}
			case 32:
			{
				return 8;
			}
		}
	}
}

void Application::RunFolder()
{
	while (1)
	{
		Folder_Command = GetFolderCommand();

		switch (Folder_Command)
		{
		case 2:		// 
			NewFolder();
			break;
		case 3:		//delete
			DeleteFolder();
			break;
		case 4:
			Replace();
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
			break;
		}
		if (Folder_Command == 8)
			break;
	}
}

int Application::GetFolderCommand()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	int command;
	system("cls");
	cout << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t       ---- Menu ---- " << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t       New Folder " << endl;
	cout << "\t       Delete Folder" << endl;
	cout << "\t       Rename Folder" << endl;
	cout << "\t       CopyFolder" << endl;
	cout << "\t       CutFolder" << endl;
	cout << "\t       PasteFolder" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t       Quit(Space Bar)" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n\t       Address:" << cur_Folder->GetAddress() << endl << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	cout << "\t\tSub List" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	DisplaySubfolder();
	DisplaySubfile();
	
	int x = 11;
	int y = 2;
	while (1)
	{
		gotoxy(x, y);
		cout << "▶";

		command = _getch();
		switch (command)
		{
				//위
			case 72:
			{
				if (y > 1 && y < 9)
				{
					gotoxy(x, y);
					cout << "  ";
				}
				y--;
				if (y < 2)
				{
					y = 8;
				}
				break;
			}
			//아래쪽
			case 80:
			{
				if (y > 1 && y < 9)
				{
					gotoxy(x, y);
					cout << "  ";
				}
				y++;
				if (y > 8)
				{
					y = 2;
				}
				break;
			}
			case 13:
			{
				return y;
			}
			case 32:
			{
				return 8;
			}
		}
	}
}

void Application::RunFile()
{
	while (1)
	{
		File_Command = GetFileCommand();

		switch (File_Command)
		{
		case 2:		// 
			NewFile();
			break;
		case 3:		//delete
			DelFile();
			break;
		case 4:
			ReFile();
			break;
		case 5:
			OpenFile();
			break;
		case 6:
			CopFile();
			break;
		case 7:
			CutFile();
			break;
		case 8:
			PasteFile();
			break;
		case 9:
			break;
		}
		if (File_Command == 9)
			break;
	}
}

int Application::GetFileCommand()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	int command;
	system("cls");
	cout << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t       ---- Menu ---- " << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t       New File " << endl;
	cout << "\t       Delete File" << endl;
	cout << "\t       Rename File" << endl;
	cout << "\t       OpenFile" << endl;
	cout << "\t       CopyFile" << endl;
	cout << "\t       CutFile" << endl;
	cout << "\t       PasteFile" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t       Quit(Space Bar)" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n\t       Address:" << cur_Folder->GetAddress() << endl << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	cout << "\t\tSub List" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	DisplaySubfolder();
	DisplaySubfile();
	
	int x = 11;
	int y = 2;
	while (1)
	{
		gotoxy(x, y);
		cout << "▶";

		command = _getch();
		switch (command)
		{
			//위
			case 72:
			{
				if (y > 1 && y < 10)
				{
					gotoxy(x, y);
					cout << "  ";
				}
				y--;
				if (y < 2)
				{
					y = 9;
				}
				break;
			}
			//아래쪽
			case 80:
			{
				if (y > 1 && y < 10)
				{
					gotoxy(x, y);
					cout << "  ";
				}
				y++;
				if (y > 9)
				{
					y = 2;
				}
				break;
			}
			case 13:
			{
				return y;
			}
			case 32:
			{
				return 9;
			}
		}
	}
}

void Application::RunMove()
{
	while (1)
	{
		Move_Command = GetMoveCommand();

		switch (Move_Command)
		{
		case 2:		// 
			OpenFolder();
			break;
		case 3:		//delete
			GoToUpFolder();
			break;
		case 4:
			GoToBack();
			break;
		case 5:
			GoToFront();
			break;
		case 6:
			GoToAddress();
			break;
		case 7:
			break;
		}
		if (Move_Command == 7)
			break;
	}
}

int Application::GetMoveCommand()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	int command;
	system("cls");
	cout << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t       ---- Menu ---- " << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t       Open Folder " << endl;
	cout << "\t       Go To Up Folder" << endl;
	cout << "\t       Go To Back" << endl;
	cout << "\t       Go To Front" << endl;
	cout << "\t       Go To Address" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t       Quit(Space Bar)" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n\t       Address:" << cur_Folder->GetAddress() << endl << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	cout << "\t\tSub List" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	DisplaySubfolder();
	DisplaySubfile();
	int x = 11;
	int y = 2;
	while (1)
	{
		gotoxy(x, y);
		cout << "▶";

		command = _getch();
		switch (command)
		{
			//위
			case 72:
			{
				if (y > 1 && y < 8)
				{
					gotoxy(x, y);
					cout << "  ";
				}
				y--;
				if (y < 2)
				{
					y = 7;
				}
				break;
			}
			//아래쪽
			case 80:
			{
				if (y > 1 && y < 8)
				{
					gotoxy(x, y);
					cout << "  ";
				}
				y++;
				if (y > 7)
				{
					y = 2;
				}
				break;
			}
			case 13:
			{
				return y;
			}
			case 32:
			{
				return 7;
			}
		}
	}
}


// Add new record into list.
int Application::NewFolder()
{
	system("cls");
	cout << endl << endl;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// 파일 추가
	if (cur_Folder->AddFolder())
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t\tSubList" << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		DisplaySubfolder();
		cout << "\t\tComplete...\n";
		
		system("pause");
		return 1;
	}
	else
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t파일 생성 실패" << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		system("pause");
		return 0;
	}
}

//이름을 입력받은 item으로 리스트에서 폴더를 찾아서 출력한다.
int Application::RetriveFolderByName()
{
	cout << endl << endl;
	system("cls");
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
	system("pause");
	return 1;
}

//이름으로 파일을 찾아서 제거한다.
int Application::DeleteFolder()
{
	cout << endl << endl;
	system("cls");
	FolderType temp;
	temp.SetNameFromKB();

	return cur_Folder->DeleteFolder(temp);
}
int Application::DelFile()
{
	cout << endl << endl;
	system("cls");
	FileType temp;
	temp.SetFileNameFromKB();
	return cur_Folder->DelFile(temp);
}
void Application::ReFile()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (cur_Folder->ReplaceFileName())
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t=======================\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\tComplete...\n";
	}
	else
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t이름 교체 실패" << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
}
int Application::OpenFile()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	FileType* a= cur_Folder->openfile();
	if (a != NULL)
	{
		FilePushQue(a);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t=======================\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\tComplete...\n";
		system("pause");
		return 1;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t파일을 찾지 못했습니다." << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	system("pause");
	return 0;
}
///폴더를 연다
FolderType* Application::OpenFolder()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	FolderType temp;
	temp.SetNameFromKB();
	FolderType* test = cur_Folder->Open(temp);
	if (test != 0)
	{
		AddStack(test);
		cur_Folder = test;
		FolderPushQue(cur_Folder);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t=======================\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\tComplete...\n";
		system("pause");
		return cur_Folder;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t=======================\n";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t\tFail...\n";
	system("pause");
	return NULL;
}

///상위폴더에 들어간다.
FolderType* Application::GoToUpFolder()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (cur_Folder->GetAddress() != "root")
	{
		cur_Folder = cur_Folder->getParent();
		AddStack(cur_Folder);
		FolderPushQue(cur_Folder);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t=======================\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\tComplete...\n";
		system("pause");
		return cur_Folder;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t최상위 폴더입니다" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	system("pause");
	return 0;
}

void Application::CopyFolder()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (cur_Folder->GetFolderNumber() > 0)
	{
		FolderType temp;
		temp.SetNameFromKB();
		FolderType* test;
		test = cur_Folder->getFolderPointer(temp);

		if (test == NULL)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\t파일을 못 찾았습니다." << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
		else
		{
			copy = test;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			cout << "\t=======================\n";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\tComplete...\n";
		}
	}
	else 
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t서브 폴더가 없습니다." << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	system("pause");
}
		

void Application::CutFolder()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (cur_Folder->GetFolderNumber() > 0)
	{
		FolderType temp;
		temp.SetNameFromKB();
		FolderType* test;
		test = cur_Folder->getFolderPointer(temp);
		if (test == NULL)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\t파일을 못 찾았습니다." << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			system("pause");
		}
		else
		{
			copy = test;
			cur_Folder->DeleteFolder(temp);
		}
	}
	else
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t서브 폴더가 없습니다." << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		system("pause");
	}
}

void Application::PasteFolder()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (copy != NULL)
	{
		FolderType* temp = new FolderType(*copy);
		cur_Folder->Paste(temp);
	}
	else 
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t복사하거나 자르기를 한 파일이 없습니다." << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
}

void Application::CopFile()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (cur_Folder->GetFileNumber() > 0)
	{
		FileType temp;
		temp.SetFileNameFromKB();
		FileType* test;
		test = cur_Folder->getFilePointer(temp);
		if (test == NULL)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\t파일을 못 찾았습니다." << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			system("pause");
		}
		else
		{
			copyfile = test;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			cout << "\t=======================\n";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\t\tComplete...\n";
			system("pause");
		}
	}
	else 
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t서브 폴더가 없습니다." << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		system("pause");
	}
		

}

void Application::CutFile()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (cur_Folder->GetFileNumber() > 0)
	{
		FileType temp;
		temp.SetFileNameFromKB();
		FileType* test;
		test = cur_Folder->getFilePointer(temp);
		if (test == NULL)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\t파일을 못 찾았습니다." << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			system("pause");
		}
		else
		{
			copyfile = test;
			cur_Folder->DelFile(temp);
		}
	}
	else
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t서브 폴더가 없습니다." << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		system("pause");
	}
		
}

void Application::PasteFile()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (copyfile != NULL)
	{
		FileType* temp = new FileType(*copyfile);
		cur_Folder->PasteFile(temp);
	}
	else
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t복사하거나 자르기를 한 파일이 없습니다." << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	system("pause");

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
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	system("pause");
}

void Application::DisplayCurrentFolder() 
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t--- Current Folder List ---" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	fol.PrintQ();
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t--- Current File List ---" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	fil.PrintQ();
	system("pause");
}

void Application::Replace()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (cur_Folder->ReplaceFolderName())
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t=======================\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\tComplete...\n";
	}
	else 
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t이름 교체 실패" << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	system("pause");
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
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (back.GetIndex() > 0)
	{
		PopStack();
		cur_Folder = back.GoBack();
		FolderPushQue(cur_Folder);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t=======================\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\tComplete...\n";
		system("pause");
	}
	else
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t뒤로갈수가 없습니다.";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
}

void Application::GoToFront()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (back.CantGoFront())
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t앞으로 갈곳이 없습니다." << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	else 
	{
		cur_Folder = back.GoFront();

		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\t=======================\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\tComplete...\n";
		system("pause");
	}
}

void Application::GoToAddress()
{
	cout << endl << endl;
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	FolderType* temp = cur_Folder;
	adnum = 0;
	string address;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t가고싶은 경로: ";
	cin >> address;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
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
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\tFail..." << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			return;
		}
	}
	AddStack(cur_Folder);
	FolderPushQue(cur_Folder);
}
