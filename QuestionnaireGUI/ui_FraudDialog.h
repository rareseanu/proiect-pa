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

QT_BEGIN_NAMESPACE

class Ui_FraudDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *oopsLabel;
    QLabel *sendLabel;
    QPushButton *pushButton;

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
        verticalLayout_2 = new QVBoxLayout(FraudDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        oopsLabel = new QLabel(FraudDialog);
        oopsLabel->setObjectName(QString::fromUtf8("oopsLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(oopsLabel->sizePolicy().hasHeightForWidth());
        oopsLabel->setSizePolicy(sizePolicy);
        oopsLabel->setMaximumSize(QSize(800, 16777215));
        QFont font;
        font.setPointSize(10);
        oopsLabel->setFont(font);
        oopsLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(oopsLabel, 0, Qt::AlignHCenter);

        sendLabel = new QLabel(FraudDialog);
        sendLabel->setObjectName(QString::fromUtf8("sendLabel"));
        sizePolicy.setHeightForWidth(sendLabel->sizePolicy().hasHeightForWidth());
        sendLabel->setSizePolicy(sizePolicy);
        sendLabel->setMaximumSize(QSize(600, 16777215));
        sendLabel->setFont(font);
        sendLabel->setContextMenuPolicy(Qt::NoContextMenu);
        sendLabel->setAcceptDrops(false);
        sendLabel->setLayoutDirection(Qt::LeftToRight);
        sendLabel->setTextFormat(Qt::AutoText);
        sendLabel->setScaledContents(false);
        sendLabel->setAlignment(Qt::AlignCenter);
        sendLabel->setWordWrap(true);

        verticalLayout->addWidget(sendLabel, 0, Qt::AlignHCenter);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton = new QPushButton(FraudDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(150, 0));

        verticalLayout_2->addWidget(pushButton, 0, Qt::AlignHCenter);


        retranslateUi(FraudDialog);
        QObject::connect(pushButton, &QPushButton::clicked, FraudDialog, &QDialog::accept);

        QMetaObject::connectSlotsByName(FraudDialog);
    } // setupUi

    void retranslateUi(QDialog *FraudDialog)
    {
        FraudDialog->setWindowTitle(QCoreApplication::translate("FraudDialog", "Cheating Detected", nullptr));
        oopsLabel->setText(QCoreApplication::translate("FraudDialog", "Oops! You clicked outside of the app window. :(", nullptr));
        sendLabel->setText(QCoreApplication::translate("FraudDialog", "Doing this while the quiz is running will stop the quiz and send the current results.", nullptr));
        pushButton->setText(QCoreApplication::translate("FraudDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FraudDialog: public Ui_FraudDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAUDDIALOG_H
