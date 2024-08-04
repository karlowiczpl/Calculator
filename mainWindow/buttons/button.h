#ifndef CALCULATOR_BUTTON_H
#define CALCULATOR_BUTTON_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QLineEdit>

#define normal 0
#define rst 1
#define bracket 2
#define prc 3
#define bck 4
#define point 5
#define sum 6
#define character 7

class Button : public QWidget {
Q_OBJECT

public:

    explicit Button(QString name , QColor color , int flag , QLineEdit* lineEdit);
    void changeSize(int width , int height);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QString name;
    QColor color;
    QLineEdit* lineEdit;

    int buttonHeight;
    int buttonWidth;

    int buttonFlag;
};


#endif //CALCULATOR_BUTTON_H
