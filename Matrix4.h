#pragma once
#include "Vector3.h"

struct Matrix4 {
	float m[4][4];

	Matrix4();
	Matrix4 translate(Vector3 position);
	Matrix4 rotate(Vector3 position);
};