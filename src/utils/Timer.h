#pragma once

#include <chrono>
#include <iostream>
#include <string>

class Timer {
    using Clock = std::chrono::high_resolution_clock;
    std::string label;
    Clock::time_point start;
public:
    explicit Timer(const std::string& lbl)
        : label(lbl), start(Clock::now()) {
    }

    ~Timer() {
        auto end = Clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << label << " took " << ms << " ms\n";
    }
};
