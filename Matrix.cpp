#include "Matrix.h"

Matrix::Matrix()
{
	MakeIdentity();
}


Matrix::~Matrix()
{
}

void Matrix::MakeIdentity() {
	//i represents index of row, j represents index of column...
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i == j) {
				mArr[j][i] = 1;
			}
		}
	}
}

//TODO: NOT WORKING RIGHT... Get this working!!!
void Matrix::Transpose() {
	//i represents index of row, j represents index of column...
	for (int i = 0; i < 4; ++i) {
		for (int j = i; j < 4; ++j) {
			mArr[i][j] = mArr[j][i];
		}
	}
}

Matrix Matrix::Transposed() {
	Matrix transposed;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			transposed.mArr[i][j] = mArr[j][i];
		}
	}

	return transposed;
}
