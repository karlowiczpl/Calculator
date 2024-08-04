#include "mainWindow.h"
#include "buttons/button.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSizePolicy>

MainWindow::MainWindow()
{
    mainDisplay = new QLineEdit(this);
    mainDisplay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    connect(mainDisplay , &QLineEdit::textChanged , this , &MainWindow::onTextChanged);

    setMinimumSize(320 , 500);

    auto *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    auto *mainLayout = new QVBoxLayout(centralWidget);
    centralWidget->setLayout(mainLayout);

    mainLayout->addWidget(mainDisplay);

    auto *keyboardLayout = new QGridLayout;
    mainLayout->addLayout(keyboardLayout);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            auto *button = new Button(buttonsNames[i][j], buttonsColor[i][j] , buttonFlags[i][j] , mainDisplay);
            keyboardLayout->addWidget(button, i, j);
            buttons[i][j] = button;
        }
    }
    show();
    resize(360, 510);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QFont font1;
    font1.setPointSize(event->size().height() / 15);
    mainDisplay->setFont(font1);

    mainDisplay->setFixedHeight(event->size().height() / 6);
    for(auto & button : buttons)
        for(auto & j : button)
            j->changeSize((int)(event->size().width() / 4.5) , (int)(event->size().height() / 6.7));

}

void MainWindow::onTextChanged()
{
    QString text = mainDisplay->displayText();
    if(text.back() == '*')
    {
        text[text.length() - 1] = QChar('x');
        mainDisplay->setText(text);
    }
}
