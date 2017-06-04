#include "matrix.h"

#include <fstream>

Matrix::Matrix():
        matrix{     /*Default rules matrix*/
        0, 4, 4, 4, /*0 defectors*/
        1, 5, 2, 2, /*1 defector*/
        2, 3, 3, 0, /*2 defectors*/
        3, 1, 1, 1  /*3 defectors*/
} {}

Matrix::~Matrix() {}

bool Matrix::LoadFromFile(const std::string& fileName) {
	std::ifstream source;

	source.exceptions(
		std::ifstream::failbit |
		std::ifstream::badbit);

	try {
		source.open(fileName, std::ifstream::in);

                int temp[size] = { 0 };

                for (int i = 0; i < size; ++i)
                    source >> temp[i];

                for (int i = 0; i < size; ++i) {
                        matrix[i] = temp[i];
                }

                return true;
	}
	catch (std::ifstream::failure) {
		return false;
	}
}

Matrix::stepScore Matrix::GetScore(Strategy::Result& res) const{
	stepScore temp = { 0, 0, 0 };
	int rats = 0;
	if (res.a == Strategy::defect)
		++rats;
	if (res.b == Strategy::defect)
		++rats;
	if (res.c == Strategy::defect)
		++rats;

	int i = 0;
	while (matrix[i] != rats) {
		i += 4;
	}

	int first = 1 + i;
	int last = 3 + i;

	if (res.a == Strategy::defect)
		temp.a = matrix[first++];
	else temp.a = matrix[last--];

	if (res.b == Strategy::defect)
		temp.b = matrix[first++];
	else temp.b = matrix[last--];

	if (res.c == Strategy::defect)
		temp.c = matrix[first++];
	else temp.c = matrix[last--];

	return temp;
}
