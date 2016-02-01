#define _CRT_SECURE_CPP_WARNINGS
#include <iostream>
#include <math.h>
#include <chrono>
#include <list>
#include <map>
#include <hash_map>

int main()
{

	using namespace std;
	using namespace std::chrono; 
	const int size = 16777216;
	//int *massive = (int*) malloc(size * sizeof(int));
	//list<int>a;
	map<int, int> mymap;

	std::cout << "Start Time"<< std::endl;
	system_clock::time_point before = system_clock::now();
	for (int i = 0; i < size; i++)
	{
		mymap[1] = rand();
	}
	system_clock::time_point after = system_clock::now();
	milliseconds ms = duration_cast<milliseconds> (after - before);
	std::cout << "ms: " << ms.count() << std::endl;
	std::cout << "End Time" << std::endl;

	system("pause");
	return 0;
}