// Обьявление функция и засовуем мелкие и короткие функции
#pragma once
#include <iostream>

class Fraction {
public:
	int ntor; // numerator
	unsigned int dtor; // denominator

	Fraction operator+ (); // делаем положительное число
	Fraction operator- (); // делаем отрицательное число
	Fraction operator+= (const Fraction& n); // слаживаем числа
	Fraction operator-= (const Fraction& n); // отнимаем число
	
	//Сравнение
	bool operator< (const Fraction& n) const;
	bool operator>(const Fraction& n) const{
		return n < (*this);
	}
	bool  operator>= (const Fraction& n) const{
		return !((*this) < n);
	}
	bool  operator<= (const Fraction& n) const{
		return !(n < (*this));
	}
	void operator== (const Fraction& n) const;
	void operator!= (const Fraction& n) const;
	//Сравнение

	Fraction& Fraction::operator*=(const Fraction& n);
	Fraction Fraction::operator*(const Fraction& n) const;

	Fraction& Fraction::operator/=(const Fraction& n);
	Fraction Fraction::operator/(const Fraction& n) const;

	void print() const;

	Fraction();
	Fraction(int n, unsigned int d){
		ntor = n;
		dtor = d;
	};
	
};


std::ostream& operator<<(std::ostream &s, const Fraction &n);
