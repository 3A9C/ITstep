#include <iostream>
#include <list>     // ���������� ��������� ������
#include <iterator> // ��������� ����������
#include <ctime>
#include <cstdlib>
#include "Ticket.h"


int main()
{
	//�������� ������
	std::list<int> ticket;
	srand(time(NULL));


	//��������� ���������� �������
	for (int i = 0; i < 30; i++) {
		ticket.push_back(rand() % 90 + 1); // ��������� � ������ ����� ��������
	}

	ticket.unique();   // ������� ��������� ��������� ������
	std::cout << "\nNumbers in tickets \n";
	std::copy(ticket.begin(), ticket.end(), std::ostream_iterator<int>(std::cout, " "));


	//�������� ������� ���� � ������
		while (ticket.size() != 30)
		{
			ticket.push_back(rand() % 90 + 1);
		}

	std::cout << "\nsize: " << ticket.size() << '\n';

	//����� ���������� ������

	//========================================================================================================================

	//��������

	std::list<int> superloto;

	while (ticket.size() != 0)
	{
		superloto.push_back(rand() % 90 + 1); // ��������� � ������ ����� ��������

		ticket.unique();   // ������� ��������� ��������� ������
		std::cout << "\nNumbers in superloto \n";

		//��������� ������� ��� ��� � ������ ����� 
		std::cout << "\nCheck in numbers superloto to tickets \n";

		for (std::list<int>::iterator it = superloto.begin(); it != superloto.end(); ++it)
		{
			ticket.remove(*it);
		}
		std::cout << "\nsize: " << ticket.size() << " Step : " << superloto.size() << '\n';
	}







	//����� ���������


	//========================================================================================================================




	system("pause");
}

//�������

//����� "���������" �������� 30 ��������� ����� �� 1 �� 90 ��� ����������. ������������� ��� �����. 
//�� ����� ��������� �� ������ ���� ��������� ������� ���������� ����� �� ���� �� ��������� ��� ����������. ���� ��������� ����� ���������, � ��������� � ������, �� ��� "�������������". 
//����� ���������� � ���, �� ������� � �� "����������" ��� �����. ����������, �� ����� ���� �������� �������� ��������������� �����
