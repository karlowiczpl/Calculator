#ifndef MATH_T
#define MATH_T

#include <QString>
#include <vector>
#include <QDebug>

class Math
{
public:
    Math(QString expression);
    QString getResult();

private:
    enum Literals
    {
        none,
        dod,
        od,
        mn,
        dz,
    };

    void getLiterals();
    Literals checkSign(QChar sign);
    void getNumbers();

    std::vector<double> numbers;
    std::vector<Literals> literals;

    QString expression;

};


#endif // MATH_T