// ���������� ������� � �������� ������ � �������� �������
#pragma once
#include <iostream>

class Fraction {
public:
	int ntor; // numerator
	unsigned int dtor; // denominator

	Fraction operator+ (); // ������ ������������� �����
	Fraction operator- (); // ������ ������������� �����
	Fraction operator+= (const Fraction& n); // ��������� �����
	Fraction operator-= (const Fraction& n); // �������� �����
	
	//���������
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
	//���������

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
