#include "math.h"

Math::Math(QString math)     :
expression(math)
{
    getLiterals();
    getNumbers();
    for(int i = 0; i < numbers.size(); i++)     qDebug() << numbers[i];
}
void Math::getLiterals()
{
    for(int i = 0; i < expression.size(); i++) {
        if (checkSign(expression.at(i)) != none) {
            literals.push_back(checkSign(expression.at(i)));
            if (i + 1 < expression.size() && expression.at(i + 1) == '-') {
                i++;
            }
        }
    }
}
Math::Literals Math::checkSign(QChar sign)
{
    switch (sign.toLatin1())
    {
        case '+':   return dod;
        case '-':   return od;
        case 'x':   return mn;
        case '/':   return dz;
        default:    return none;
    }
}

QString Math::getResult()
{
    double result = numbers[0];
    double number;
    if(literals.size() > 1)
    {
        for(int i = 0; i < literals.size(); i++)
        {
            if(literals[i] == mn)
            {
                number = numbers[i] * numbers[i + 1];
                numbers[i] = number;
                numbers.erase(numbers.begin() + i + 1);

                literals.erase(literals.begin() + i);
            }else if(literals[i] == dz)
            {
                number = numbers[i] / numbers[i + 1];
                numbers[i] = number;
                numbers.erase(numbers.begin() + i + 1);

                literals.erase(literals.begin() + i);
            }
        }
        for(int i = 0; i < literals.size(); i++)
        {
            if(literals[i] == dod)
            {
                result += numbers[i + 1];
            }else if(literals[i] == od)
            {
                result -= numbers[i + 1];
            }
        }
    }else
    {
        if(literals[0] == dod)      return QString::number(result + numbers[1]);
        if(literals[0] == od)      return QString::number(result - numbers[1]);
        if(literals[0] == dz)      return QString::number(result / numbers[1]);
        if(literals[0] == mn)      return QString::number(result * numbers[1]);
    }
    return QString::number(result);
}

void Math::getNumbers()
{
    bool negation = false;
    QString numb;
    numbers.clear();
    for(int i = 0; i < expression.size(); i++)
    {
        if(checkSign(expression.at(i)) == none)
        {
            numb += expression.at(i);
            if((i + 1) < expression.size()  && checkSign(expression.at(i + 1)) != none)
            {
                if(negation)
                {
                    numbers.push_back(numb.toInt() * - 1);
                    negation = false;
                }
                else    numbers.push_back(numb.toInt());
                numb.clear();
            }
        }else if(i + 1 < expression.size() && expression.at(i + 1) == '-')
        {
            negation = true;
        }
    }
    if(negation)    numbers.push_back(numb.toInt() * - 1);
    else    numbers.push_back(numb.toInt());
}
