#include "Stack.h"

void Stack::AddStack(FolderType* temp)
{
	if (index == 10)
	{
		for (int i = 1; i < 10; i++) 
		{
			arr[i - 1] = arr[i];
		}
		arr[9] = temp;
	}
	else
	{
		index++;
		arr[index] = temp;
		UpdateNum();
	}
}

void Stack::UpdateNum()
{
	snum = index;
}

int Stack::GetIndex()
{
	return index;
}

bool Stack::CantGoFront()
{
	if (index == snum)
		return 1;
	else
		return 0;
}

FolderType* Stack::GoBack()
{
	return arr[index];
}

FolderType* Stack::GoFront()
{
	index++;
	return arr[index];
}

void Stack::PopStack()
{
	index--;
}
