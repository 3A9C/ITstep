#include "ListShablon.h"

#include <iostream>

using namespace std;

int main() {
	
	List<int>a;
	/*a.pushFront(1).pushFront(2553).pushFront(54);
	a.pushBack(10).pushBack(16).popBack();
	a.printAll();
	List b = a;
	b.printAll();*/

	a.pushFront(1).pushFront(2553).pushFront(54);
	a.printAll();

	//a.pushInIndex(13, 4);

	//a.popFromIndex(0);
	//a.printAll();

	cin.get();
	return 0;
}