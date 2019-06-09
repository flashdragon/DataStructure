#include "FileType.h"
#include "SortedLinkedList.h"

FileType::FileType(FileType& data)
{
	this->mName = data.mName;
	this->m_fAddress = data.m_fAddress;
	this->date = data.date;
	this->indata = data.indata;
}

FileType& FileType::operator=(const FileType& data)
{
	this->mName = data.mName;
	this->m_fAddress = data.m_fAddress;
	this->date = data.date;
	this->indata = data.indata;
	return (*this);
}

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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	string a;
	cout << "\tName : ";
	cin >> a;
	ofstream infile;
	infile.open(a + ".txt");
	SetName(a + ".txt");
	infile.close();
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

}

// Set file name from keyboard.
void FileType::SetFileNameFromKB()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	
	cout << "\tName : ";
	cin >> mName;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

}


// Compare two FileTypes.
void FileType::Open()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	string a="";
	ofstream output;
	output.open(this->mName);
	cout << "\n\n";
	while (1)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t종료할려면: \"Exit\"\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "\t입력할 내용: ";
		cin >> a;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		if (a == "Exit")
		{
			break;
		}
		output << a;
		output << "\n";
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "\t입력할 내용: ";
		cin >> a;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		if (a == "Exit")
		{
			break;
		}
		output << a;
		output << "\n";
		system("pause");
		system("cls");
		cout << "\n\n";
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