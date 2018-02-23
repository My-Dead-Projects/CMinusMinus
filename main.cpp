
#include <unordered_map>
#include <iostream>
#include <fstream>

#include "FileUtils.h"
#include "StringUtils.h"
#include "Symbol.h"

using namespace std;

void compile(const list<string>& tokens, ofstream& out);
void compile(const list<string>& tokens, ofstream&& out);

int main() {

    string source = file_uitls::read("main.cmm");

    auto tokens = string_utils::tokenize(source, regex(R"([\w]+|\->|[(){}\->])"));

    string_utils::print_tokens(tokens);

    compile(tokens, ofstream("out/main.c"));

    return 0;
}

void compile(const list<string>& tokens, ofstream& out)
{
    compile(tokens, move(out));
}

void compile(const list<string>& tokens, ofstream&& out)
{
    unordered_map<string, shared_ptr<Symbol>> symbolTable;

    for (auto tok = tokens.begin(); tok != tokens.end();)
    {
        if (*tok == "def")
        {
            string fname = *(++tok);
            if (*(++tok) != "(")
            {
                // compile error
                cout << "expected parameter list following function name \
                         in definition of '"
                     << fname << "'" << endl;
            }
            else
            {
                // TEMPORARY
                if (*(++tok) != ")")
                {
                    // compile error
                    cout << "missing closing ')' in function definition of '"
                         << fname << "'" << endl;
                }
                else
                {
                    if (*(++tok) != "->")
                    {
                        // compile error
                        cout << "expected '->' following '"
                             << fname << "'" << endl;
                    }
                    else
                    {
                        string rtype = *(++tok);
                        symbolTable.insert(make_pair(fname, make_shared<Function>(Function(fname, rtype))));
                        if (*(++tok) != "{")
                        {
                            // compile error
                            cout << "expected '{' following return type in function definition"
                                 << endl;
                        } else
                        {
                            // TEMPORARY
                            if (*(++tok) != "}")
                            {
                                cout << "something's wrong..."
                                     << endl;
                            }
                            else
                            {
                                // everything's good
                                ++tok; // should == tokens.end()
                            }
                        }
                    }
                }
            }
        }
    }

    Function main = (Function&)*symbolTable["main"];

    out << endl
        << main.getReturnType()
        << " "
        << main.getName()
        << "() {\n\n}" << endl;

    out.close();
}
