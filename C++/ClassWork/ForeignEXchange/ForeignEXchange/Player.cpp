
#include "Player.h"
#include <math.h>

void Player::Act()
{
	double rate, amount;
	if (rand() % 2)
	{
		rate = stock.getBuyRate() + ((double)rand() / RAND_MAX - 0.5) * (stock.getSellRate() - stock.getBuyRate());
		amount = pow(10, rand() * 5.0 / RAND_MAX);
		stock.makeBuyBet(rate, amount);
	}
	else
	{
		rate = stock.getSellRate() + ((double)rand() / RAND_MAX - 0.5) * (stock.getSellRate() - stock.getBuyRate());//(stock.getSellRate() - stock.getBuyRate());
		amount = pow(10, rand() * 5.0 / RAND_MAX);
		stock.makeSellBet(rate, amount);
	}

}