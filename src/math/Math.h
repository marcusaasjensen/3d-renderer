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

    inline Vector3 barycentricCoordinates(const Vector3& p, const Vector3& a, const Vector3& b, const Vector3& c) {
        Vector3 v0 = b - a;
        Vector3 v1 = c - a;
        Vector3 v2 = p - a;

        float d00 = v0.dot(v0);
        float d01 = v0.dot(v1);
        float d11 = v1.dot(v1);
        float d20 = v2.dot(v0);
        float d21 = v2.dot(v1);

        float denom = d00 * d11 - d01 * d01;
        if (denom == 0.0f) {
            return Vector3(-1, -1, -1);
        }

        float beta = (d11 * d20 - d01 * d21) / denom;
        float gamma = (d00 * d21 - d01 * d20) / denom;
        float alpha = 1.0f - beta - gamma;

        return Vector3(alpha, beta, gamma);
    }


}
