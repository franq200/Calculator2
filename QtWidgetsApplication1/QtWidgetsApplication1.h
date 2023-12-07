#pragma once
#include <string>
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include "Calculator.h"

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget* parent = nullptr);
    ~QtWidgetsApplication1();
private:
    void UpdateDisplay(char chr);
    void ShowWarningInformation(std::string msg);
    void Back();
    void ShowResult();

    Ui::QtWidgetsApplication1Class ui;
    Calculator m_calculator;
};