#pragma once
#include <vector>

using namespace std;

template <class T>
class Matrix
{
private:
	static int last;
public:
	static Matrix unity[3][3], zero[3][3];
	int num;
	Matrix() : num(last++){};
	static void setLast(int L) { 
		last - L; 
	}
};

int Matrix<class T>::last = 1;


//static заноситься в статическую область