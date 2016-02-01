#include "Header.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
int main()
{
	tree<double>a;
	a["mama"] = 343.0;
	a["pabaama"] = 1.00;

	cout << a["mama"] << a["pabaama"] << "\n";
	_getch();


	return 0;
}