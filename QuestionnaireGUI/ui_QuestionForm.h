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
#include <QtWidgets/QSpacerItem>
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
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *unitbvLogo;
    QLabel *miLogo;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *studentNume;
    QLabel *studentPrenume;
    QSpacerItem *horizontalSpacer;
    QLabel *questionNumeLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *timeLabel;
    QWidget *layoutWidget2;
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

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 617, 54));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        unitbvLogo = new QLabel(layoutWidget1);
        unitbvLogo->setObjectName(QString::fromUtf8("unitbvLogo"));
        unitbvLogo->setMaximumSize(QSize(50, 50));
        unitbvLogo->setPixmap(QPixmap(QString::fromUtf8("images/unitbvLogo.png")));

        horizontalLayout_3->addWidget(unitbvLogo);

        miLogo = new QLabel(layoutWidget1);
        miLogo->setObjectName(QString::fromUtf8("miLogo"));
        miLogo->setMaximumSize(QSize(50, 50));
        miLogo->setPixmap(QPixmap(QString::fromUtf8("images/miLogo.png")));

        horizontalLayout_3->addWidget(miLogo);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        studentNume = new QLabel(layoutWidget1);
        studentNume->setObjectName(QString::fromUtf8("studentNume"));
        QFont font;
        font.setPointSize(12);
        studentNume->setFont(font);

        horizontalLayout_5->addWidget(studentNume);

        studentPrenume = new QLabel(layoutWidget1);
        studentPrenume->setObjectName(QString::fromUtf8("studentPrenume"));
        studentPrenume->setFont(font);

        horizontalLayout_5->addWidget(studentPrenume);


        horizontalLayout_2->addLayout(horizontalLayout_5);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        questionNumeLabel = new QLabel(layoutWidget1);
        questionNumeLabel->setObjectName(QString::fromUtf8("questionNumeLabel"));
        questionNumeLabel->setFont(font);

        horizontalLayout_2->addWidget(questionNumeLabel);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        timeLabel = new QLabel(layoutWidget1);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setFont(font);
        timeLabel->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(timeLabel);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(340, 130, 78, 50));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        questionLabel = new QLabel(layoutWidget2);
        questionLabel->setObjectName(QString::fromUtf8("questionLabel"));

        verticalLayout->addWidget(questionLabel);

        answerLabel = new QLabel(layoutWidget2);
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
        studentNume->setText(QCoreApplication::translate("QuestionWindow", "[Nume]", nullptr));
        studentPrenume->setText(QCoreApplication::translate("QuestionWindow", "[Prenume]", nullptr));
        questionNumeLabel->setText(QCoreApplication::translate("QuestionWindow", "Question: 0/?", nullptr));
        timeLabel->setText(QCoreApplication::translate("QuestionWindow", "Time left: ?", nullptr));
        questionLabel->setText(QCoreApplication::translate("QuestionWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Question</span></p></body></html>", nullptr));
        answerLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QuestionWindow: public Ui_QuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONFORM_H
