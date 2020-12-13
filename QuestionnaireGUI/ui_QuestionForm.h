/********************************************************************************
** Form generated from reading UI file 'QuestionForm.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONFORM_H
#define UI_QUESTIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *answerGrid;
    QHBoxLayout *horizontalLayout;
    QPushButton *nextQuestionButton;
    QPushButton *finishButton;

    void setupUi(QMainWindow *QuestionWindow)
    {
        if (QuestionWindow->objectName().isEmpty())
            QuestionWindow->setObjectName(QString::fromUtf8("QuestionWindow"));
        QuestionWindow->resize(800, 800);
        QuestionWindow->setMinimumSize(QSize(800, 800));
        QuestionWindow->setMaximumSize(QSize(800, 800));
        centralwidget = new QWidget(QuestionWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(800, 800));
        centralwidget->setMaximumSize(QSize(800, 800));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(-1, -1, -1, 9);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 300));
        QFont font;
        font.setPointSize(27);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        answerGrid = new QGridLayout();
        answerGrid->setObjectName(QString::fromUtf8("answerGrid"));

        verticalLayout->addLayout(answerGrid);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        nextQuestionButton = new QPushButton(centralwidget);
        nextQuestionButton->setObjectName(QString::fromUtf8("nextQuestionButton"));

        horizontalLayout->addWidget(nextQuestionButton);

        finishButton = new QPushButton(centralwidget);
        finishButton->setObjectName(QString::fromUtf8("finishButton"));

        horizontalLayout->addWidget(finishButton);


        verticalLayout->addLayout(horizontalLayout);

        QuestionWindow->setCentralWidget(centralwidget);

        retranslateUi(QuestionWindow);

        QMetaObject::connectSlotsByName(QuestionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QuestionWindow)
    {
        QuestionWindow->setWindowTitle(QCoreApplication::translate("QuestionWindow", "Questionnaire", nullptr));
        label->setText(QCoreApplication::translate("QuestionWindow", "Question", nullptr));
        nextQuestionButton->setText(QCoreApplication::translate("QuestionWindow", "Next", nullptr));
        finishButton->setText(QCoreApplication::translate("QuestionWindow", "Finish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionWindow: public Ui_QuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONFORM_H
