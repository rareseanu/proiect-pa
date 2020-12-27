/********************************************************************************
** Form generated from reading UI file 'SendDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDDIALOG_H
#define UI_SENDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SendDialog
{
public:
    QLabel *thanksLabel;
    QPushButton *pushButton;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *whereLabel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *studentLabel;
    QLabel *markLabel;
    QLabel *mailLabel;
    QVBoxLayout *verticalLayout_2;
    QLabel *nameLabel;
    QLabel *actualMarkLabel;
    QLineEdit *mailEdit;

    void setupUi(QDialog *SendDialog)
    {
        if (SendDialog->objectName().isEmpty())
            SendDialog->setObjectName(QString::fromUtf8("SendDialog"));
        SendDialog->resize(638, 365);
        thanksLabel = new QLabel(SendDialog);
        thanksLabel->setObjectName(QString::fromUtf8("thanksLabel"));
        thanksLabel->setGeometry(QRect(130, 60, 391, 41));
        pushButton = new QPushButton(SendDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 310, 171, 28));
        label = new QLabel(SendDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 131, 51));
        label->setPixmap(QPixmap(QString::fromUtf8("images/UNITBV_MI_logo.png")));
        layoutWidget = new QWidget(SendDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 140, 381, 123));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        whereLabel = new QLabel(layoutWidget);
        whereLabel->setObjectName(QString::fromUtf8("whereLabel"));

        verticalLayout_3->addWidget(whereLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        studentLabel = new QLabel(layoutWidget);
        studentLabel->setObjectName(QString::fromUtf8("studentLabel"));

        verticalLayout->addWidget(studentLabel);

        markLabel = new QLabel(layoutWidget);
        markLabel->setObjectName(QString::fromUtf8("markLabel"));

        verticalLayout->addWidget(markLabel);

        mailLabel = new QLabel(layoutWidget);
        mailLabel->setObjectName(QString::fromUtf8("mailLabel"));

        verticalLayout->addWidget(mailLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        verticalLayout_2->addWidget(nameLabel);

        actualMarkLabel = new QLabel(layoutWidget);
        actualMarkLabel->setObjectName(QString::fromUtf8("actualMarkLabel"));

        verticalLayout_2->addWidget(actualMarkLabel);

        mailEdit = new QLineEdit(layoutWidget);
        mailEdit->setObjectName(QString::fromUtf8("mailEdit"));

        verticalLayout_2->addWidget(mailEdit);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(SendDialog);
        QObject::connect(pushButton, &QPushButton::clicked, SendDialog, &QDialog::close);

        QMetaObject::connectSlotsByName(SendDialog);
    } // setupUi

    void retranslateUi(QDialog *SendDialog)
    {
        SendDialog->setWindowTitle(QCoreApplication::translate("SendDialog", "Results", nullptr));
        thanksLabel->setText(QCoreApplication::translate("SendDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Thank you for your time! :)</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("SendDialog", "Send", nullptr));
        label->setText(QString());
        whereLabel->setText(QCoreApplication::translate("SendDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">Where should we send the results?</span></p></body></html>", nullptr));
        studentLabel->setText(QCoreApplication::translate("SendDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">Student:</span></p></body></html>", nullptr));
        markLabel->setText(QCoreApplication::translate("SendDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">Mark:</span></p></body></html>", nullptr));
        mailLabel->setText(QCoreApplication::translate("SendDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">Teacher's e-mail address:</span></p></body></html>", nullptr));
        nameLabel->setText(QCoreApplication::translate("SendDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">[name]</span></p></body></html>", nullptr));
        actualMarkLabel->setText(QCoreApplication::translate("SendDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">[mark]</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendDialog: public Ui_SendDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDDIALOG_H
