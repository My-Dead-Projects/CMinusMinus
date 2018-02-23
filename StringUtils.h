#pragma once

#include <string>
#include <regex>
#include <list>

namespace string_utils
{
    std::list<std::string> tokenize(const std::string& str, std::regex rexp);
    void print_tokens(std::list<std::string>::const_iterator begin,
                      std::list<std::string>::const_iterator end);
    void print_tokens(const std::list<std::string>& tokens);
}
