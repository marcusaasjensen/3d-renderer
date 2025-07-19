#include "Matrix4.h"

Matrix4::Matrix4() {
	for (int i{ 0 }; i < 4; ++i) {
		for (int j{ 0 }; i < 4; ++j) {
			m[i][j] = i == j ? 1.0f : 0.0f;
		}
	}
}
