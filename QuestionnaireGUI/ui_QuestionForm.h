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
#include <QtGui/QIcon>
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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *clearButton;
    QPushButton *nextButton;
    QPushButton *finishButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *questionLabel;
    QLabel *answerLabel;
    QLabel *unitbvLogo;
    QLabel *miLogo;
    QLabel *timeLabel;
    QLabel *questionNumeLabel;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *studentNume;
    QLabel *studentPrenume;

    void setupUi(QMainWindow *QuestionWindow)
    {
        if (QuestionWindow->objectName().isEmpty())
            QuestionWindow->setObjectName(QString::fromUtf8("QuestionWindow"));
        QuestionWindow->resize(1280, 720);
        QuestionWindow->setMinimumSize(QSize(1280, 720));
        QuestionWindow->setMaximumSize(QSize(1280, 720));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        QuestionWindow->setWindowIcon(icon);
        centralwidget = new QWidget(QuestionWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(1280, 720));
        centralwidget->setMaximumSize(QSize(1280, 720));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(340, 660, 671, 31));
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
        layoutWidget1->setGeometry(QRect(570, 90, 151, 71));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        questionLabel = new QLabel(layoutWidget1);
        questionLabel->setObjectName(QString::fromUtf8("questionLabel"));

        verticalLayout->addWidget(questionLabel);

        answerLabel = new QLabel(layoutWidget1);
        answerLabel->setObjectName(QString::fromUtf8("answerLabel"));

        verticalLayout->addWidget(answerLabel);

        unitbvLogo = new QLabel(centralwidget);
        unitbvLogo->setObjectName(QString::fromUtf8("unitbvLogo"));
        unitbvLogo->setGeometry(QRect(22, 12, 45, 45));
        unitbvLogo->setMaximumSize(QSize(50, 50));
        unitbvLogo->setPixmap(QPixmap(QString::fromUtf8("images/unitbvLogo.png")));
        miLogo = new QLabel(centralwidget);
        miLogo->setObjectName(QString::fromUtf8("miLogo"));
        miLogo->setGeometry(QRect(73, 12, 50, 50));
        miLogo->setMaximumSize(QSize(50, 50));
        miLogo->setPixmap(QPixmap(QString::fromUtf8("images/miLogo.png")));
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(1140, 30, 74, 22));
        QFont font;
        font.setPointSize(12);
        timeLabel->setFont(font);
        timeLabel->setLayoutDirection(Qt::LeftToRight);
        questionNumeLabel = new QLabel(centralwidget);
        questionNumeLabel->setObjectName(QString::fromUtf8("questionNumeLabel"));
        questionNumeLabel->setGeometry(QRect(600, 30, 92, 22));
        questionNumeLabel->setFont(font);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(129, 13, 151, 51));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        studentNume = new QLabel(widget);
        studentNume->setObjectName(QString::fromUtf8("studentNume"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(studentNume->sizePolicy().hasHeightForWidth());
        studentNume->setSizePolicy(sizePolicy);
        studentNume->setFont(font);

        gridLayout->addWidget(studentNume, 0, 0, 1, 1);

        studentPrenume = new QLabel(widget);
        studentPrenume->setObjectName(QString::fromUtf8("studentPrenume"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(studentPrenume->sizePolicy().hasHeightForWidth());
        studentPrenume->setSizePolicy(sizePolicy1);
        studentPrenume->setFont(font);

        gridLayout->addWidget(studentPrenume, 0, 1, 1, 1);

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
        questionLabel->setText(QCoreApplication::translate("QuestionWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Question</span></p></body></html>", nullptr));
        answerLabel->setText(QString());
        unitbvLogo->setText(QString());
        miLogo->setText(QString());
        timeLabel->setText(QCoreApplication::translate("QuestionWindow", "Time left: ?", nullptr));
        questionNumeLabel->setText(QCoreApplication::translate("QuestionWindow", "Question: 0/?", nullptr));
        studentNume->setText(QCoreApplication::translate("QuestionWindow", "[Nume]", nullptr));
        studentPrenume->setText(QCoreApplication::translate("QuestionWindow", "[Prenume]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionWindow: public Ui_QuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONFORM_H
