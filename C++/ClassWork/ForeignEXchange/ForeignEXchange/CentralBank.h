#pragma once
#include "Buddy.h"
#include <queue> 

class CentralBank : public Buddy
{
public:

	std::queue<int> course;
	CentralBank(Stock& st) : Buddy(st) {};
	virtual void Act();
};

