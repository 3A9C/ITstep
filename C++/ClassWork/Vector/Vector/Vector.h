#pragma once
#include <sstream>    
#include <initializer_list>
#include <iostream>

using namespace std;

class Vector
{
private:
	double *vector;
	int element_count, memory_size;
public:

	void PushFront(double element);
	void PushEnd(double element);
	double PopFront();
	double PopEnd();

	
	Vector(initializer_list<double> args);
	const double &operator[](size_t index)const;

	
	// ctor
	Vector();
	// dtor
	~Vector();

	friend ostream &operator<<(ostream &s, const Vector &a); 
};

ostream &operator<<(ostream &s, const Vector &a);



