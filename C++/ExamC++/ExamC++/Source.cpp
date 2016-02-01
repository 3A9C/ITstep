#include <iostream>
#include <list>     // подключаем заголовок списка
#include <iterator> // заголовок итераторов
#include <ctime>
#include <cstdlib>
#include "Ticket.h"


int main()
{
	//Создание белета
	std::list<int> ticket;
	srand(time(NULL));


	//Наполняем случайными числами
	for (int i = 0; i < 30; i++) {
		ticket.push_back(rand() % 90 + 1); // добавляем в список новые элементы
	}

	ticket.unique();   // удалили дубликаты элементов списка
	std::cout << "\nNumbers in tickets \n";
	std::copy(ticket.begin(), ticket.end(), std::ostream_iterator<int>(std::cout, " "));


	//Проверка сколько цифр в билете
		while (ticket.size() != 30)
		{
			ticket.push_back(rand() % 90 + 1);
		}

	std::cout << "\nsize: " << ticket.size() << '\n';

	//Конец наполнение билета

	//========================================================================================================================

	//Розыгрыш

	std::list<int> superloto;

	while (ticket.size() != 0)
	{
		superloto.push_back(rand() % 90 + 1); // добавляем в список новые элементы

		ticket.unique();   // удалили дубликаты элементов списка
		std::cout << "\nNumbers in superloto \n";

		//Проверяем совпало или нет в билете цифры 
		std::cout << "\nCheck in numbers superloto to tickets \n";

		for (std::list<int>::iterator it = superloto.begin(); it != superloto.end(); ++it)
		{
			ticket.remove(*it);
		}
		std::cout << "\nsize: " << ticket.size() << " Step : " << superloto.size() << '\n';
	}







	//Конец Розыгрыша


	//========================================================================================================================




	system("pause");
}

//Задание

//Билет "суперлото" содержит 30 случайных чисел от 1 до 90 без повторений. Сгенерировать эти числа. 
//Во время розыгрыша на каждом ходу случайным образом выбираются числа из того же диапазона без повторений. Если выбранное число совпадает, с имеющимся в билете, то оно "вычёркивается". 
//Билет выигрывает в ход, на котором в нём "вычеркнуты" все числа. Определить, на каком ходу выиграет случайно сгенерированный билет
