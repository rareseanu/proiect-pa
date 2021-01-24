/********************************************************************************
** Form generated from reading UI file 'EmptyNameDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPTYNAMEDIALOG_H
#define UI_EMPTYNAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EmptyNameDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *EmptyNameDialog)
    {
        if (EmptyNameDialog->objectName().isEmpty())
            EmptyNameDialog->setObjectName(QString::fromUtf8("EmptyNameDialog"));
        EmptyNameDialog->resize(360, 170);
        EmptyNameDialog->setMinimumSize(QSize(360, 170));
        EmptyNameDialog->setMaximumSize(QSize(360, 170));
        EmptyNameDialog->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        EmptyNameDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(EmptyNameDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(EmptyNameDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(EmptyNameDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);


        retranslateUi(EmptyNameDialog);

        QMetaObject::connectSlotsByName(EmptyNameDialog);
    } // setupUi

    void retranslateUi(QDialog *EmptyNameDialog)
    {
        EmptyNameDialog->setWindowTitle(QCoreApplication::translate("EmptyNameDialog", "Enter Name", nullptr));
        label->setText(QCoreApplication::translate("EmptyNameDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">You must enter your full name </span></p><p align=\"center\"><span style=\" font-size:12pt;\">before starting the quiz.</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("EmptyNameDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmptyNameDialog: public Ui_EmptyNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPTYNAMEDIALOG_H
