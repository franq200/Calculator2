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

public slots:
    void Add();
    void Subtrack();
    void Multiple();
    void Divide();
    void Power();
    void Zero();
    void One();
    void Two();
    void Three();
    void Four();
    void Five();
    void Six();
    void Seven();
    void Eight();
    void Nine();
    void Back();
    void ShowResult();

private:
    void UpdateDisplay(char chr);
    void ShowWarningInformation(std::string msg);

    Ui::QtWidgetsApplication1Class ui;
    Calculator m_calculator;
};
/*
kalkulator:
- z jakim� wygl�dem
- podstawowy
- wy�wietlacz kt�ry poka�e wynik
- doda� jakie� opcje na g�rze np zamknij kalkulator (cokolwiek)
(-grid layout)
*/