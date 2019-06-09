#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


template<class T>
class Queue
{
public:
	void AddQ(T* temp);
	void PrintQ();


private:
	T* arr[5];
	int num=0;
};


template<class T>
void Queue<T>::AddQ(T* temp)
{
	for (int i = 0; i < num; i++)
	{
		if (arr[i] == temp)
		{
			for (int j = i + 1; j < num; j++)
			{
				arr[j - 1] = arr[j];
			}
			arr[num - 1] = temp;
			return;
		}
	}
	if (num == 5)
	{
		for (int i = 0; i < 4; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[4] = temp;
	}
	else
	{
		arr[num] = temp;
		num++;
	}
	return;
}

template<class T>
void Queue<T>::PrintQ()
{
	for (int i = num; i > 0; i--)
	{
		cout << "\tName: " << arr[i-1]->GetName() << endl;
	}
}

