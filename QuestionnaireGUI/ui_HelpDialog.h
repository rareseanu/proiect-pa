/********************************************************************************
** Form generated from reading UI file 'HelpDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QLabel *calculatorIconLabel;
    QLabel *calculatorInfoLabel;
    QLabel *previousIconLabel;
    QLabel *clearIconLabel;
    QLabel *nextIconLabel;
    QLabel *finishIconLabel;
    QLabel *previousInfoLabel;
    QLabel *clearInfoLabel;
    QLabel *nextInfoLabel;
    QLabel *finishInfoLabel;
    QLabel *buttonsLabel;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName(QString::fromUtf8("HelpDialog"));
        HelpDialog->resize(550, 500);
        HelpDialog->setMinimumSize(QSize(550, 500));
        HelpDialog->setMaximumSize(QSize(550, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        HelpDialog->setWindowIcon(icon);
        calculatorIconLabel = new QLabel(HelpDialog);
        calculatorIconLabel->setObjectName(QString::fromUtf8("calculatorIconLabel"));
        calculatorIconLabel->setGeometry(QRect(170, 120, 41, 39));
        calculatorIconLabel->setMinimumSize(QSize(20, 39));
        calculatorIconLabel->setPixmap(QPixmap(QString::fromUtf8("images/calculator.png")));
        calculatorIconLabel->setScaledContents(true);
        calculatorInfoLabel = new QLabel(HelpDialog);
        calculatorInfoLabel->setObjectName(QString::fromUtf8("calculatorInfoLabel"));
        calculatorInfoLabel->setGeometry(QRect(220, 130, 211, 21));
        previousIconLabel = new QLabel(HelpDialog);
        previousIconLabel->setObjectName(QString::fromUtf8("previousIconLabel"));
        previousIconLabel->setGeometry(QRect(170, 180, 41, 41));
        previousIconLabel->setPixmap(QPixmap(QString::fromUtf8("images/backButton.png")));
        previousIconLabel->setScaledContents(true);
        clearIconLabel = new QLabel(HelpDialog);
        clearIconLabel->setObjectName(QString::fromUtf8("clearIconLabel"));
        clearIconLabel->setGeometry(QRect(170, 240, 41, 41));
        clearIconLabel->setPixmap(QPixmap(QString::fromUtf8("images/clearButton.png")));
        clearIconLabel->setScaledContents(true);
        nextIconLabel = new QLabel(HelpDialog);
        nextIconLabel->setObjectName(QString::fromUtf8("nextIconLabel"));
        nextIconLabel->setGeometry(QRect(170, 300, 41, 41));
        nextIconLabel->setPixmap(QPixmap(QString::fromUtf8("images/nextButton.png")));
        nextIconLabel->setScaledContents(true);
        finishIconLabel = new QLabel(HelpDialog);
        finishIconLabel->setObjectName(QString::fromUtf8("finishIconLabel"));
        finishIconLabel->setGeometry(QRect(170, 360, 41, 41));
        finishIconLabel->setPixmap(QPixmap(QString::fromUtf8("images/finishButton.png")));
        finishIconLabel->setScaledContents(true);
        previousInfoLabel = new QLabel(HelpDialog);
        previousInfoLabel->setObjectName(QString::fromUtf8("previousInfoLabel"));
        previousInfoLabel->setGeometry(QRect(220, 190, 161, 21));
        clearInfoLabel = new QLabel(HelpDialog);
        clearInfoLabel->setObjectName(QString::fromUtf8("clearInfoLabel"));
        clearInfoLabel->setGeometry(QRect(220, 250, 111, 21));
        nextInfoLabel = new QLabel(HelpDialog);
        nextInfoLabel->setObjectName(QString::fromUtf8("nextInfoLabel"));
        nextInfoLabel->setGeometry(QRect(220, 310, 121, 21));
        finishInfoLabel = new QLabel(HelpDialog);
        finishInfoLabel->setObjectName(QString::fromUtf8("finishInfoLabel"));
        finishInfoLabel->setGeometry(QRect(220, 370, 101, 21));
        buttonsLabel = new QLabel(HelpDialog);
        buttonsLabel->setObjectName(QString::fromUtf8("buttonsLabel"));
        buttonsLabel->setGeometry(QRect(130, 60, 301, 31));

        retranslateUi(HelpDialog);

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QCoreApplication::translate("HelpDialog", "Help", nullptr));
        calculatorIconLabel->setText(QString());
        calculatorInfoLabel->setText(QCoreApplication::translate("HelpDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">- launches a calculator.</span></p></body></html>", nullptr));
        previousIconLabel->setText(QString());
        clearIconLabel->setText(QString());
        nextIconLabel->setText(QString());
        finishIconLabel->setText(QString());
        previousInfoLabel->setText(QCoreApplication::translate("HelpDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">- previous question.</span></p></body></html>", nullptr));
        clearInfoLabel->setText(QCoreApplication::translate("HelpDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">- clear choice.</span></p></body></html>", nullptr));
        nextInfoLabel->setText(QCoreApplication::translate("HelpDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">- next question.</span></p></body></html>", nullptr));
        finishInfoLabel->setText(QCoreApplication::translate("HelpDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">- finish quiz.</span></p></body></html>", nullptr));
        buttonsLabel->setText(QCoreApplication::translate("HelpDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">Buttons on the question window:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
