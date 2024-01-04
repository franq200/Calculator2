#pragma once
#include <string>
#include <map>
#include <functional>
#include <vector>
#include <cmath>
#include <algorithm>

using Operator = char;

template<typename T>
class TCalculator
{
public:
	TCalculator() : m_actionMaps({ {'+', &TCalculator<T>::add}, {'-', &TCalculator<T>::sub}, {'/', &TCalculator<T>::divide}, {'*', &TCalculator<T>::mul}, {'^', &TCalculator<T>::pow} })
	{
	}
	T Calculate(const std::string& expression, std::vector<std::string>& history)
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
			return SaveAndReturnResult(firstNumber, expression, history);
		}

		auto mapActionIt = m_actionMaps.find(expression[operatorPos]);
		if (mapActionIt == m_actionMaps.end())
		{
			return SaveAndReturnResult(firstNumber, expression, history);
		}

		int secondNumber = std::stoi(expression.substr(operatorPos + 1, expression.size() - (operatorPos + 1)));
		std::function<T(T, T)> action = mapActionIt->second;
		return SaveAndReturnResult(action(firstNumber, secondNumber), expression, history);
	}
private:
	void ValidateExpression(const std::string& expression) const
	{
		if (!std::isdigit(expression[0]) && expression[0] != '-')
		{
			throw std::exception("blad");
		}
	}
	T SaveAndReturnResult(T result, const std::string& expression, std::vector<std::string>& history)
	{
		history.push_back(expression + "=" + std::to_string(result));
		return result;
	}
	T ParseFirstNumber(const std::string& expression, size_t& operatorPos)
	{
		operatorPos = expression.find_first_of(m_operators, 1);
		if (operatorPos == std::string::npos)
		{
			return std::stoi(expression.substr(0, expression.size()));
		}
		return std::stoi(expression.substr(0, operatorPos));
	}

	static T add(T lhs, T rhs)
	{
		return lhs + rhs;
	}

	static T sub(T lhs, T rhs)
	{
		return lhs - rhs;
	}

	static T mul(T lhs, T rhs)
	{
		return lhs * rhs;
	}

	static T divide(T lhs, T rhs)
	{
		if (rhs == 0)
		{
			throw std::exception("Nie dziel przez 0");
		}

		return lhs / rhs;
	}

	static T pow(T lhs, T rhs)
	{
		return static_cast<T>(std::pow(lhs, rhs));
	}

	std::string m_operators = "*/+-^";
	std::map<Operator, std::function<T(T, T)>> m_actionMaps;
};

