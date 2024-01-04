#include "Calculator.h"
#include "TCalculator.h"

std::string Calculator::GetLastAction() const
{
	if (!m_history.empty())
		return m_history.back();
	return "";
}

std::string Calculator::Calculate(const std::string& expression)
{
	if (expression.find_first_of(",") == std::string::npos)
	{
		TCalculator<int> calc;
		return std::to_string(calc.Calculate(expression, m_history));
	}
	TCalculator<double> calc;
	std::string result = std::to_string(calc.Calculate(expression, m_history));
	RemoveTrailingZeros(result);
	return result;
}

void Calculator::RemoveTrailingZeros(std::string& result)
{
	size_t lastNotZero = result.find_last_not_of('0');
	size_t pointPos = result.find_first_of('.');
	if (pointPos != std::string::npos && pointPos < lastNotZero)
	{
		result.erase(lastNotZero + 1, result.size() - lastNotZero - 1);
	}
}
