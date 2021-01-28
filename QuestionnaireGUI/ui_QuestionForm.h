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
    QGroupBox *answerChoiceBox;
    QGridLayout *answerChoiceLayout;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *unitbvLogo;
    QLabel *miLogo;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *studentNume;
    QLabel *studentPrenume;
    QLabel *questionNumberLabel;
    QLabel *timeLabel;
    QPushButton *calculatorButton;
    QPushButton *helpButton;

    void setupUi(QMainWindow *QuestionWindow)
    {
        if (QuestionWindow->objectName().isEmpty())
            QuestionWindow->setObjectName(QString::fromUtf8("QuestionWindow"));
        QuestionWindow->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QuestionWindow->sizePolicy().hasHeightForWidth());
        QuestionWindow->setSizePolicy(sizePolicy);
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
        layoutWidget->setGeometry(QRect(20, 660, 1241, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setMinimumSize(QSize(40, 40));
        backButton->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/backButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon1);
        backButton->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(backButton);

        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setMinimumSize(QSize(40, 40));
        clearButton->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/clearButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon2);
        clearButton->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(clearButton);

        nextButton = new QPushButton(layoutWidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setMinimumSize(QSize(40, 40));
        nextButton->setMaximumSize(QSize(40, 40));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("images/nextButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon3);
        nextButton->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(nextButton);

        finishButton = new QPushButton(layoutWidget);
        finishButton->setObjectName(QString::fromUtf8("finishButton"));
        finishButton->setMinimumSize(QSize(40, 40));
        finishButton->setMaximumSize(QSize(40, 40));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("images/finishButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        finishButton->setIcon(icon4);
        finishButton->setIconSize(QSize(40, 40));

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

        answerChoiceBox = new QGroupBox(centralwidget);
        answerChoiceBox->setObjectName(QString::fromUtf8("answerChoiceBox"));
        answerChoiceBox->setGeometry(QRect(20, 200, 1241, 441));
        QFont font1;
        font1.setPointSize(13);
        answerChoiceBox->setFont(font1);
        answerChoiceBox->setLayoutDirection(Qt::LeftToRight);
        answerChoiceBox->setAlignment(Qt::AlignCenter);
        answerChoiceBox->setCheckable(false);
        answerChoiceLayout = new QGridLayout(answerChoiceBox);
        answerChoiceLayout->setObjectName(QString::fromUtf8("answerChoiceLayout"));
        answerChoiceLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 20, 1241, 63));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        unitbvLogo = new QLabel(layoutWidget2);
        unitbvLogo->setObjectName(QString::fromUtf8("unitbvLogo"));
        unitbvLogo->setMaximumSize(QSize(50, 50));
        unitbvLogo->setPixmap(QPixmap(QString::fromUtf8("images/unitbvLogo.png")));

        horizontalLayout_3->addWidget(unitbvLogo);

        miLogo = new QLabel(layoutWidget2);
        miLogo->setObjectName(QString::fromUtf8("miLogo"));
        miLogo->setMaximumSize(QSize(50, 50));
        miLogo->setPixmap(QPixmap(QString::fromUtf8("images/miLogo.png")));

        horizontalLayout_3->addWidget(miLogo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(0);
        studentNume = new QLabel(layoutWidget2);
        studentNume->setObjectName(QString::fromUtf8("studentNume"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(studentNume->sizePolicy().hasHeightForWidth());
        studentNume->setSizePolicy(sizePolicy1);
        studentNume->setMaximumSize(QSize(150, 16777215));
        QFont font2;
        font2.setPointSize(12);
        studentNume->setFont(font2);

        gridLayout->addWidget(studentNume, 0, 0, 1, 1, Qt::AlignLeft);

        studentPrenume = new QLabel(layoutWidget2);
        studentPrenume->setObjectName(QString::fromUtf8("studentPrenume"));
        sizePolicy1.setHeightForWidth(studentPrenume->sizePolicy().hasHeightForWidth());
        studentPrenume->setSizePolicy(sizePolicy1);
        studentPrenume->setMaximumSize(QSize(150, 16777215));
        studentPrenume->setFont(font2);

        gridLayout->addWidget(studentPrenume, 0, 1, 1, 1, Qt::AlignLeft);


        horizontalLayout_2->addLayout(gridLayout);

        questionNumberLabel = new QLabel(layoutWidget2);
        questionNumberLabel->setObjectName(QString::fromUtf8("questionNumberLabel"));
        questionNumberLabel->setFont(font2);
        questionNumberLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(questionNumberLabel);

        timeLabel = new QLabel(layoutWidget2);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setFont(font2);
        timeLabel->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(timeLabel);

        calculatorButton = new QPushButton(layoutWidget2);
        calculatorButton->setObjectName(QString::fromUtf8("calculatorButton"));
        calculatorButton->setMinimumSize(QSize(39, 50));
        calculatorButton->setMaximumSize(QSize(39, 50));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("images/calculator.png"), QSize(), QIcon::Normal, QIcon::Off);
        calculatorButton->setIcon(icon5);
        calculatorButton->setIconSize(QSize(50, 49));

        horizontalLayout_2->addWidget(calculatorButton);

        helpButton = new QPushButton(layoutWidget2);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setMinimumSize(QSize(45, 45));
        helpButton->setMaximumSize(QSize(45, 45));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        helpButton->setIcon(icon6);
        helpButton->setIconSize(QSize(45, 45));

        horizontalLayout_2->addWidget(helpButton);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        QuestionWindow->setCentralWidget(centralwidget);

        retranslateUi(QuestionWindow);
        QObject::connect(calculatorButton, SIGNAL(clicked()), QuestionWindow, SLOT(LaunchCalculatorButtonClicked()));
        QObject::connect(helpButton, SIGNAL(clicked()), QuestionWindow, SLOT(HelpButtonClicked()));

        QMetaObject::connectSlotsByName(QuestionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QuestionWindow)
    {
        QuestionWindow->setWindowTitle(QCoreApplication::translate("QuestionWindow", "Questionnaire", nullptr));
        backButton->setText(QString());
        clearButton->setText(QString());
        nextButton->setText(QString());
        finishButton->setText(QString());
        questionLabel->setText(QCoreApplication::translate("QuestionWindow", "Question", nullptr));
        answerChoiceBox->setTitle(QCoreApplication::translate("QuestionWindow", "Choices", nullptr));
        unitbvLogo->setText(QString());
        miLogo->setText(QString());
        studentNume->setText(QCoreApplication::translate("QuestionWindow", "[Nume]", nullptr));
        studentPrenume->setText(QCoreApplication::translate("QuestionWindow", "[Prenume]", nullptr));
        questionNumberLabel->setText(QCoreApplication::translate("QuestionWindow", "Question: 0/?", nullptr));
        timeLabel->setText(QCoreApplication::translate("QuestionWindow", "Time left: ?", nullptr));
        calculatorButton->setText(QString());
        helpButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QuestionWindow: public Ui_QuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONFORM_H
