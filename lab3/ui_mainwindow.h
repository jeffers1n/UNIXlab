/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *inputText;
    QPushButton *convertButton;
    QLabel *morseCodeLabel;
    QLabel *lampLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        inputText = new QLineEdit(centralWidget);
        inputText->setObjectName(QString::fromUtf8("inputText"));

        verticalLayout->addWidget(inputText);

        convertButton = new QPushButton(centralWidget);
        convertButton->setObjectName(QString::fromUtf8("convertButton"));

        verticalLayout->addWidget(convertButton);

        morseCodeLabel = new QLabel(centralWidget);
        morseCodeLabel->setObjectName(QString::fromUtf8("morseCodeLabel"));

        verticalLayout->addWidget(morseCodeLabel);

        lampLabel = new QLabel(centralWidget);
        lampLabel->setObjectName(QString::fromUtf8("lampLabel"));
        lampLabel->setMinimumSize(QSize(50, 50));
        lampLabel->setStyleSheet(QString::fromUtf8("background-color: gray; border-radius: 25px;"));

        verticalLayout->addWidget(lampLabel);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Morse Code Converter", nullptr));
        convertButton->setText(QCoreApplication::translate("MainWindow", "Convert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
