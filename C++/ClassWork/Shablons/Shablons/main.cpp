#include <cmath>
#include <string>
#include <iostream>
#include <conio.h>
#include "Header.h"

using namespace std;

class Turtles
{

};


template < class T>
T f(T x, T y){
	return x + y;
}

int main() {
	Vector<int> arr(4);
	arr[0] = 1;

	cout << arr[0] << endl;

	Vector<Turtles> zoo(2);                                                                                                                                                                                                                                                                                                                                                                      
	Vector<Vector<int>> qq(3, Vector<int>(3,0));




	_getch();
	return 0;
}