/********************************************************************************
** Form generated from reading UI file 'thirddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRDDIALOG_H
#define UI_THIRDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ThirdDialog
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

    void setupUi(QDialog *ThirdDialog)
    {
        if (ThirdDialog->objectName().isEmpty())
            ThirdDialog->setObjectName(QString::fromUtf8("ThirdDialog"));
        ThirdDialog->resize(780, 556);
        label = new QLabel(ThirdDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 90, 141, 51));
        radioButton = new QRadioButton(ThirdDialog);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(30, 150, 95, 20));
        radioButton_2 = new QRadioButton(ThirdDialog);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(30, 200, 95, 20));
        radioButton_3 = new QRadioButton(ThirdDialog);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(30, 250, 95, 20));
        radioButton_4 = new QRadioButton(ThirdDialog);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(30, 300, 95, 20));
        pushButton = new QPushButton(ThirdDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(450, 510, 141, 31));
        pushButton_2 = new QPushButton(ThirdDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(610, 510, 161, 31));
        label_2 = new QLabel(ThirdDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 71, 21));

        retranslateUi(ThirdDialog);

        QMetaObject::connectSlotsByName(ThirdDialog);
    } // setupUi

    void retranslateUi(QDialog *ThirdDialog)
    {
        ThirdDialog->setWindowTitle(QCoreApplication::translate("ThirdDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ThirdDialog", "Alege raspunsul corect", nullptr));
        radioButton->setText(QCoreApplication::translate("ThirdDialog", "A", nullptr));
        radioButton_2->setText(QCoreApplication::translate("ThirdDialog", "B", nullptr));
        radioButton_3->setText(QCoreApplication::translate("ThirdDialog", "C", nullptr));
        radioButton_4->setText(QCoreApplication::translate("ThirdDialog", "D", nullptr));
        pushButton->setText(QCoreApplication::translate("ThirdDialog", "Intrebarea anterioare", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ThirdDialog", "Trimite Raspunsurile", nullptr));
        label_2->setText(QCoreApplication::translate("ThirdDialog", "Intrebarea3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThirdDialog: public Ui_ThirdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDDIALOG_H