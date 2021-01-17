/********************************************************************************
** Form generated from reading UI file 'FraudDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAUDDIALOG_H
#define UI_FRAUDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FraudDialog
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *oopsLabel;
    QLabel *sendLabel;

    void setupUi(QDialog *FraudDialog)
    {
        if (FraudDialog->objectName().isEmpty())
            FraudDialog->setObjectName(QString::fromUtf8("FraudDialog"));
        FraudDialog->resize(430, 175);
        FraudDialog->setMinimumSize(QSize(430, 175));
        FraudDialog->setMaximumSize(QSize(430, 175));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FraudDialog->setWindowIcon(icon);
        pushButton = new QPushButton(FraudDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 130, 93, 28));
        layoutWidget = new QWidget(FraudDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 411, 84));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        oopsLabel = new QLabel(layoutWidget);
        oopsLabel->setObjectName(QString::fromUtf8("oopsLabel"));
        QFont font;
        font.setPointSize(10);
        oopsLabel->setFont(font);
        oopsLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(oopsLabel);

        sendLabel = new QLabel(layoutWidget);
        sendLabel->setObjectName(QString::fromUtf8("sendLabel"));
        sendLabel->setMaximumSize(QSize(300, 16777215));
        sendLabel->setFont(font);
        sendLabel->setContextMenuPolicy(Qt::NoContextMenu);
        sendLabel->setAcceptDrops(false);
        sendLabel->setLayoutDirection(Qt::LeftToRight);
        sendLabel->setTextFormat(Qt::AutoText);
        sendLabel->setScaledContents(false);
        sendLabel->setAlignment(Qt::AlignCenter);
        sendLabel->setWordWrap(true);

        verticalLayout->addWidget(sendLabel, 0, Qt::AlignHCenter);


        retranslateUi(FraudDialog);
        QObject::connect(pushButton, &QPushButton::clicked, FraudDialog, &QDialog::accept);

        QMetaObject::connectSlotsByName(FraudDialog);
    } // setupUi

    void retranslateUi(QDialog *FraudDialog)
    {
        FraudDialog->setWindowTitle(QCoreApplication::translate("FraudDialog", "Cheating Detected", nullptr));
        pushButton->setText(QCoreApplication::translate("FraudDialog", "Ok", nullptr));
        oopsLabel->setText(QCoreApplication::translate("FraudDialog", "Oops! You clicked outside of the app window. :(", nullptr));
        sendLabel->setText(QCoreApplication::translate("FraudDialog", "Doing this while the quiz is running will stop the quiz and send the current results.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FraudDialog: public Ui_FraudDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAUDDIALOG_H
