#include "button.h"
#include "../math/math.h"

#include <utility>

Button::Button(QString name , QColor col , int flag , QLineEdit* lineEdit1)    :
name(std::move(name)) , buttonWidth(80) , buttonHeight(80) , color(std::move(col)) , buttonFlag(flag) , lineEdit(lineEdit1)
{
    resize(50 , 50);
    show();
}

void Button::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    int x = width() / 2;
    int y = height() / 2;

    painter.setBrush(color);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(x - (buttonWidth / 2), y - (buttonHeight / 2), buttonWidth, buttonHeight);

    QFont font1 = painter.font();
    font1.setPointSize(20);
    painter.setFont(font1);
    painter.setPen(Qt::black);

    QRect textRect(x - buttonWidth / 2, y - buttonHeight / 2, buttonWidth, buttonHeight);
    painter.drawText(textRect, Qt::AlignCenter, name);
}

void Button::changeSize(int wid, int hei)
{
    buttonWidth = wid;
    buttonHeight = hei;
}

void Button::mousePressEvent(QMouseEvent *event)
{
    color = color.darker(150);
    update();

//    qDebug() << buttonFlag << name;

    if(buttonFlag == normal)
    {
        lineEdit->setText(lineEdit->displayText() + name);
    }else if(buttonFlag == character)
    {
        lineEdit->setText(lineEdit->displayText() + name);
    }else if(buttonFlag == bracket)
    {
        QString text = lineEdit->displayText();
        bool bracketClose = true;

        for(auto i : text)
        {
            if(i == ')')   bracketClose = true;
            else if(i == '(')   bracketClose = false;
        }

        lineEdit->setText(lineEdit->displayText() + (!bracketClose ? ")" : "("));
    }else if(buttonFlag == sum)
    {
        QString expression = lineEdit->displayText();
        expression.remove(" ");
        Math m1(expression);
        lineEdit->setText(m1.getResult());
    }else if(buttonFlag == rst)
    {
        lineEdit->setText("");
    }else if(buttonFlag == bck)
    {
        QString n = lineEdit->displayText();
        n.chop(1);
        lineEdit->setText(n);
    }

}

void Button::mouseReleaseEvent(QMouseEvent *event) {
    color = color.lighter(150);
    update();
}
