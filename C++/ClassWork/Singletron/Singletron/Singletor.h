#pragma once
#include <string>

using namespace std;
class Singleton
{

private:
	Singleton(){}
	~Singleton(){}

	static Singleton * instance;
	string username;
public:
	static Singleton& getInstance() {
		if (instance == nullptr){
			instance = new Singleton;
		}
	 return (*instance);
    }
};

