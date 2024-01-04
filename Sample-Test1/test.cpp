#include "..\\QtWidgetsApplication1\Calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorTest, SimpleTestWithAddition) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("5+6"), "11");
}

TEST(CalculatorTest, SimpleTestWithSubstraction) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("20-17"), "3");
}

TEST(CalculatorTest, SimpleTestWithMultiplication) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("3*7"), "21");
}

TEST(CalculatorTest, SimpleTestWithDivision) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("10/2"), "5");
}

TEST(CalculatorTest, SimpleTestWithEmptyExpression) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate(""), "0");
}

TEST(CalculatorTest, SimpleTestWithoutOperator) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("10043"), "10043");
}

TEST(CalculatorTest, SimpleTestWithDivisionByZero) {
	Calculator calculator;
	EXPECT_THROW(calculator.Calculate("811/0"), std::exception);
}

TEST(CalculatorTest, SimpleTestWithTwoOperators) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("200++430"), "630");
}

TEST(CalculatorTest, SimpleTestWithTwoDifferentOperatorsShouldThrow) {
	Calculator calculator;
	EXPECT_THROW(calculator.Calculate("200+/430"), std::invalid_argument);
}

TEST(CalculatorTest, SimpleTestWithTwoDifferentOperators) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("321*-2"), "-642");
}

TEST(CalculatorTest, SimpleTestWithOnlyOneNumberAndOneOperator) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("383*"), "383");
}

TEST(CalculatorTest, SimpleTestWithNegativeNumber) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("-790"), "-790");
}

TEST(CalculatorTest, SimpleTestWithInvalidNegativeNumber) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("-79ab0"), "-79");
}

TEST(CalculatorTest, SimpleTestWithNegativeNumberAddedToAnotherNumber) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("-390+11"), "-379");
}

TEST(CalculatorTest, SimpleTestWithNegativeNumberSubstractedWithNegativeNumber) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("-390--11"), "-379");
}

TEST(CalculatorTest, SimpleTestWithPow) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("692^2"), "478864");
}

TEST(CalculatorTest, SimpleTestWithPowOne) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("690^1"), "690");
}

TEST(CalculatorTest, SimpleTestWithPowZero) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("1000000^0"), "1");
}

TEST(CalculatorTest, SimpleTestWithNegativeNumberToTheEvenPower) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("-231^2"), "53361");
}

TEST(CalculatorTest, SimpleTestWithNegativeNumberToTheOddPower) {
	Calculator calculator;
	EXPECT_EQ(calculator.Calculate("-21^3"), "-9261");
}

TEST(GetLastActionTest, SimpleTestWith399Minus100) {
	Calculator calculator;
	calculator.Calculate("399-100");
	EXPECT_EQ(calculator.GetLastAction(), "399-100=299");
}

TEST(GetLastActionTest, SimpleTestWithoutAction) {
	Calculator calculator;
	calculator.Calculate("");
	EXPECT_EQ(calculator.GetLastAction(), "");
}