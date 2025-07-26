#include "Matrix4.h"
#include <cstring>
#include <cmath>
#include <ostream>

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

Matrix4 Matrix4::translate(float dx, float dy, float dz)
{
	Matrix4 result = identity();

	result(0, 3) = dx;
	result(1, 3) = dy;
	result(2, 3) = dz;

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


Matrix4 Matrix4::scale(float factor, const Vector3& axis)
{
	Matrix4 result = identity();
	result(0, 0) = factor;
	result(1, 1) = factor;
	result(2, 2) = factor;
	return Matrix4();
}

Matrix4 Matrix4::rotateX(float angle) {
	float c = std::cos(angle);
	float s = std::sin(angle);

	Matrix4 result = identity();
	result(1,1) = c;
	result(1,2) = -s;
	result(2,1) = s;
	result(2,2) = c;

	return result;
}

Matrix4 Matrix4::rotateY(float angle) {
	float c = std::cos(angle);
	float s = std::sin(angle);

	Matrix4 result = identity();
	result(0, 0) = c;
	result(0, 2) = s;
	result(2, 0) = -s;
	result(2, 2) = c;

	return result;
}

Matrix4 Matrix4::rotateZ(float angle) {
	float c = std::cos(angle);
	float s = std::sin(angle);

	Matrix4 result = identity();
	result(0, 0) = c;
	result(0, 1) = -s;
	result(1, 0) = s;
	result(1, 1) = c;

	return result;
}


Matrix4 Matrix4::rotate(float angle, const Vector3& axis) {
	Vector3 n = axis.normalized();
	float x = n.x, y = n.y, z = n.z;
	float c = std::cos(angle);
	float s = std::sin(angle);
	float t = 1.0f - c;

	Matrix4 result = identity();

	result(0, 0) = t * x * x + c;
	result(0, 1) = t * x * y - s * z;
	result(0, 2) = t * x * z + s * y;

	result(1, 0) = t * x * y + s * z;
	result(1, 1) = t * y * y + c;
	result(1, 2) = t * y * z - s * x;

	result(2, 0) = t * x * z - s * y;
	result(2, 1) = t * y * z + s * x;
	result(2, 2) = t * z * z + c;

	result(0, 3) = result(1, 3) = result(2, 3) = 0.0f;
	result(3, 0) = result(3, 1) = result(3, 2) = 0.0f;
	result(3, 3) = 1.0f;

	return result;
}

Matrix4 Matrix4::perspective(float fovY, float aspect, float znear, float zfar) {
	Matrix4 result;

	float tanHalfFovY = std::tan(fovY / 2.0f);
	float zRange = znear - zfar;

	result(0, 0) = 1.0f / (aspect * tanHalfFovY);
	result(1, 1) = 1.0f / tanHalfFovY;
	result(2, 2) = (zfar + znear) / zRange;
	result(2, 3) = (2.0f * zfar * znear) / zRange;
	result(3, 2) = -1.0f;
	result(3, 3) = 0.0f;

	return result;
}

Matrix4 Matrix4::orthographic(float left, float right, float bottom, float top, float znear, float zfar) {
	Matrix4 result;

	float rl = right - left;
	float tb = top - bottom;
	float fn = zfar - znear;

	result(0, 0) = 2.0f / rl;
	result(1, 1) = 2.0f / tb;
	result(2, 2) = -2.0f / fn;

	result(0, 3) = -(right + left) / rl;
	result(1, 3) = -(top + bottom) / tb;
	result(2, 3) = -(zfar + znear) / fn;

	result(3, 3) = 1.0f;

	return result;
}


std::ostream& Matrix4::operator<<(std::ostream& os) {
	for (int row = 0; row < 4; ++row) {
		os << "| ";
		for (int col = 0; col < 4; ++col) {
			os << (*this)(row, col) << " ";
		}
		os << "|\n";
	}
	return os;
}
