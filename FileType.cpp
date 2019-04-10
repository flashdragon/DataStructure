#include "FileType.h"
#include "FolderLinkedList.h"

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

// Set file Data from keyboard.
void FileType::SetDataFromKB()
{
	cout << "\tData : ";
	cin >> data;
}


// Set file record from keyboard.

void FileType::SetRecordFromKB()
{
	SetNameFromKB();
}




// Compare two FileTypes.
void FileType::Open()
{
	string a;
	ofstream output;
	output.open(this->mName);
	cout << "입력할 내용: ";
	cin >> a;
	output << a;
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