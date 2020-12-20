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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QString::fromUtf8("SecDialog"));
        SecDialog->resize(812, 557);
        SecDialog->setStyleSheet(QString::fromUtf8("background-color:rgb(113, 211, 220);"));
        label = new QLabel(SecDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 80, 141, 41));
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
        pushButton_3->setGeometry(QRect(640, 450, 141, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 169, 202, 255), stop:1 rgba(255, 255, 255, 255));"));
        checkBox = new QCheckBox(SecDialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(40, 160, 81, 20));
        checkBox_2 = new QCheckBox(SecDialog);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(40, 210, 81, 20));
        checkBox_3 = new QCheckBox(SecDialog);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(40, 260, 81, 20));
        checkBox_4 = new QCheckBox(SecDialog);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(40, 310, 81, 20));

        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QCoreApplication::translate("SecDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SecDialog", "Alege raspunsul corect", nullptr));
        pushButton->setText(QCoreApplication::translate("SecDialog", "Intrebarea urmatoare", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SecDialog", "Intrebarea anterioara", nullptr));
        label_2->setText(QCoreApplication::translate("SecDialog", "Intrebarea2", nullptr));
        label_3->setText(QCoreApplication::translate("SecDialog", "Comentarii:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SecDialog", "Verificare", nullptr));
        checkBox->setText(QCoreApplication::translate("SecDialog", "A", nullptr));
        checkBox_2->setText(QCoreApplication::translate("SecDialog", "B", nullptr));
        checkBox_3->setText(QCoreApplication::translate("SecDialog", "C", nullptr));
        checkBox_4->setText(QCoreApplication::translate("SecDialog", "D", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
