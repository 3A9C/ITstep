#include "Matrix.h"
#include <vector>

const Matrix<double> Matrix<double>::zero(3, 3, 0);
const Matrix<double> Matrix<double>::unit (3, std::vector<double>(3, 1));