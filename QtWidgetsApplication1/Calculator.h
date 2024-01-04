#pragma once
#include "string"
#include "vector"

class Calculator
{
public:
	std::string GetLastAction() const;
	std::string Calculate(const std::string& expression);
	void RemoveTrailingZeros(std::string& result);
private:

    std::vector<std::string> m_history;
	std::string m_operators = "+-/*^";
};
