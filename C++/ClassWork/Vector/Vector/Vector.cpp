#include "Vector.h"
#include <cstdlib>

using namespace std;

void Vector::PushFront(double element)
{
	if (element_count == memory_size)
	{
		memory_size *= 2;
		vector = (double*)realloc(vector, memory_size * sizeof(double));
	}
	memmove(vector + 1, vector, element_count * sizeof(double));
	vector[0] = element;
	element_count++;
}
void Vector::PushEnd(double element)
{
	if (element_count == memory_size)
	{
		memory_size *= 2;
		vector = (double*)realloc(vector, memory_size * sizeof(double));
	}
	vector[element_count++] = element;
}
double Vector::PopFront()
{
	if (element_count * 2 == memory_size)
	{
		memory_size *= 3 / 4;
		vector = (double*)realloc(vector, memory_size * sizeof(double));
	}
	double result = vector[0];
	element_count--;
	memmove(vector, vector + 1, element_count * sizeof(double));
	return result;
}
double Vector::PopEnd()
{
	if (element_count * 2 == memory_size)
	{
		memory_size *= 3 / 4;
		vector = (double*)realloc(vector, memory_size * sizeof(double));
	}
	double result = vector[--element_count];
	vector[element_count] = 0;
	return result;
}



Vector::Vector(initializer_list<double> args)
{
	auto it = args.begin();
	element_count = args.size();
	memory_size = element_count * 2;
	vector = (double*)malloc(memory_size * sizeof(double));
	int i;
	for (it, i = 0; it != args.end(); it++, i++)
		vector[i] = *it;
}
const double &Vector::operator[](size_t index)const
{
	if (element_count <= index)
		exit(1);
	return *(vector + index);
}



// ctor
Vector::Vector()
{
	memory_size = 0;
	element_count = 0;
	vector = nullptr;
}



// dtor
Vector::~Vector()
{
	free(vector);
}


ostream &operator<<(ostream &s, const Vector &a)
{
	for (int i = 0; i < a.element_count; i++)
	{
		s << a.vector[i];
		if (i != a.element_count - 1)
			s << ", ";
	}
	return s;
}