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
	return std::to_string(calc.Calculate(expression, m_history));
}
