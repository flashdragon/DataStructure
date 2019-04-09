#include "FolderType.h"
#include "FolderLinkedList.h"
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

//�����߰�
int FolderType::AddFolder()
{
	//���� ������ ������ �迭�� �Ҵ�
	if (subFileNum == 0)
	{
		down = new FolderLinkedList<FolderType>;
	}
	/*getFolderTypeFromkeyboard*/
	FolderType temp;
	setFolderTypeProperty(temp);

	//���� �߰��� �����ϸ� �������� ������ 1�����ϰ� 1�� ����, �ƴϸ� 0�� ����
	if (down->Add(temp))
	{
		subFileNum++;
		return 1;
	}
	return 0;
}

//���� ����
int FolderType::DeleteFolder()
{
	int pre = down->GetLength();
	FolderType temp;
	temp.SetNameFromKB();
	down->Delete(temp);
	if (pre > down->GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout << "<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;
	return 0;
}

//��� ���� ���
void FolderType::DisplayProperty()
{
	if (subFileNum == 0)
	{
		return;
	}
	FolderType data;
	// list�� ��� �����͸� ȭ�鿡 ���
	down->ResetList();
	while (down->GetNextItem(data)!=NULL)
	{
		cout << "\t";
		data.DisplayNameOnScreen();
	}
}

//�̸����� ������ ã�Ƽ� ����Ѵ�.
int FolderType::SearchListByMemberName(FolderType &inData)
{
	FolderType tmp;
	if (subFileNum == 0)
	{
		return 0;
	}
	down->ResetList();//iterator �ʱ�ȭ
	while (down->GetNextItem(tmp) != NULL) //����Ʈ�� ���������� �ݺ�
	{
		if (tmp.GetName().find(inData.GetName()) != -1) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{
			
			tmp.DisplayRecordOnScreen();
			result = 1;	//����(1)
		}
		tmp.SearchListByMemberName(inData);
	}
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
