#include "Matrix4.h"

Matrix4::Matrix4() {
	for (int i{ 0 }; i < 4; ++i) {
		for (int j{ 0 }; j < 4; ++j) {
			m[i][j] = (i == j) ? 1.0f : 0.0f;
		}
	}
}

Matrix4::Matrix4(float m[4][4]) {
	for (int i{ 0 }; i < 4; ++i) {
		for (int j{ 0 }; j < 4; ++j) {
			this->m[i][j] = m[i][j];
		}
	}
}

Matrix4::Matrix4(const Matrix4& m) {
	for (int i{ 0 }; i < 4; ++i) {
		for (int j{ 0 }; j < 4; ++j) {
			this->m[i][j] = m.m[i][j];
		}
	}
}

float* Matrix4::operator[](int row) {
	return m[row];
}

const float* Matrix4::operator[](int row) const {
	return m[row];
}

Matrix4 Matrix4::operator+(const Matrix4& other) const {
	float matrix[4][4];

	for (int i{ 0 }; i < 4; ++i) {
		for (int j{ 0 }; j < 4; ++j) {
			matrix[i][j] = m[i][j] + other[i][j];
		}
	}

	return Matrix4(matrix);
}

Matrix4 Matrix4::operator-(const Matrix4& other) const {
	float matrix[4][4];

	for (int i{ 0 }; i < 4; ++i) {
		for (int j{ 0 }; j < 4; ++j) {
			matrix[i][j] = m[i][j] - other[i][j];
		}
	}

	return Matrix4(matrix);
}

Matrix4 Matrix4::operator*(const Matrix4& other) const
{
	float matrix[4][4];

	for (int i{ 0 }; i < 4; ++i) {
		for (int j{ 0 }; j < 4; ++j) {
			matrix[i][j] = 0.0f;
			for (int k{ 0 }; k < 4; ++k) {
				matrix[i][j] += m[i][k] * other[k][j];
			}
		}
	}

	return Matrix4(matrix);
}
