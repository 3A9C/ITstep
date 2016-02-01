#include "Fraction.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstdbool>

using namespace std;

Fraction Fraction::operator+ (){ // Делает число положительным
	Fraction res(*this);
	if (res.ntor < 0)
	{
		res.ntor *= (-1);
		return res;
	}
	return res;
}

Fraction Fraction::operator- (){ // Делает число отрицательнцым
	Fraction res(*this);
	if (res.ntor > 0)
	{
		res.ntor *= (-1);
		return res;
	}
	return res;
}

Fraction Fraction::operator+= (const Fraction& n){ // Слаживает числа
	int a, b;
	a = ntor * n.dtor;
	b = dtor * n.ntor;
	dtor = dtor * n.dtor;
	ntor = (a) + (b);
	return *this;
}

Fraction Fraction::operator-= (const Fraction& n){ // Отнимает числа
	int a, b;
	a = ntor * n.dtor;
	b = dtor * n.ntor;
	dtor = dtor * n.dtor;
	ntor = (a) - (b);
	return *this;
}

bool Fraction::operator< (const Fraction& n) const{ // Сравнение чисел
	int a, b;
	a = ntor * n.dtor;
	b = dtor * n.ntor;
	if (a < b) return true;
	else return false;
}

void Fraction::operator== (const Fraction& n) const{ // Сравнение чисел
	int a, b;
	a = ntor * n.dtor;
	b = dtor * n.ntor;
	if (a == b)
	{
		std::cout << "true";
	}
	else
	{
		std::cout << "false";
	}
}

void Fraction::operator!= (const Fraction& n) const{ // Сравнение чисел
	int a, b;
	a = ntor * n.dtor;
	b = dtor * n.ntor;
	if (a != b)
	{
		std::cout << "true";
	}
	else
	{
		std::cout << "false";
	}
}

Fraction& Fraction::operator*=(const Fraction& n) {
	ntor *= n.ntor;
	dtor *= n.dtor;
	return *this;
}

Fraction Fraction::operator*(const Fraction& n) const {
	Fraction result(*this);
	result *= n;
	return result;
}

Fraction& Fraction::operator/=(const Fraction& n) {
	ntor *= n.dtor;
	dtor *= n.ntor;
	return *this;
}

Fraction Fraction::operator/(const Fraction& n) const {
	Fraction result(*this);
	result /= n;
	return result;
}

//Вывод информации
void Fraction::print() const{
	cout << ntor << ' ' << dtor << endl;
}

ostream& operator<<(ostream &s, const Fraction &n)
{
	s << n.ntor << ' ' << n.dtor << endl;
	return s;
}