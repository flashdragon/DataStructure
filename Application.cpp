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
			push(OpenFolder());
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
		case 11:		// display all the records in list on screen.
			DisplayThisfolder();
			break;
		case 12:
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
	DisplaySubfile();
	
	cout << "\t   ---- Menu ---- " << endl;
	cout << "\t    1 : ���� ����" << endl;
	cout << "\t    2 : ���� ����" << endl;
	cout << "\t    3 : ���� �̸� �ٲٱ�" << endl;
	cout << "\t    4 : ���� ����" << endl;
	cout << "\t    5 : ���� ����" << endl;
	cout << "\t    6 : ���� ����" << endl;
	cout << "\t    7 : ���� �̸� �ٲٱ�" << endl;
	cout << "\t    8 : ���� ����" << endl;
	cout << "\t    9 : �˻�" << endl;
	cout << "\t   10 : �ֱ� ��� ����" << endl;
	cout << "\t   11 : ���� ������ �Ӽ�" << endl;
	cout << "\t   12 : ���� ������ �̵�" << endl;
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
	cur_Folder->AddFolder();
	return 1;
}

//�̸��� �Է¹��� item���� ����Ʈ���� ������ ã�Ƽ� ����Ѵ�.
int Application::RetriveFolderByName()
{
	FolderType item;
	item.SetNameFromKB(); //name�� �Է¹޴´�.

	if(SearchListByMemberName(item)) //0�� �ƴϸ�(ã����)
		return 1;	//����(1)�� ����
	return 0;	//����(0)�� ����
}

//�̸����� ������ ã�Ƽ� ����Ѵ�.
int Application::SearchListByMemberName( FolderType &inData )
{
	return cur_Folder->SearchListByMemberName(inData);
}

//�̸����� ������ ã�Ƽ� �����Ѵ�.
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
		cout << "\t�̸� ��ü ����" << endl;
	}
	else
	{
		cout << "\t�̸� ��ü ����" << endl;
	}
}
int Application::OpenFile()
{
	if (cur_Folder->openfile())
	{
		return 1;
	}
	cout << "\t������ ã�� ���߽��ϴ�." << endl;
	return 0;
}
///������ ����
FolderType* Application::OpenFolder()
{
	FolderType* temp = cur_Folder->Open();
	if (temp != 0)
	{
		return cur_Folder = temp;
	}
	return NULL;
}

///���������� ����.
FolderType* Application::GoToUpFolder()
{
	if (cur_Folder->GetAddress() != "root")
	{
		return cur_Folder = cur_Folder->getParent();
	}
	cout << "\t�ֻ��� �����Դϴ�" << endl;
	return 0;
}
///ť�� �ִ´�
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
///ť���� ����.
void Application::pop()
{
	cnt--;
	queue[front] = NULL;
	front++;
	front %= MAXFOLDERSIZE;
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
	}
}

void Application::DisplayCurrentFolder() 
{
	for (int i = back-1; i>=0; i--)
	{
		cout << queue[i]->GetName() << endl;
	}
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
