#include "QtWidgetsApplication1.h"
#include <iostream>
#include <QMessageBox>
#include <QRegularExpressionValidator>

QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9+-/*]+")));
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

void QtWidgetsApplication1::Add()
{
	UpdateDisplay('+');
}
void QtWidgetsApplication1::Subtrack()
{
	UpdateDisplay('-');
}
void QtWidgetsApplication1::Multiple()
{
	UpdateDisplay('*');
}
void QtWidgetsApplication1::Divide()
{
	UpdateDisplay('/');
}
void QtWidgetsApplication1::Power()
{
	UpdateDisplay('^');
}
void QtWidgetsApplication1::Zero()
{
	UpdateDisplay('0');
}
void QtWidgetsApplication1::One()
{
	UpdateDisplay('1');
}
void QtWidgetsApplication1::Two()
{
	UpdateDisplay('2');
}
void QtWidgetsApplication1::Three()
{
	UpdateDisplay('3');
}
void QtWidgetsApplication1::Four()
{
	UpdateDisplay('4');
}
void QtWidgetsApplication1::Five()
{
	UpdateDisplay('5');
}
void QtWidgetsApplication1::Six()
{
	UpdateDisplay('6');
}
void QtWidgetsApplication1::Seven()
{
	UpdateDisplay('7');
}
void QtWidgetsApplication1::Eight()
{
	UpdateDisplay('8');
}
void QtWidgetsApplication1::Nine()
{
	UpdateDisplay('9');
}
void QtWidgetsApplication1::Back()
{
	ui.lineEdit->setText(ui.lineEdit->displayText().removeLast());
}

void QtWidgetsApplication1::ShowResult()
{
	try
	{
		int result = m_calculator.Calculate(ui.lineEdit->displayText().toStdString());
		ui.myDisplay->display(result);
		auto history = m_calculator.GetLastAction();
		ui.history->addItem(history.c_str());
	}
	catch (const std::exception& e)
	{
		ShowWarningInformation(e.what());
	}
}

void QtWidgetsApplication1::UpdateDisplay(char chr)
{
	ui.lineEdit->setText(ui.lineEdit->displayText() + chr);
}

void QtWidgetsApplication1::ShowWarningInformation(std::string msg)
{
	QMessageBox msgBox;
	msgBox.setText(msg.c_str());
	msgBox.exec();
}