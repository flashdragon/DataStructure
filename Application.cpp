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
		case 15:
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
	cout << "\t   10 : �ֱ� ��� ������ ����" << endl;
	cout << "\t   11 : �ڷ� ����" << endl;
	cout << "\t   12 : ������ ����" << endl;
	cout << "\t   13 : ���� ������ �Ӽ�" << endl;
	cout << "\t   14 : ���� ������ �̵�" << endl;
	cout << "\t   15 : �ش� ��η� �̵�" << endl;
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
	string a= cur_Folder->openfile();
	if (a != "")
	{
		push(a);
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
		AddStack(cur_Folder);
		cur_Folder = test;
		push(cur_Folder->GetName());
		return cur_Folder;
	}
	return NULL;
}

///���������� ����.
FolderType* Application::GoToUpFolder()
{
	if (cur_Folder->GetAddress() != "root")
	{
		AddStack(cur_Folder);
		cur_Folder = cur_Folder->getParent();
		push(cur_Folder->GetName());
		return cur_Folder;
	}
	cout << "\t�ֻ��� �����Դϴ�" << endl;
	return 0;
}
///ť�� �ִ´�
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
///ť���� ����.
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
	for (int i = 0; i < cnt; i++)
	{
		cout << "\t    " << queue[i] << endl;
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

void Application::AddStack(FolderType* temp)
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
		cout << "\t�ڷΰ����� �����ϴ�.";
	}
}

void Application::GoToFront()
{
	if (stacknum == frontnum)
	{
		cout << "\t������ ������ �����ϴ�." << endl;
	}
	else 
	{
		stacknum++;
		cur_Folder = stack[stacknum];
	}
}

void Application::GoToAddress()
{
	FolderType* temp = cur_Folder;
	adnum = 0;
	string address;
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
	AddStack(temp);
	push(cur_Folder->GetName());
}
