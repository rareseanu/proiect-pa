/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QString::fromUtf8("SecDialog"));
        SecDialog->resize(812, 557);
        SecDialog->setStyleSheet(QString::fromUtf8("background-color:rgb(113, 211, 220);"));
        label = new QLabel(SecDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 80, 141, 41));
        radioButton = new QRadioButton(SecDialog);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(30, 140, 95, 20));
        radioButton_2 = new QRadioButton(SecDialog);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(30, 190, 95, 20));
        radioButton_3 = new QRadioButton(SecDialog);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(30, 240, 95, 20));
        radioButton_4 = new QRadioButton(SecDialog);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(30, 290, 95, 20));
        pushButton = new QPushButton(SecDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(640, 500, 141, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 169, 202, 255), stop:1 rgba(255, 255, 255, 255));"));
        pushButton_2 = new QPushButton(SecDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(490, 500, 141, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 169, 202, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_2 = new QLabel(SecDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 60, 81, 21));
        label_3 = new QLabel(SecDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 460, 71, 21));
        lineEdit = new QLineEdit(SecDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 500, 341, 31));
        pushButton_3 = new QPushButton(SecDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(660, 430, 93, 28));

        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QCoreApplication::translate("SecDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SecDialog", "Alege raspunsul corect", nullptr));
        radioButton->setText(QCoreApplication::translate("SecDialog", "A", nullptr));
        radioButton_2->setText(QCoreApplication::translate("SecDialog", "B", nullptr));
        radioButton_3->setText(QCoreApplication::translate("SecDialog", "C", nullptr));
        radioButton_4->setText(QCoreApplication::translate("SecDialog", "D", nullptr));
        pushButton->setText(QCoreApplication::translate("SecDialog", "Intrebarea urmatoare", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SecDialog", "Intrebarea anterioara", nullptr));
        label_2->setText(QCoreApplication::translate("SecDialog", "Intrebarea2", nullptr));
        label_3->setText(QCoreApplication::translate("SecDialog", "Comentarii:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SecDialog", "Verificare", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
