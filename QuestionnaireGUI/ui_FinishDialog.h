/********************************************************************************
** Form generated from reading UI file 'FinishDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINISHDIALOG_H
#define UI_FINISHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FinishDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FinishDialog)
    {
        if (FinishDialog->objectName().isEmpty())
            FinishDialog->setObjectName(QString::fromUtf8("FinishDialog"));
        FinishDialog->resize(284, 138);
        verticalLayout = new QVBoxLayout(FinishDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(FinishDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(FinishDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(FinishDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, FinishDialog, &QDialog::accept);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, FinishDialog, &QDialog::reject);

        QMetaObject::connectSlotsByName(FinishDialog);
    } // setupUi

    void retranslateUi(QDialog *FinishDialog)
    {
        FinishDialog->setWindowTitle(QCoreApplication::translate("FinishDialog", "Confirm", nullptr));
        label->setText(QCoreApplication::translate("FinishDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Are you sure you want to finish the quiz and </span></p><p align=\"center\"><span style=\" font-size:10pt;\">send the results?</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinishDialog: public Ui_FinishDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINISHDIALOG_H
