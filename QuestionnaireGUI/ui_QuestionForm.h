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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *clearButton;
    QPushButton *nextButton;
    QPushButton *finishButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *unitbvLogo;
    QLabel *miLogo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *studentLogo;
    QLabel *questionNumbeLabel;
    QLabel *timeLabel;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *questionLabel;
    QLabel *answerLabel;

    void setupUi(QMainWindow *QuestionWindow)
    {
        if (QuestionWindow->objectName().isEmpty())
            QuestionWindow->setObjectName(QString::fromUtf8("QuestionWindow"));
        QuestionWindow->resize(770, 499);
        QuestionWindow->setMinimumSize(QSize(600, 400));
        QuestionWindow->setMaximumSize(QSize(800, 800));
        centralwidget = new QWidget(QuestionWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(800, 800));
        centralwidget->setMaximumSize(QSize(800, 800));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 440, 671, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout->addWidget(clearButton);

        nextButton = new QPushButton(layoutWidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        horizontalLayout->addWidget(nextButton);

        finishButton = new QPushButton(layoutWidget);
        finishButton->setObjectName(QString::fromUtf8("finishButton"));

        horizontalLayout->addWidget(finishButton);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 537, 54));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        unitbvLogo = new QLabel(widget);
        unitbvLogo->setObjectName(QString::fromUtf8("unitbvLogo"));
        unitbvLogo->setPixmap(QPixmap(QString::fromUtf8("unitbvLogo.png")));

        horizontalLayout_3->addWidget(unitbvLogo);

        miLogo = new QLabel(widget);
        miLogo->setObjectName(QString::fromUtf8("miLogo"));
        miLogo->setPixmap(QPixmap(QString::fromUtf8("miLogo.png")));

        horizontalLayout_3->addWidget(miLogo);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        studentLogo = new QLabel(widget);
        studentLogo->setObjectName(QString::fromUtf8("studentLogo"));

        horizontalLayout_2->addWidget(studentLogo);

        questionNumbeLabel = new QLabel(widget);
        questionNumbeLabel->setObjectName(QString::fromUtf8("questionNumbeLabel"));

        horizontalLayout_2->addWidget(questionNumbeLabel);

        timeLabel = new QLabel(widget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        horizontalLayout_2->addWidget(timeLabel);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(340, 130, 75, 44));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        questionLabel = new QLabel(widget1);
        questionLabel->setObjectName(QString::fromUtf8("questionLabel"));

        verticalLayout->addWidget(questionLabel);

        answerLabel = new QLabel(widget1);
        answerLabel->setObjectName(QString::fromUtf8("answerLabel"));

        verticalLayout->addWidget(answerLabel);

        QuestionWindow->setCentralWidget(centralwidget);

        retranslateUi(QuestionWindow);

        QMetaObject::connectSlotsByName(QuestionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QuestionWindow)
    {
        QuestionWindow->setWindowTitle(QCoreApplication::translate("QuestionWindow", "Questionnaire", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QuestionWindow", "Back", nullptr));
        clearButton->setText(QCoreApplication::translate("QuestionWindow", "Clear Choice", nullptr));
        nextButton->setText(QCoreApplication::translate("QuestionWindow", "Next", nullptr));
        finishButton->setText(QCoreApplication::translate("QuestionWindow", "Finish Quiz", nullptr));
        unitbvLogo->setText(QString());
        miLogo->setText(QString());
        studentLogo->setText(QCoreApplication::translate("QuestionWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Student: [first name] [last name]</span></p></body></html>", nullptr));
        questionNumbeLabel->setText(QCoreApplication::translate("QuestionWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Question: 0/?</span></p></body></html>", nullptr));
        timeLabel->setText(QCoreApplication::translate("QuestionWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Time left: ?</span></p></body></html>", nullptr));
        questionLabel->setText(QCoreApplication::translate("QuestionWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Question</span></p></body></html>", nullptr));
        answerLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QuestionWindow: public Ui_QuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONFORM_H
