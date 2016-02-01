#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <iterator>


using namespace std;

list <int >mylist{ 5, 3, 1, 7, 9 };

template < class iter >
void BubbleSort(iter &from, iter &to);

void main()
{
	BubbleSort(mylist.begin(),mylist.end());
	system("pause");
}


template < class iter >
void BubbleSort(iter &from, iter &to)
{
	int check = 1;
	for (auto it = from; it != to; it++)
	{
		if (it + 1 != to && it > it + 1)
		{
			check = it;
			it = it + 1;
			it + 1 = check;
		}
	}
}
