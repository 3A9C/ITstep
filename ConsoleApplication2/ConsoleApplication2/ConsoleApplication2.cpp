#include "stdafx.h"
#include <iostream>
#include <locale.h>
using namespace std;
 int main()
 {
	setlocale(LC_CTYPE, "RUS");
	std::cout << "�����, " << endl;
	std::cout << "          ������� " << endl;
	std::cout << "                    ���������������� " << endl;
	system ("pause");
	return 0;
}