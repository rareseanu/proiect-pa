/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *welcomeLabel;
    QLabel *enterNameLabel;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QVBoxLayout *verticalLayout;
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *startQuizButton;
    QPushButton *closeButton;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(450, 193);
        StartWindow->setMinimumSize(QSize(450, 193));
        StartWindow->setMaximumSize(QSize(450, 193));
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(450, 193));
        centralwidget->setMaximumSize(QSize(450, 193));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 431, 71));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        welcomeLabel = new QLabel(widget);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Semibold"));
        font.setPointSize(16);
        font.setBold(true);
        welcomeLabel->setFont(font);

        verticalLayout_3->addWidget(welcomeLabel);

        enterNameLabel = new QLabel(widget);
        enterNameLabel->setObjectName(QString::fromUtf8("enterNameLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI Semibold"));
        font1.setPointSize(12);
        font1.setBold(true);
        enterNameLabel->setFont(font1);

        verticalLayout_3->addWidget(enterNameLabel);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 90, 431, 54));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        firstNameLabel = new QLabel(widget1);
        firstNameLabel->setObjectName(QString::fromUtf8("firstNameLabel"));

        verticalLayout_2->addWidget(firstNameLabel);

        lastNameLabel = new QLabel(widget1);
        lastNameLabel->setObjectName(QString::fromUtf8("lastNameLabel"));

        verticalLayout_2->addWidget(lastNameLabel);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        firstNameEdit = new QLineEdit(widget1);
        firstNameEdit->setObjectName(QString::fromUtf8("firstNameEdit"));

        verticalLayout->addWidget(firstNameEdit);

        lastNameEdit = new QLineEdit(widget1);
        lastNameEdit->setObjectName(QString::fromUtf8("lastNameEdit"));

        verticalLayout->addWidget(lastNameEdit);


        horizontalLayout_2->addLayout(verticalLayout);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(10, 160, 431, 26));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        startQuizButton = new QPushButton(widget2);
        startQuizButton->setObjectName(QString::fromUtf8("startQuizButton"));

        horizontalLayout->addWidget(startQuizButton);

        closeButton = new QPushButton(widget2);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);

        StartWindow->setCentralWidget(centralwidget);

        retranslateUi(StartWindow);
        QObject::connect(closeButton, &QPushButton::clicked, StartWindow, &QMainWindow::close);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "Questionnaire", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("StartWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Welcome!</span></p></body></html>", nullptr));
        enterNameLabel->setText(QCoreApplication::translate("StartWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Enter your name below:</span></p></body></html>", nullptr));
        firstNameLabel->setText(QCoreApplication::translate("StartWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">First name:</span></p></body></html>", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("StartWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Last name:</span></p></body></html>", nullptr));
        startQuizButton->setText(QCoreApplication::translate("StartWindow", "Start Quiz", nullptr));
        closeButton->setText(QCoreApplication::translate("StartWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
