#pragma once

struct Vector3 {
	float x, y, z;

	Vector3();
	Vector3(float x, float y, float z);

	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	Vector3 operator*(const Vector3& other) const;
	Vector3 operator/(const Vector3& other) const;

	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);
	Vector3& operator*=(const Vector3& other);
	Vector3& operator/=(const Vector3& other);

	Vector3 operator*(float scalar) const;
	Vector3& operator*=(float scalar);

	bool operator==(const Vector3& other) const;

	Vector3 normalized() const;

	static Vector3 up() { return Vector3(0, 1, 0); }
	static Vector3 right() { return Vector3(1, 0, 0); }
};