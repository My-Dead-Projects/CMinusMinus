#include <iostream>
#include <string>
#include <iostream>
using namespace std;

#include "FileUtils.h"
#include "StringUtils.h"

int main() {

    string source = file_uitls::read("main.cmm");

    auto tokens = string_utils::tokenize(source, regex(R"([\w]+|\->|[(){}\->])"));

    string_utils::print_tokens(tokens);

    return 0;
}
