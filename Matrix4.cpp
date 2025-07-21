#include "Matrix4.h"
#include <cstring>
#include <cmath>

Matrix4::Matrix4() {
	for (int i = 0; i < 16; ++i)
		m[i] = (i % 5 == 0) ? 1.0f : 0.0f;
}

Matrix4::Matrix4(const float* values) {
	std::memcpy(m, values, 16 * sizeof(float));
}

Matrix4::Matrix4(const Matrix4& other) {
	std::memcpy(m, other.m, 16 * sizeof(float));
}

float& Matrix4::operator()(int row, int col) {
	return m[col * 4 + row];
}

const float& Matrix4::operator()(int row, int col) const {
	return m[col * 4 + row];
}

const float* Matrix4::data() const {
	return m;
}

float* Matrix4::data() {
	return m;
}

Matrix4 Matrix4::identity() {
	return Matrix4();
}

Matrix4 Matrix4::operator+(const Matrix4& other) const {
	Matrix4 result;
	for (int i = 0; i < 16; ++i)
		result.m[i] = m[i] + other.m[i];
	return result;
}

Matrix4 Matrix4::operator-(const Matrix4& other) const {
	Matrix4 result;
	for (int i = 0; i < 16; ++i)
		result.m[i] = m[i] - other.m[i];
	return result;
}

Matrix4 Matrix4::operator*(const Matrix4& other) const {
	Matrix4 result;
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			result(row, col) = 0.0f;
			for (int k = 0; k < 4; ++k) {
				result(row, col) += (*this)(row, k) * other(k, col);
			}
		}
	}
	return result;
}

Vector4 Matrix4::operator*(const Vector4& v) const {
	Vector4 result;
	result.x = m[0] * v.x + m[4] * v.y + m[8] * v.z + m[12] * v.w;
	result.y = m[1] * v.x + m[5] * v.y + m[9] * v.z + m[13] * v.w;
	result.z = m[2] * v.x + m[6] * v.y + m[10] * v.z + m[14] * v.w;
	result.w = m[3] * v.x + m[7] * v.y + m[11] * v.z + m[15] * v.w;
	return result;
}

Matrix4 Matrix4::transpose() const {
	Matrix4 result;
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			result(row, col) = (*this)(col, row);
		}
	}
	return result;
}

Matrix4 Matrix4::translateX(float delta) {
	Matrix4 result = identity();
	result(0, 3) = delta;
	return result;
}

Matrix4 Matrix4::translateY(float delta) {
	Matrix4 result = identity();
	result(1, 3) = delta;
	return result;
}

Matrix4 Matrix4::translateZ(float delta) {
	Matrix4 result = identity();
	result(2, 3) = delta;
	return result;
}

Matrix4 Matrix4::translate(float delta, const Vector3& axis)
{
	Vector3 dir = axis.normalized();
	Matrix4 result = identity();

	result(0, 3) = dir.x * delta;
	result(1, 3) = dir.y * delta;
	result(2, 3) = dir.z * delta;

	return result;
}

Matrix4 Matrix4::scaleX(float factor) {
	Matrix4 result = identity();
	result(0, 0) = factor;
	return result;
}

Matrix4 Matrix4::scaleY(float factor) {
	Matrix4 result = identity();
	result(1, 1) = factor;
	return result;
}

Matrix4 Matrix4::scaleZ(float factor) {
	Matrix4 result = identity();
	result(2, 2) = factor;
	return result;
}
