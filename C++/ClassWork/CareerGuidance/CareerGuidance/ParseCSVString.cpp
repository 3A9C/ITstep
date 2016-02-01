#include "ParseCSVString.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

<<<<<<< HEAD
vector<string> ParseCSVString(const string& line) {
=======
vector<string> ParseCSVString(const string& line, char separator) {
>>>>>>> 19e0f44b808e8168582b9e16ef361261c65925e7
	vector<string> return_vector;

	size_t left_border = 0, right_border = 0;

	while (right_border < line.size()) {
<<<<<<< HEAD
		right_border = line.find(';', left_border);
=======
		right_border = line.find(separator, left_border);
>>>>>>> 19e0f44b808e8168582b9e16ef361261c65925e7
		string temp = line.substr(left_border, right_border - left_border);
		return_vector.push_back(temp);
		left_border = right_border + 1;
	}

	return return_vector;
}