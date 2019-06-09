#include "FileType.h"
#include "SortedLinkedList.h"

void FileType::GenCreateTime()
{
	time_t tt;
	struct tm * ti;
	time(&tt);
	ti = localtime(&tt);
	stringstream ss;
	ss << setw(4) << ti->tm_year + 1900 << setfill('0') << setw(2) << ti->tm_mon + 1 << setfill('0') << setw(2) << ti->tm_mday << setfill('0') << ti->tm_hour << setfill('0') << setw(2) << ti->tm_min << setfill('0') << setw(2) << ti->tm_sec << "\0";
	date = ss.str();
}

// Set file name from keyboard.
void FileType::SetNameFromKB()
{
	string a;
	cout << "\tName : ";
	cin >> a;
	ofstream infile;
	infile.open(a + ".txt");
	SetName(a + ".txt");
	infile.close();
}

// Set file name from keyboard.
void FileType::SetFileNameFromKB()
{
	string a;
	cout << "\tName : ";
	cin >> a;
	SetName(a);
}

// Set file Data from keyboard.
void FileType::SetDataFromKB()
{
	cout << "\tData : ";
	cin >> data;
}

// Compare two FileTypes.
void FileType::Open()
{
	string a="";
	ofstream output;
	output.open(this->mName);
	while (1)
	{
		cout << "\t입력할 내용: ";
		cin >> a;
		if (a == "Exit")
		{
			break;
		}
		output << a;
		output << "\n";
		cout << "\t종료할려면: \"Exit\"\n";
	}
	output.close();
}

int FileType::CompareByName(FileType data)
{
	if (this->mName > data.mName)
		return 1;
	else if (this->mName < data.mName)
		return 0;
	else
		return 2;
}