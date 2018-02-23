#pragma once

#include <string>
#include <utility>

class Symbol {
public:
    enum Type
    {
        None,
        Function,
        Variable
    };
    virtual ~Symbol() = default;
    explicit Symbol(Type type = Type::None);
protected:
    Type m_type;
};


class Function : public Symbol
{
private:
    std::string m_name;
    std::string m_returnType;

public:
    std::string getName();
    std::string getReturnType();
    explicit Function(std::string name, std::string returnType);
};


class Variable : public Symbol
{
private:
    std::string m_name;
    std::string m_type;

public:
    std::string getName();
    std::string getType();
    explicit Variable(std::string name, std::string type);
};
