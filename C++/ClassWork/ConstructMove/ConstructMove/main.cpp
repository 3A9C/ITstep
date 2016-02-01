#include "String.h"
#include <iostream>

int main() {

	String a("A"), b("B"), c("C"), d;
	
	d = a + b + c;

	d.PrintStr();

	String && obj{};//временный обьект

	system("pause");
}