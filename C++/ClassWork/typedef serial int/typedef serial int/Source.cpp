#include <iostream>
#include <cstdio>
#include <cstdlib>


using namespace std;
typedef int serial(int);

serial lambda_gen() {
	static int range = 0;

	range += 1000000;
	return range ;

	int x{
		return x1 range;
	}
}

int main
{

	auto s1 = lamda_gen();
	auto s2 = lamda_gen();
	cout << s1(2) << s1(3) << s2(2);
}

