#pragma once
#include <iostream>
#include <fstream>	
#include <string>

#include "FolderType.h"
using namespace std;


class Stack 
{
protected:
	int index;
	int snum;
	FolderType* arr[10];


public:
	Stack()
	{
		index = -1;
		snum = -1;
	}
	~Stack()
	{

	}
	void AddStack(FolderType* temp);
	void UpdateNum();
	int GetIndex();
	bool CantGoFront();
	FolderType* GoBack();
	FolderType* GoFront();
	void PopStack();
};