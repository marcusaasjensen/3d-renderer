#pragma once

#include <iostream>
#include "Vector4.h"
#include "Vector3.h"

struct alignas(16) Matrix4 {
	float m[16];

	Matrix4();
	Matrix4(const float* values);
	Matrix4(const Matrix4& other);

	Matrix4 operator+(const Matrix4& other) const;
	Matrix4 operator-(const Matrix4& other) const;
	Matrix4 operator*(const Matrix4& other) const;
	Vector4 operator*(const Vector4& vec) const;
	std::ostream& operator<<(std::ostream& os);

	float& operator()(int row, int col);
	const float& operator()(int row, int col) const;

	const float* data() const;
	float* data();

	static Matrix4 identity();
	Matrix4 transpose() const;

	// Transform operations
	static Matrix4 scaleX(float factor);
	static Matrix4 scaleY(float factor);
	static Matrix4 scaleZ(float factor);
	static Matrix4 perspective(float fovY, float aspect, float znear, float zfar);
	static Matrix4 scale(float factor, const Vector3& axis);
	static Matrix4 rotateX(float angle);
	static Matrix4 rotateY(float angle);
	static Matrix4 rotateZ(float angle);
	static Matrix4 rotate(float angle, const Vector3& axis);
	static Matrix4 translateX(float delta);
	static Matrix4 translateY(float delta);
	static Matrix4 translateZ(float delta);
	static Matrix4 translate(float delta, const Vector3& axis);
};
