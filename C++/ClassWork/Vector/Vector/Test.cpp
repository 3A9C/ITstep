#include "Vector.h"
#include <conio.h>



int main()
{
	Vector a{ 2, 3, 4 };
	std::cout << a;
	std::cout << a[2] << a[1] << a[0] << std::endl;
	_getch();
	return 0;
}

