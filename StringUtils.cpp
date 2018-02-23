#include "StringUtils.h"

#include <iostream>
using namespace std;

list<string> string_utils::tokenize(const string& str, regex rexp)
{
    list<string> tokens;
    sregex_iterator it(str.begin(), str.end(), rexp);
    sregex_iterator end;
    for (; it != end; ++it)
    {
        if (it->length() > 0)
            tokens.push_back(it->str());
    }
    return tokens;
}

void string_utils::print_tokens(list<string>::const_iterator begin,
                                list<string>::const_iterator end)
{
    cout << "[";
    auto it = begin;
    while (true)
    {
        cout << *it;
        if (++it != end)
        {
            cout << ", ";
        }
        else
        {
            cout << "]" << endl;
            break;
        }
    }
}

void string_utils::print_tokens(const list<string>& tokens)
{
    print_tokens(tokens.begin(), tokens.end());
}
