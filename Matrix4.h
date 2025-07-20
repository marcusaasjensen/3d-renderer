#pragma once
#include "Vector3.h"

struct Matrix4 {
	float m[4][4];

	Matrix4();
	Matrix4(float m[4][4]);
	Matrix4(const Matrix4& m);
	Matrix4 operator+(const Matrix4& other) const;
	Matrix4 operator-(const Matrix4& other) const;
	Matrix4 operator*(const Matrix4& other) const;
	float* operator[](int row);
	const float* operator[](int row) const;
	Matrix4 inverse();
	Matrix4 transpose();

};