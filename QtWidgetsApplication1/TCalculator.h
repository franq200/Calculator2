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
		std::string convertedExpression = expression;
		std::replace_if(convertedExpression.begin(), convertedExpression.end(), [](char el) {return el == ','; }, '.');
		size_t operatorPos = convertedExpression.find_first_of(m_operators);
		bool isFirstNumNegative = operatorPos == 0;
		ValidateExpression(convertedExpression);

		T firstNumber = ParseFirstNumber(convertedExpression, operatorPos);
		if (operatorPos == std::string::npos || operatorPos == convertedExpression.size() - 1)
		{
			return SaveAndReturnResult(firstNumber, expression, history);
		}

		auto mapActionIt = m_actionMaps.find(convertedExpression[operatorPos]);
		if (mapActionIt == m_actionMaps.end())
		{
			return SaveAndReturnResult(firstNumber, expression, history);
		}

		T secondNumber = std::stoi(convertedExpression.substr(operatorPos + 1, convertedExpression.size() - (operatorPos + 1)));
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
			return static_cast<T>(std::stod(expression.substr(0, expression.size())));
		}
		return static_cast<T>(std::stod(expression.substr(0, operatorPos)));
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

