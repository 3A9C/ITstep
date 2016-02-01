#include "stdafx.h"
#include <iostream>
#include <locale.h>
using namespace std;
 int main()
 {
	setlocale(LC_CTYPE, "RUS");
	std::cout << "Будем, " << endl;
	std::cout << "          Изучать " << endl;
	std::cout << "                    программирование " << endl;
	system ("pause");
	return 0;
}