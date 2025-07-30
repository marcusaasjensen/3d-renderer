#pragma once

namespace Math {
    constexpr float PI = 3.14159265358979323846f;

    inline constexpr float toRadians(float degrees) {
        return degrees * (PI / 180.0f);
    }

    inline constexpr float toDegrees(float radians) {
        return radians * (180.0f / PI);
    }

    inline constexpr int sign(const Vector3& p1, const Vector3& p2, const Vector3& p3) {
        float result = (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
        return (result > 0) - (result < 0);
    }

}
