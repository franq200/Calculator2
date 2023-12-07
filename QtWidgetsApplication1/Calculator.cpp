#include "Calculator.h"
#include <string>
#include <cmath>
#include <algorithm>

namespace actions
{
	int add(int lhs, int rhs)
	{
		return lhs + rhs;
	}

	int sub(int lhs, int rhs)
	{
		return lhs - rhs;
	}
	
	int mul(int lhs, int rhs)
	{
		return lhs * rhs;
	}

	int div(int lhs, int rhs)
	{
		if(rhs == 0)
		{
			throw std::exception("Nie dziel przez 0");
		}

		return lhs / rhs;
	}	
	int pow(int lhs, int rhs)
	{
		return static_cast<int>(std::pow(lhs, rhs));
	}
}

Calculator::Calculator() : m_actionMaps({ {'+', actions::add}, {'-', actions::sub}, {'/', actions::div}, {'*', actions::mul}, {'^', actions::pow}})
{

}

int Calculator::Calculate(const std::string& expression)
{
	if (expression.empty())
	{
		return 0;
	}
	size_t operatorPos = expression.find_first_of(m_operators);
	bool isFirstNumNegative = operatorPos == 0;
	ValidateExpression(expression);

	int firstNumber = ParseFirstNumber(expression, operatorPos);
	if (operatorPos == std::string::npos || operatorPos == expression.size() - 1)
	{
		return SaveAndReturnResult(firstNumber, expression);
	}

	auto mapActionIt = m_actionMaps.find(expression[operatorPos]);
	if(mapActionIt == m_actionMaps.end())
	{
		return SaveAndReturnResult(firstNumber, expression);
	}

	int secondNumber = std::stoi(expression.substr(operatorPos + 1, expression.size() - (operatorPos + 1)));
	std::function<int(int,int)> action = mapActionIt->second;
	return SaveAndReturnResult(action(firstNumber, secondNumber), expression);
}

int Calculator::SaveAndReturnResult(int result, const std::string& expression)
{
	m_history.push_back(expression + "=" + std::to_string(result));
	return result;
}

void Calculator::ValidateExpression(const std::string& expression) const
{
	if (!std::isdigit(expression[0]) && expression[0] != '-')
	{
		throw std::exception("blad");
	}
}

int Calculator::ParseFirstNumber(const std::string& expression, size_t& operatorPos)
{
	operatorPos = expression.find_first_of(m_operators, 1);
	if (operatorPos == std::string::npos)
	{
		return std::stoi(expression.substr(0, expression.size()));
	}
	return std::stoi(expression.substr(0, operatorPos));
}

std::string Calculator::GetLastAction() const
{
	 if(!m_history.empty())
		 return m_history.back();
	 return "";
}
