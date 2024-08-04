#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>

#include "buttons/button.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

protected slots:
    void onTextChanged();

private:
    QLineEdit *mainDisplay;
    Button* buttons[5][4]{};

#include <QColor>

    QColor buttonsColor[5][4] = {
            { QColor(200, 200, 200), QColor(200, 200, 200), QColor(200, 200, 200), QColor(255, 165, 0) }, // Row 1: 0-3 (numeric and equals)
            { QColor(220, 220, 220), QColor(220, 220, 220), QColor(220, 220, 220), QColor(255, 165, 0) }, // Row 2: 4-7 (numeric and equals)
            { QColor(220, 220, 220), QColor(220, 220, 220), QColor(220, 220, 220), QColor(255, 165, 0) }, // Row 3: 8-9 (numeric) and equals
            { QColor(220, 220, 220), QColor(220, 220, 220), QColor(220, 220, 220), QColor(50, 50, 50) },    // Row 4: AC, 1-3 (numeric and operator)
            { QColor(0, 122, 255), QColor(0, 122, 255), QColor(0, 122, 255), QColor(50, 50, 50) }        // Row 5: AC, CE, CE, operator
    };
    QString buttonsNames[5][4]{
            {"AC" , "()" , "%" , "/"},
            {"7" , "8" , "9" , "x"},
            {"4" , "5" , "6" , "-"},
            {"1" , "2" , "3" , "+"},
            {"0" , "," , "bac" , "="}
    };
    int buttonFlags[5][4]
            {
                    {rst  , bracket , normal , character},
                    {normal , normal , normal , character},
                    {normal , normal , normal , character},
                    {normal , normal , normal , character},
                    {normal , point , bck , sum}
            };
};

#endif // MAIN_WINDOW_H
