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
	cout << "\t   1 : ���� ����" << endl;
	cout << "\t   2 : ���� ����" << endl;
	cout << "\t   3 : ���� ����" << endl;
	cout << "\t   4 : �˻�" << endl;
	cout << "\t   5 : �ֱ� ��� ����" << endl;
	cout << "\t   6 : ���� ������ �Ӽ�" << endl;
	cout << "\t   7 : ���� ������ �̵�" << endl;
	cout << "\t   0 : ����" << endl; 

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
	cout << "\t�ֻ��� �����Դϴ�" << endl;
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