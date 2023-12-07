#pragma once
#include <string>
#include <map>
#include <functional>
#include <vector>

using Operator = char;
using Action = std::function<int(int,int)>;

class Calculator
{
public:
    Calculator();
    int Calculate(const std::string& expression);
    std::string GetLastAction() const;
private:
    int SaveAndReturnResult(int result, const std::string& expression);
    void ValidateExpression(const std::string& expression) const;
    int ParseFirstNumber(const std::string& expression, size_t& operatorPos);
    std::vector<std::string> m_history;
    std::string m_operators = "+-/*^";
    std::map<Operator, Action> m_actionMaps;
};
