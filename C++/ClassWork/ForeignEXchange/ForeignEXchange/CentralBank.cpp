#include "CentralBank.h"
#include <cmath>

const int DAYS = 10;
const double MIN = 0.97;
const double MAX = 1.97;

void CentralBank::Act()
{

	course.push(sqrt(stock.getBuyRate() * stock.getSellRate()));

	if (course.size() < DAYS)
	{
		return;
	}

	double volatility = course.back() / course.front();

	if (volatility < MIN)
	{
		stock.makeBuyBet(stock.getBuyRate(), 1e6);
	}
	else if (volatility < MAX)
	{
		stock.makeSellBet(stock.getSellRate(), 1e6);
	}

	course.pop();

	
}
