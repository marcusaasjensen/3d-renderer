#pragma once

#include <iostream>
#include "Vector4.h"
#include "Vector3.h"

struct Matrix4 {
	float m[16];

	Matrix4();
	Matrix4(const float* values);
	Matrix4(const Matrix4& other);

	Matrix4 operator+(const Matrix4& other) const;
	Matrix4 operator-(const Matrix4& other) const;
	Matrix4 operator*(const Matrix4& other) const;
	Vector4 operator*(const Vector4& vec) const;

	float& operator()(int row, int col);
	const float& operator()(int row, int col) const;

	const float* data() const;
	float* data();

	static Matrix4 Identity();
	Matrix4 Transpose() const;
	Matrix4 Inverse() const;

	static Matrix4 ScaleX(float factor);
	static Matrix4 ScaleY(float factor);
	static Matrix4 ScaleZ(float factor);
	static Matrix4 Perspective(float fovY, float aspect, float znear, float zfar);
	static Matrix4 Orthographic(float left, float right, float bottom, float top, float znear, float zfar);
	static Matrix4 LookAt(const Vector3& eye, const Vector3& target, const Vector3& up);
	static Matrix4 Scale(float factor, const Vector3& axis);
	static Matrix4 Scale(const Vector3& factor);
	static Matrix4 RotateX(float angle);
	static Matrix4 RotateY(float angle);
	static Matrix4 RotateZ(float angle);
	static Matrix4 RotateEuler(float angle, const Vector3& axis);
	static Matrix4 RotateEuler(const Vector3& angles);
	static Matrix4 TranslateX(float delta);
	static Matrix4 TranslateY(float delta);
	static Matrix4 TranslateZ(float delta);
	static Matrix4 Translate(float delta, const Vector3& axis);
	static Matrix4 Translate(float dx, float dy, float dz);
	static Matrix4 Translate(Vector3 dv);
};

inline std::ostream& operator<<(std::ostream& os, const Matrix4& mat) {
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			os << mat(row, col) << " ";
		}
		os << "\n";
	}
	return os;
}



