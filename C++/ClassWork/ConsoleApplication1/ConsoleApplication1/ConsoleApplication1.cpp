// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>



int main()
{
	float x,y,z,A;
	printf("vvedite x,y,z");
	scanf_s("%f,&x, %f,&y, %f,&z");
	A = x*y*z;
	printf("%f", cbrtf(A));
	_getch();

	return 0;
}

