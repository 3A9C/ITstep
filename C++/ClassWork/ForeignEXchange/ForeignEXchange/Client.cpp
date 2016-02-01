#include "Client.h"
#include <math.h>

void Client::Act()
{
	double amount, power;
	amount = pow(10, rand() * 9.0 / RAND_MAX);

	if ((stock.getSellRate() / stock.getBuyRate()) < 1.0001)
		power = 6.0;
	else
		power = 5.0;
	amount = pow(10, rand() * power / RAND_MAX);
	if (rand() % 2)
	{
		stock.buy(amount);
	}
	else
	{
		stock.sell(amount);
	}

}