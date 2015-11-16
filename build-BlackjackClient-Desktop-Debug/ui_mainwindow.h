/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonStand;
    QPushButton *pushButtonConnect;
    QLineEdit *lineEditIP;
    QPushButton *pushButtonHit;
    QLineEdit *lineEditName;
    QLabel *labelName;
    QLabel *labelIP;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(439, 330);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonStand = new QPushButton(centralWidget);
        pushButtonStand->setObjectName(QStringLiteral("pushButtonStand"));
        pushButtonStand->setGeometry(QRect(240, 260, 121, 51));
        pushButtonConnect = new QPushButton(centralWidget);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(174, 190, 111, 51));
        lineEditIP = new QLineEdit(centralWidget);
        lineEditIP->setObjectName(QStringLiteral("lineEditIP"));
        lineEditIP->setGeometry(QRect(174, 120, 161, 31));
        pushButtonHit = new QPushButton(centralWidget);
        pushButtonHit->setObjectName(QStringLiteral("pushButtonHit"));
        pushButtonHit->setGeometry(QRect(100, 260, 121, 51));
        lineEditName = new QLineEdit(centralWidget);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(174, 60, 161, 31));
        labelName = new QLabel(centralWidget);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(94, 70, 67, 17));
        labelIP = new QLabel(centralWidget);
        labelIP->setObjectName(QStringLiteral("labelIP"));
        labelIP->setGeometry(QRect(80, 130, 81, 20));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 20, 401, 221));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButtonStand->setText(QApplication::translate("MainWindow", "Stand", 0));
        pushButtonConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        lineEditIP->setText(QApplication::translate("MainWindow", "172.17.13.144", 0));
        pushButtonHit->setText(QApplication::translate("MainWindow", "Hit", 0));
        lineEditName->setText(QApplication::translate("MainWindow", "abcd", 0));
        labelName->setText(QApplication::translate("MainWindow", "Name:", 0));
        labelIP->setText(QApplication::translate("MainWindow", "Server's IP:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
