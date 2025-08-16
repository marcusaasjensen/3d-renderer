#include <fstream>
#include <iostream>
#include <string>

class LogFile {
    std::ofstream file;
    std::streambuf* oldCoutBuf;
public:
    LogFile(const std::string& filename)
        : file(filename), oldCoutBuf(std::cout.rdbuf()) {
        std::cout.rdbuf(file.rdbuf());
    }

    ~LogFile() {
        std::cout.rdbuf(oldCoutBuf);
    }
};