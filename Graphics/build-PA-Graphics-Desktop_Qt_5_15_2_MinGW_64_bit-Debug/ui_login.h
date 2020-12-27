/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_usename;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_Login;
    QLabel *label_3;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(774, 544);
        Login->setStyleSheet(QString::fromUtf8("background-color:rgb(113, 211, 220);"));
        groupBox = new QGroupBox(Login);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 210, 381, 301));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label);

        lineEdit_usename = new QLineEdit(groupBox);
        lineEdit_usename->setObjectName(QString::fromUtf8("lineEdit_usename"));
        lineEdit_usename->setStyleSheet(QString::fromUtf8("background-color:rgb(103, 111, 255)"));

        horizontalLayout->addWidget(lineEdit_usename);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color:rgb(103, 111, 255)"));

        horizontalLayout_2->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_Login = new QPushButton(Login);
        pushButton_Login->setObjectName(QString::fromUtf8("pushButton_Login"));
        pushButton_Login->setGeometry(QRect(600, 480, 101, 31));
        pushButton_Login->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 169, 202, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 10, 311, 171));
        label_3->setPixmap(QPixmap(QString::fromUtf8("C:/Users/User/Pictures/Saved Pictures/Project.jpg")));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Login", "Singin", nullptr));
        label->setText(QCoreApplication::translate("Login", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Password", nullptr));
        lineEdit_password->setText(QString());
        pushButton_Login->setText(QCoreApplication::translate("Login", "Login", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
