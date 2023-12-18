#pragma once
#include <string>
#include <map>
#include <functional>
#include <vector>
#include <cmath>
#include <algorithm>


using Operator = char;

template<typename T>
class Calculator
{
public:
	Calculator()// : m_actionMaps({ {'+', &Calculator<T>::add}, {'-', &Calculator<T>::sub}, {'/', &Calculator<T>::divide}, {'*', &Calculator<T>::mul}, {'^', &Calculator<T>::pow} })
    {
        m_actionMaps.emplace('/', &Calculator<T>::divide);
    }
    T Calculate(const std::string& expression)
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
		if (mapActionIt == m_actionMaps.end())
		{
			return SaveAndReturnResult(firstNumber, expression);
		}

		int secondNumber = std::stoi(expression.substr(operatorPos + 1, expression.size() - (operatorPos + 1)));
		std::function<T(T, T)> action = mapActionIt->second;
		return SaveAndReturnResult(action(firstNumber, secondNumber), expression);
	}
    std::string GetLastAction() const
	{
		if (!m_history.empty())
			return m_history.back();
		return "";
	}
private:
	T SaveAndReturnResult(T result, const std::string& expression)
	{
		m_history.push_back(expression + "=" + std::to_string(result));
		return result;;
	}
	void ValidateExpression(const std::string& expression) const
	{
		if (!std::isdigit(expression[0]) && expression[0] != '-')
		{
			throw std::exception("blad");
		}
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

	T add(T lhs, T rhs)
	{
		return lhs + rhs;
	}

	T sub(T lhs, T rhs)
	{
		return lhs - rhs;
	}

	T mul(T lhs, T rhs)
	{
		return lhs * rhs;
	}

	T divide(T lhs, T rhs)
	{
		if (rhs == 0)
		{
			throw std::exception("Nie dziel przez 0");
		}

		return lhs / rhs;
	}

	T pow(T lhs, T rhs)
	{
		return static_cast<T>(std::pow(lhs, rhs));
	}

    std::vector<std::string> m_history;
    std::string m_operators = "+-/*^";
    std::map<Operator, std::function<::std::type_identity_t<T>(::std::type_identity_t<T>,::std::type_identity_t<T>)>> m_actionMaps;
};