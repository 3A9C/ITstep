#include <iostream>
<<<<<<< HEAD
=======
#include <conio.h>
>>>>>>> 19e0f44b808e8168582b9e16ef361261c65925e7
#include "Test.h"
#include <string>
#include "Trait.h"



using namespace std;

int main()
{
	Trait::Init();
	Profession::Init();
    string ratee = "Irina";
    Test test(ratee);
	while (!test.IsFinished())
		test.AskQuestion();
    test.ShowResult();
<<<<<<< HEAD
	system("pause");
=======
	_getch();
>>>>>>> 19e0f44b808e8168582b9e16ef361261c65925e7
	return 0;
}