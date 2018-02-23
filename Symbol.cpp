#include "Symbol.h"

using namespace std;

Symbol::Symbol(Symbol::Type type) : m_type(type) {}

string Function::getName() {
    return m_name;
}

string Function::getReturnType() {
    return m_returnType;
}

Function::Function(string name,
                   string returnType) : Symbol(Type::Function),
                                        m_name(move(name)),
                                        m_returnType(move(returnType)) {}

string Variable::getName() {
    return m_name;
}

string Variable::getType() {
    return m_type;
}

Variable::Variable(string name, string type) : Symbol(Type::Variable),
                                               m_name(move(name)),
                                               m_type(move(type)) {}
