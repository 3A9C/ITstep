#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

int main()
{
	std::ifstream data;
	data.open("names.txt", std::ifstream::in);

	char c = data.get();

	while (data.good()) {
		std::getline(std::cin, c);
	}

	data.close();

	system("pause");

}