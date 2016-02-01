#include <iostream>
#include <new>
#include "iteratorsortvector.h"



using namespace std;
int main()
{
	Vector<int> a_int;

	for (int i = 0; i < 7; i++)
	{
		a_int.PushFront(i + 1 + rand() % 20);
	}

	auto p = a_int.find(5);
	if (p == a_int.end()) 
	{
		cout << "value not found!\n";
		sort<Vector<int>::iterator>(a_int.begin(), a_int.end());

	}
	else
	{
		a_int.erase(p);
	}


	for (Vector<int>::iterator q = a_int.begin(); q != a_int.end(); ++q) {
		cout << *q << endl;
	}

	// 0 1 2 3 5 6

	system("pause");

	return 0;

}