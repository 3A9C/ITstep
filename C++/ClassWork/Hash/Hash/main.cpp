#include <string>
#include "UnorderedMap.h"
#include <conio.h>

class Turtle {
public:
	Turtle() {};
};

int main() {

	UnorderedMap<string, float> people;
	people["Anna"] = 1.7f;
	people["Alex"] = 2.7f;
	people["Boreau"] = 0.1f;

	people.show();

	_getch();

	return 0;
}