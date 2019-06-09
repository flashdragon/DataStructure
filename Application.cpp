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
	cout << "\t    1 : ���� ����" << endl;
	cout << "\t    2 : ���� ����" << endl;
	cout << "\t    3 : ���� �̸� �ٲٱ�" << endl;
	cout << "\t    4 : ���� ����" << endl;
	cout << "\t    5 : ���� ����" << endl;
	cout << "\t    6 : ���� �ڸ���" << endl;
	cout << "\t    7 : ���� �ٿ��ֱ�" << endl;
	cout << "\t    8 : ���� ����" << endl;
	cout << "\t    9 : ���� ����" << endl;
	cout << "\t   10 : ���� �̸� �ٲٱ�" << endl;
	cout << "\t   11 : ���� ����" << endl;
	cout << "\t   12 : �˻�" << endl;
	cout << "\t   13 : �ֱ� ��� ������ ����" << endl;
	cout << "\t   14 : �ڷ� ����" << endl;
	cout << "\t   15 : ������ ����" << endl;
	cout << "\t   16 : ���� ������ �Ӽ�" << endl;
	cout << "\t   17 : ���� ������ �̵�" << endl;
	cout << "\t   18 : �ش� ��η� �̵�" << endl;
	cout << "\t    0 : ����" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::NewFolder()
{
	// ���� �߰�
	if (cur_Folder->AddFolder())
	{
		return 1;
	}
	cout << "\t���� ���� ����" << endl;
	return 0;
}

//�̸��� �Է¹��� item���� ����Ʈ���� ������ ã�Ƽ� ����Ѵ�.
int Application::RetriveFolderByName()
{
	FolderType item;
	item.SetNameFromKB(); //name�� �Է¹޴´�.

	SearchListByMemberName(item); //0�� �ƴϸ�(ã����)
	return 1;		
	
}

//�̸����� ������ ã�Ƽ� ����Ѵ�.
int Application::SearchListByMemberName( FolderType &inData )
{
	cur_Folder->SearchListByMemberName(inData);
	cur_Folder->SearchFileByMemberName(inData);
	return 1;
}

//�̸����� ������ ã�Ƽ� �����Ѵ�.
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
		cout << "\t�̸� ��ü ����" << endl;
	}
	else
	{
		cout << "\t�̸� ��ü ����" << endl;
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
	cout << "\t������ ã�� ���߽��ϴ�." << endl;
	return 0;
}
///������ ����
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

///���������� ����.
FolderType* Application::GoToUpFolder()
{
	if (cur_Folder->GetAddress() != "root")
	{
		cur_Folder = cur_Folder->getParent();
		AddStack(cur_Folder);
		FolderPushQue(cur_Folder);
		return cur_Folder;
	}
	cout << "\t�ֻ��� �����Դϴ�" << endl;
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
			cout << "\t������ �� ã�ҽ��ϴ�." << endl;
		}
		else
		{
			copy = test;
		}
	}
	else
		cout << "\t���� ������ �����ϴ�." << endl;
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
			cout << "\t������ �� ã�ҽ��ϴ�." << endl;
		}
		else
		{
			copy = test;
			cur_Folder->DeleteFolder(temp);
		}
	}
	else
		cout << "\t���� ������ �����ϴ�." << endl;

}

void Application::PasteFolder()
{
	if (copy != NULL)
	{
		FolderType* temp = new FolderType(*copy);
		cur_Folder->Paste(temp);
	}
	else
		cout << "\t�����ϰų� �ڸ��⸦ �� ������ �����ϴ�." << endl;
}


///ť�� ������ �ִ´�
void Application::FolderPushQue(FolderType* temp)
{
	fol.AddQ(temp);
}
///ť�� ������ �ִ´�
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
///������ �Ӽ��� �����ش�.
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
		cout << "\t�̸� ��ü ����" << endl;
	}
	else 
	{
		cout << "\t�̸� ��ü ����" << endl;
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
		cout << "\t�ڷΰ����� �����ϴ�.";
	}
}

void Application::GoToFront()
{
	if (back.CantGoFront())
	{
		cout << "\t������ ������ �����ϴ�." << endl;
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
	cout << "\t������� ���: ";
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
