#include "Stock.h"
#include "Buddy.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include "Client.h"
#include "Player.h"
#include <fstream>
#include "CentralBank.h"

#include <ctime>

using namespace std;
int main()
{
	srand(time(NULL));
	Stock stock;
	vector<Buddy*> buddies{ new CentralBank(stock) };

	for (int i = 0; i < 10; ++i)
	{
		buddies.push_back(new Client(stock));
		buddies.push_back(new Player(stock));
	}

	// спекулятивнфе заявки
	stock.makeBuyBet(1.5, 1e9);
	stock.makeSellBet(1.81, 1e9);
	stock.makeBuyBet(1.99, 1e7);
	stock.makeSellBet(1.89, 1e7);
	stock.makeBuyBet(1.85, 1e5);
	stock.makeSellBet(1.22, 1e5);
	stock.makeBuyBet(1.77, 1e3);
	stock.makeSellBet(2.1, 1e3);


	ofstream fs("result.csv");
	fs.imbue(locale(""));
	fs << "time;buy rate;sell rate\n";
	for (int time = 0; time < 30000; time++)
	{
		for (auto b : buddies) // (b->begin(); b != b->end(); b++)
			b->Act();
		fs << time << ";";
		fs << stock.getBuyRate() << ";";
		fs << stock.getSellRate() << "\n";
		cout << time << ' ';
	}
	fs.close();
	cout << "end" << endl;
	_getch();
	return 0;
}