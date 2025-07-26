#pragma once

namespace Math {
    constexpr float PI = 3.14159265358979323846f;

    inline constexpr float toRadians(float degrees) {
        return degrees * (PI / 180.0f);
    }

    inline constexpr float toDegrees(float radians) {
        return radians * (180.0f / PI);
    }
}
