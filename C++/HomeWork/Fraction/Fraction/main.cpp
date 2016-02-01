#include "Fraction.h"
#include <iostream>

void main()
{
	Fraction a(3, 3);
	Fraction b(-7, -4);

	a = +b;
	a.print();
	a = -b;
	a.print();

	a != b;
	
	//a.print();

	getc(stdin);

}