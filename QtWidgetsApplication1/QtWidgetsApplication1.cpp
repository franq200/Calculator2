#include "QtWidgetsApplication1.h"
#include <iostream>
#include <QMessageBox>
#include <QRegularExpressionValidator>

QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9+-/*]+")));

	connect(ui.pushButton_0, &QPushButton::released, this, [this] { UpdateDisplay('0'); });
	connect(ui.pushButton_1, &QPushButton::released, this, [this] { UpdateDisplay('1'); });
	connect(ui.pushButton_2, &QPushButton::released, this, [this] { UpdateDisplay('2'); });
	connect(ui.pushButton_3, &QPushButton::released, this, [this] { UpdateDisplay('3'); });
	connect(ui.pushButton_4, &QPushButton::released, this, [this] { UpdateDisplay('4'); });
	connect(ui.pushButton_5, &QPushButton::released, this, [this] { UpdateDisplay('5'); });
	connect(ui.pushButton_6, &QPushButton::released, this, [this] { UpdateDisplay('6'); });
	connect(ui.pushButton_7, &QPushButton::released, this, [this] { UpdateDisplay('7'); });
	connect(ui.pushButton_8, &QPushButton::released, this, [this] { UpdateDisplay('8'); });
	connect(ui.pushButton_9, &QPushButton::released, this, [this] { UpdateDisplay('9'); });
	connect(ui.multiplication, &QPushButton::released, this, [this] { UpdateDisplay('*'); });
	connect(ui.division, &QPushButton::released, this, [this] { UpdateDisplay('/'); });
	connect(ui.power, &QPushButton::released, this, [this] { UpdateDisplay('^'); });
	connect(ui.addition, &QPushButton::released, this, [this] { UpdateDisplay('+'); });
	connect(ui.subtraction, &QPushButton::released, this, [this] { UpdateDisplay('-'); });
	connect(ui.back, &QPushButton::released, this, [this] { Back(); });
	connect(ui.equals, &QPushButton::released, this, [this] { ShowResult(); });
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

void QtWidgetsApplication1::Back()
{
	ui.lineEdit->setText(ui.lineEdit->displayText().removeLast());
}

void QtWidgetsApplication1::ShowResult()
{
	try
	{
		std::string result = m_calculator.Calculate(ui.lineEdit->displayText().toStdString());
		ui.myDisplay->display(result.c_str());
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