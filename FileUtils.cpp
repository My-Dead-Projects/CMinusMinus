#include "FileUtils.h"

#include <fstream>
#include <sstream>

std::string file_uitls::read(const std::string &filePath) {

    std::ifstream in(filePath);
    std::stringstream buffer;
    buffer << in.rdbuf();
    in.close();
    return buffer.str();
}
