#include "Singletor.h"
#include <fstream>

using namespace std;
ofstream fout;

Singleton::Singleton()
{
	fout.open("username.txt"); //��������� ������ � ������
	fout << "Hello," << instance; // ������ ������ � ����
	fout.close(); // ��������� ����
}

Singleton::~Singleton()
{

}