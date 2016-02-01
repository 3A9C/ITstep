#include "Singletor.h"
#include <fstream>

using namespace std;
ofstream fout;

Singleton::Singleton()
{
	fout.open("username.txt"); //связываем объект с файлом
	fout << "Hello," << instance; // запись строки в файл
	fout.close(); // закрываем файл
}

Singleton::~Singleton()
{

}