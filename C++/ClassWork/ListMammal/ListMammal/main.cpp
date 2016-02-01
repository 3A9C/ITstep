#include "CircularQueue.h"


#include <iostream>
#include <conio.h>
#include <new>



using namespace std;
int main()
{
	CircularQueue<int> a_int;

	for (int i = 0; i < 7; i++)
		a_int.PushFront(i);

	auto p = a_int.find(4);
	if (p == a_int.end()) {
		cout << "value not found!\n";
		return 0;
	}

	CircularQueue<int>::iterator x;
	//x++;

	a_int.erase(p);

	for (auto q = a_int.begin(); q != a_int.end(); ++q) {
		cout << *q;
	}

	// 0 1 2 3 5 6
	system("pause");

	return 0;

}