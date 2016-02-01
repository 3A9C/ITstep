#include <iostream>
#include <conio.h>
#include <new>
#include "DirectList.h"



using namespace std;
int main()
{
	List a_int(sizeof(int));

	for (int i = 0; i < 10; i++)
		a_int.PushFront((INT)i);

	List::iterator p = a_int.find((INT)9);

	List::iterator q;

	for (; p != a_int.end(); ++p) {
		*p = (INT)20;
		cout << ((int)*p) << endl;
	}

	int size_a = a_int.ElementCount();
	cout << "element count in a_int = " << size_a << endl;
	a_int[6]->data = (void*)20;
	for (int i = 0; i < size_a; i++)
		cout << (int)a_int[i]->data << ' ';

	_getch();
	return 0;
}