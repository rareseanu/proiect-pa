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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QLabel *timerStartedLabel;
    QLabel *timerStoppedLabel;
    QVBoxLayout *verticalLayout_2;
    QLabel *nameLabel;
    QLabel *actualMarkLabel;
    QLabel *time1Label;
    QLabel *time2Label;
    QLabel *label_2;

    void setupUi(QDialog *SendDialog)
    {
        if (SendDialog->objectName().isEmpty())
            SendDialog->setObjectName(QString::fromUtf8("SendDialog"));
        SendDialog->resize(638, 365);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SendDialog->setWindowIcon(icon);
        thanksLabel = new QLabel(SendDialog);
        thanksLabel->setObjectName(QString::fromUtf8("thanksLabel"));
        thanksLabel->setGeometry(QRect(130, 60, 391, 41));
        QFont font;
        font.setPointSize(16);
        thanksLabel->setFont(font);
        thanksLabel->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(SendDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 310, 171, 28));
        label = new QLabel(SendDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 131, 51));
        label->setPixmap(QPixmap(QString::fromUtf8("images/UNITBV_MI_logo.png")));
        layoutWidget = new QWidget(SendDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 110, 381, 154));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        whereLabel = new QLabel(layoutWidget);
        whereLabel->setObjectName(QString::fromUtf8("whereLabel"));
        whereLabel->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(12);
        whereLabel->setFont(font1);
        whereLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(whereLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        studentLabel = new QLabel(layoutWidget);
        studentLabel->setObjectName(QString::fromUtf8("studentLabel"));
        studentLabel->setFont(font1);
        studentLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(studentLabel);

        markLabel = new QLabel(layoutWidget);
        markLabel->setObjectName(QString::fromUtf8("markLabel"));
        markLabel->setFont(font1);
        markLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(markLabel);

        timerStartedLabel = new QLabel(layoutWidget);
        timerStartedLabel->setObjectName(QString::fromUtf8("timerStartedLabel"));

        verticalLayout->addWidget(timerStartedLabel);

        timerStoppedLabel = new QLabel(layoutWidget);
        timerStoppedLabel->setObjectName(QString::fromUtf8("timerStoppedLabel"));

        verticalLayout->addWidget(timerStoppedLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setFont(font1);
        nameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(nameLabel);

        actualMarkLabel = new QLabel(layoutWidget);
        actualMarkLabel->setObjectName(QString::fromUtf8("actualMarkLabel"));
        actualMarkLabel->setFont(font1);
        actualMarkLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(actualMarkLabel);

        time1Label = new QLabel(layoutWidget);
        time1Label->setObjectName(QString::fromUtf8("time1Label"));

        verticalLayout_2->addWidget(time1Label);

        time2Label = new QLabel(layoutWidget);
        time2Label->setObjectName(QString::fromUtf8("time2Label"));

        verticalLayout_2->addWidget(time2Label);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        label_2 = new QLabel(SendDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 171, 71));
        label_2->setPixmap(QPixmap(QString::fromUtf8("images/UNITBV_FMI.png")));
        label_2->setScaledContents(true);

        retranslateUi(SendDialog);
        QObject::connect(pushButton, &QPushButton::clicked, SendDialog, &QDialog::close);

        QMetaObject::connectSlotsByName(SendDialog);
    } // setupUi

    void retranslateUi(QDialog *SendDialog)
    {
        SendDialog->setWindowTitle(QCoreApplication::translate("SendDialog", "Results", nullptr));
        thanksLabel->setText(QCoreApplication::translate("SendDialog", "Thank you for your time! :)", nullptr));
        pushButton->setText(QCoreApplication::translate("SendDialog", "Close", nullptr));
        label->setText(QString());
        whereLabel->setText(QCoreApplication::translate("SendDialog", "The results were sent into the database.", nullptr));
        studentLabel->setText(QCoreApplication::translate("SendDialog", "Student:", nullptr));
        markLabel->setText(QCoreApplication::translate("SendDialog", "Mark:", nullptr));
        timerStartedLabel->setText(QCoreApplication::translate("SendDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Timer started at:</span></p></body></html>", nullptr));
        timerStoppedLabel->setText(QCoreApplication::translate("SendDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Timer stopped at:</span></p></body></html>", nullptr));
        nameLabel->setText(QCoreApplication::translate("SendDialog", "[name]", nullptr));
        actualMarkLabel->setText(QCoreApplication::translate("SendDialog", "[mark]", nullptr));
        time1Label->setText(QCoreApplication::translate("SendDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">[time1]</span></p></body></html>", nullptr));
        time2Label->setText(QCoreApplication::translate("SendDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">[time2]</span></p></body></html>", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SendDialog: public Ui_SendDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDDIALOG_H
