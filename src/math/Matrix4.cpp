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

Matrix4 Matrix4::Identity() {
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

Matrix4 Matrix4::Transpose() const {
	Matrix4 result;
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			result(row, col) = (*this)(col, row);
		}
	}
	return result;
}

Matrix4 Matrix4::Inverse() const {
	Matrix4 result;

	result(0, 0) = m[0];  result(1, 0) = m[1];  result(2, 0) = m[2];
	result(0, 1) = m[4];  result(1, 1) = m[5];  result(2, 1) = m[6];
	result(0, 2) = m[8];  result(1, 2) = m[9];  result(2, 2) = m[10];

	float tx = m[12];
	float ty = m[13];
	float tz = m[14];

	result(0, 3) = -(result(0, 0) * tx + result(0, 1) * ty + result(0, 2) * tz);
	result(1, 3) = -(result(1, 0) * tx + result(1, 1) * ty + result(1, 2) * tz);
	result(2, 3) = -(result(2, 0) * tx + result(2, 1) * ty + result(2, 2) * tz);

	result(3, 0) = 0.0f;
	result(3, 1) = 0.0f;
	result(3, 2) = 0.0f;
	result(3, 3) = 1.0f;

	return result;
}



Matrix4 Matrix4::TranslateX(float delta) {
	Matrix4 result = Identity();
	result(0, 3) = delta;
	return result;
}

Matrix4 Matrix4::TranslateY(float delta) {
	Matrix4 result = Identity();
	result(1, 3) = delta;
	return result;
}

Matrix4 Matrix4::TranslateZ(float delta) {
	Matrix4 result = Identity();
	result(2, 3) = delta;
	return result;
}

Matrix4 Matrix4::Translate(float delta, const Vector3& axis)
{
	Vector3 dir = axis.normalized();
	Matrix4 result = Identity();

	result(0, 3) = dir.x * delta;
	result(1, 3) = dir.y * delta;
	result(2, 3) = dir.z * delta;

	return result;
}

Matrix4 Matrix4::Translate(float dx, float dy, float dz)
{
	Matrix4 result = Identity();

	result(0, 3) = dx;
	result(1, 3) = dy;
	result(2, 3) = dz;

	return result;
}

Matrix4 Matrix4::Translate(Vector3 dv)
{
	Matrix4 result = Identity();

	result(0, 3) = dv.x;
	result(1, 3) = dv.y;
	result(2, 3) = dv.z;

	return result;
}

Matrix4 Matrix4::ScaleX(float factor) {
	Matrix4 result = Identity();
	result(0, 0) = factor;
	return result;
}

Matrix4 Matrix4::ScaleY(float factor) {
	Matrix4 result = Identity();
	result(1, 1) = factor;
	return result;
}

Matrix4 Matrix4::ScaleZ(float factor) {
	Matrix4 result = Identity();
	result(2, 2) = factor;
	return result;
}


Matrix4 Matrix4::Scale(float factor, const Vector3& axis)
{
	Matrix4 result = Identity();
	result(0, 0) = factor;
	result(1, 1) = factor;
	result(2, 2) = factor;
	return result;
}

Matrix4 Matrix4::Scale(const Vector3& factor)
{
	Matrix4 result = Identity();
	result(0, 0) = factor.x;
	result(1, 1) = factor.y;
	result(2, 2) = factor.z;
	return result;
}

Matrix4 Matrix4::RotateX(float angle) {
	float c = std::cos(angle);
	float s = std::sin(angle);

	Matrix4 result = Identity();
	result(1,1) = c;
	result(1,2) = -s;
	result(2,1) = s;
	result(2,2) = c;

	return result;
}

Matrix4 Matrix4::RotateY(float angle) {
	float c = std::cos(angle);
	float s = std::sin(angle);

	Matrix4 result = Identity();
	result(0, 0) = c;
	result(0, 2) = s;
	result(2, 0) = -s;
	result(2, 2) = c;

	return result;
}

Matrix4 Matrix4::RotateZ(float angle) {
	float c = std::cos(angle);
	float s = std::sin(angle);

	Matrix4 result = Identity();
	result(0, 0) = c;
	result(0, 1) = -s;
	result(1, 0) = s;
	result(1, 1) = c;

	return result;
}

Matrix4 Matrix4::RotateEuler(const Vector3& angles) {
	Matrix4 rx = Matrix4::RotateX(angles.x);
	Matrix4 ry = Matrix4::RotateY(angles.y);
	Matrix4 rz = Matrix4::RotateZ(angles.z);
	return rz * ry * rx;
}

Matrix4 Matrix4::RotateEuler(float angle, const Vector3& axis) {
	Vector3 n = axis.normalized();
	float x = n.x, y = n.y, z = n.z;
	float c = std::cos(angle);
	float s = std::sin(angle);
	float t = 1.0f - c;

	Matrix4 result = Identity();

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

Matrix4 Matrix4::Perspective(float fovY, float aspect, float znear, float zfar) {
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

Matrix4 Matrix4::Orthographic(float left, float right, float bottom, float top, float znear, float zfar) {
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

Matrix4 Matrix4::LookAt(const Vector3& eye, const Vector3& target, const Vector3& up) {
	Vector3 zaxis = (eye - target).normalized();
	Vector3 xaxis = up.Cross(zaxis).normalized(); 
	Vector3 yaxis = zaxis.Cross(xaxis);

	Matrix4 result;
	result(0, 0) = xaxis.x;
	result(1, 0) = xaxis.y;
	result(2, 0) = xaxis.z;
	result(3, 0) = -xaxis.Dot(eye);

	result(0, 1) = yaxis.x;
	result(1, 1) = yaxis.y;
	result(2, 1) = yaxis.z;
	result(3, 1) = -yaxis.Dot(eye);

	result(0, 2) = zaxis.x;
	result(1, 2) = zaxis.y;
	result(2, 2) = zaxis.z;
	result(3, 2) = -zaxis.Dot(eye);

	result(0, 3) = 0;
	result(1, 3) = 0;
	result(2, 3) = 0;
	result(3, 3) = 1;

	return result;
}
