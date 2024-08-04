#include <QApplication>

#include "mainWindow/mainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto* mainWindow = new MainWindow;
//    QString* expression = new QString("1+2*-4-5/6");    //-13 / 6
//    Math math(expression);
//    qDebug() << math.getResult();

    return QApplication::exec();
}

//1 + 8 - 5 / 6
//i - 8 - 5 / 6