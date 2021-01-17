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
#include <QtGui/QIcon>
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
        FinishDialog->resize(354, 138);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FinishDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(FinishDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(FinishDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(FinishDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        verticalLayout->addWidget(buttonBox, 0, Qt::AlignHCenter);


        retranslateUi(FinishDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, FinishDialog, &QDialog::reject);
        QObject::connect(buttonBox, &QDialogButtonBox::clicked, FinishDialog, &QDialog::accept);
        QObject::connect(buttonBox, SIGNAL(accepted()), FinishDialog, SLOT(onOkButtonClicked()));

        QMetaObject::connectSlotsByName(FinishDialog);
    } // setupUi

    void retranslateUi(QDialog *FinishDialog)
    {
        FinishDialog->setWindowTitle(QCoreApplication::translate("FinishDialog", "Confirm", nullptr));
        label->setText(QCoreApplication::translate("FinishDialog", "Send the results?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinishDialog: public Ui_FinishDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINISHDIALOG_H
