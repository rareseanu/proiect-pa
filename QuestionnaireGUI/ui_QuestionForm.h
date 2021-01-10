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
#include <QtWidgets/QGroupBox>
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
    QPushButton *backButton;
    QPushButton *clearButton;
    QPushButton *nextButton;
    QPushButton *finishButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *questionLabel;
    QLabel *unitbvLogo;
    QLabel *miLogo;
    QLabel *timeLabel;
    QLabel *questionNumberLabel;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *studentNume;
    QLabel *studentPrenume;
    QGroupBox *answerChoiceBox;
    QGridLayout *answerChoiceLayout;

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
        layoutWidget->setGeometry(QRect(20, 660, 1241, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout->addWidget(backButton);

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
        layoutWidget1->setGeometry(QRect(20, 90, 1241, 82));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        questionLabel = new QLabel(layoutWidget1);
        questionLabel->setObjectName(QString::fromUtf8("questionLabel"));
        QFont font;
        font.setPointSize(16);
        questionLabel->setFont(font);
        questionLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(questionLabel);

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
        timeLabel->setGeometry(QRect(1100, 10, 161, 51));
        QFont font1;
        font1.setPointSize(12);
        timeLabel->setFont(font1);
        timeLabel->setLayoutDirection(Qt::LeftToRight);
        questionNumberLabel = new QLabel(centralwidget);
        questionNumberLabel->setObjectName(QString::fromUtf8("questionNumberLabel"));
        questionNumberLabel->setGeometry(QRect(501, 30, 291, 22));
        questionNumberLabel->setFont(font1);
        questionNumberLabel->setAlignment(Qt::AlignCenter);
        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(129, 13, 151, 51));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        studentNume = new QLabel(layoutWidget2);
        studentNume->setObjectName(QString::fromUtf8("studentNume"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(studentNume->sizePolicy().hasHeightForWidth());
        studentNume->setSizePolicy(sizePolicy);
        studentNume->setFont(font1);

        gridLayout->addWidget(studentNume, 0, 0, 1, 1);

        studentPrenume = new QLabel(layoutWidget2);
        studentPrenume->setObjectName(QString::fromUtf8("studentPrenume"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(studentPrenume->sizePolicy().hasHeightForWidth());
        studentPrenume->setSizePolicy(sizePolicy1);
        studentPrenume->setFont(font1);

        gridLayout->addWidget(studentPrenume, 0, 1, 1, 1);

        answerChoiceBox = new QGroupBox(centralwidget);
        answerChoiceBox->setObjectName(QString::fromUtf8("answerChoiceBox"));
        answerChoiceBox->setGeometry(QRect(20, 200, 1241, 441));
        QFont font2;
        font2.setPointSize(13);
        answerChoiceBox->setFont(font2);
        answerChoiceBox->setLayoutDirection(Qt::LeftToRight);
        answerChoiceBox->setAlignment(Qt::AlignCenter);
        answerChoiceBox->setCheckable(false);
        answerChoiceLayout = new QGridLayout(answerChoiceBox);
        answerChoiceLayout->setObjectName(QString::fromUtf8("answerChoiceLayout"));
        answerChoiceLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        QuestionWindow->setCentralWidget(centralwidget);

        retranslateUi(QuestionWindow);

        QMetaObject::connectSlotsByName(QuestionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QuestionWindow)
    {
        QuestionWindow->setWindowTitle(QCoreApplication::translate("QuestionWindow", "Questionnaire", nullptr));
        backButton->setText(QCoreApplication::translate("QuestionWindow", "Back", nullptr));
        clearButton->setText(QCoreApplication::translate("QuestionWindow", "Clear Choice", nullptr));
        nextButton->setText(QCoreApplication::translate("QuestionWindow", "Next", nullptr));
        finishButton->setText(QCoreApplication::translate("QuestionWindow", "Finish Quiz", nullptr));
        questionLabel->setText(QCoreApplication::translate("QuestionWindow", "Question", nullptr));
        unitbvLogo->setText(QString());
        miLogo->setText(QString());
        timeLabel->setText(QCoreApplication::translate("QuestionWindow", "Time left: ?", nullptr));
        questionNumberLabel->setText(QCoreApplication::translate("QuestionWindow", "Question: 0/?", nullptr));
        studentNume->setText(QCoreApplication::translate("QuestionWindow", "[Nume]", nullptr));
        studentPrenume->setText(QCoreApplication::translate("QuestionWindow", "[Prenume]", nullptr));
        answerChoiceBox->setTitle(QCoreApplication::translate("QuestionWindow", "Choices", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionWindow: public Ui_QuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONFORM_H
