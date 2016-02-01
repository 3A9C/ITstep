#include "Matrix.h"
#include <iostream>
#include <iomanip>

Matrix::Matrix(int m, int n)
{
	nstr = m;
	nstl = n;
	a = new int *[nstr];
	for (int j = 0; j<nstr; j++)
	{
		a[j] = new int[nstl];
		for (int i = 0; i<nstl; i++)
			a[j][i] = 0;
	}
}
Matrix::Matrix(int m, int n, int *b)
{
	nstr = m;
	nstl = n;
	int k = 0;
	a = new int *[nstr];
	for (int j = 0; j<nstr; j++)
	{
		a[j] = new int[nstl];
		for (int i = 0; i<nstl; i++)
		{
			a[j][i] = b[k];
			k++;
		}
	}
}
Matrix::~Matrix()
{
	for (int i = 0; i<nstr; i++)
		delete[] a[i];
	delete[] a;
}
Matrix::Matrix(const Matrix& T)
{
	nstr = T.nstr;
	nstl = T.nstl;
	for (int i = 0; i<T.nstr; i++)
	for (int j = 0; j<T.nstl; j++)
		a[i][j] = T.a[i][j];
}
Matrix & Matrix::operator = (const Matrix & T)
{
	if (this == &T)
		return *this;
	else
	{
		delete a;
		nstr = T.nstr;
		nstl = T.nstl;
		a = new int *[nstr];
		for (int j = 0; j<nstr; j++)
		{
			a[j] = new int[nstl];
			for (int i = 0; i<nstl; i++)
				a[j][i] = T.a[i][j];
		}



		return *this;
	}
}
void Matrix::Print()
{
	for (int i = 0; i<nstr; i++)
	{
		for (int j = 0; j<nstl; j++)
			std::cout << std::setw(10) << a[i][j];
		std::cout << std::endl;
	}
}