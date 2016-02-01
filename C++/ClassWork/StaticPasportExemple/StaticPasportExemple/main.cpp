#include "Matrix.h"
#include <vector>
#include <iostream>

int
main() {

	std::vector< std::vector <double> > q
	{ { 0, 0, 0 }, { 1, 0, 0 }, { 1, 1, 0 }, { 0, 1, 0 } };

	auto r = Matrix<double>::rotateY(0.5);


	for (auto v : q) {

		auto rotatedVector = r*v;

		for (auto coord : rotatedVector) {
			std::cout << " " << coord;

		}
		std::cout << "\n ---- \n";
	}

	Matrix<double> a(3, 3);

	system("pause");
}