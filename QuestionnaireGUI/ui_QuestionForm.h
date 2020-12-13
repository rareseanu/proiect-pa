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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionWindow
{
public:
    QWidget *centralwidget;
    QLabel *questionNumber;
    QLabel *questionLabel;
    QFrame *choicesFrame;
    QGridLayout *gridLayout;
    QWidget *widget;
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
        questionNumber = new QLabel(centralwidget);
        questionNumber->setObjectName(QString::fromUtf8("questionNumber"));
        questionNumber->setGeometry(QRect(9, 9, 116, 27));
        questionNumber->setMaximumSize(QSize(200, 30));
        QFont font;
        font.setPointSize(15);
        questionNumber->setFont(font);
        questionNumber->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        questionNumber->setWordWrap(true);
        questionLabel = new QLabel(centralwidget);
        questionLabel->setObjectName(QString::fromUtf8("questionLabel"));
        questionLabel->setGeometry(QRect(10, 40, 781, 100));
        questionLabel->setMaximumSize(QSize(16777215, 100));
        QFont font1;
        font1.setPointSize(27);
        questionLabel->setFont(font1);
        questionLabel->setAlignment(Qt::AlignCenter);
        questionLabel->setWordWrap(true);
        choicesFrame = new QFrame(centralwidget);
        choicesFrame->setObjectName(QString::fromUtf8("choicesFrame"));
        choicesFrame->setEnabled(true);
        choicesFrame->setGeometry(QRect(0, 150, 801, 591));
        choicesFrame->setFrameShape(QFrame::StyledPanel);
        choicesFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(choicesFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 760, 781, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        nextQuestionButton = new QPushButton(widget);
        nextQuestionButton->setObjectName(QString::fromUtf8("nextQuestionButton"));

        horizontalLayout->addWidget(nextQuestionButton);

        finishButton = new QPushButton(widget);
        finishButton->setObjectName(QString::fromUtf8("finishButton"));

        horizontalLayout->addWidget(finishButton);

        QuestionWindow->setCentralWidget(centralwidget);

        retranslateUi(QuestionWindow);

        QMetaObject::connectSlotsByName(QuestionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QuestionWindow)
    {
        QuestionWindow->setWindowTitle(QCoreApplication::translate("QuestionWindow", "Questionnaire", nullptr));
        questionNumber->setText(QCoreApplication::translate("QuestionWindow", "Question: 0/?", nullptr));
        questionLabel->setText(QCoreApplication::translate("QuestionWindow", "Question", nullptr));
        nextQuestionButton->setText(QCoreApplication::translate("QuestionWindow", "Next", nullptr));
        finishButton->setText(QCoreApplication::translate("QuestionWindow", "Finish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionWindow: public Ui_QuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONFORM_H
