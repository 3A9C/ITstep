#include "String.h"
#include <iostream>

int main() {

	String a("A"), b("B"), c("C"), d;
	
	d = a + b + c;

	d.PrintStr();

	String && obj{};//��������� ������

	system("pause");
}