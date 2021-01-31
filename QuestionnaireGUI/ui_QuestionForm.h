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
    QGroupBox *answerChoiceBox;
    QGridLayout *answerChoiceLayout;
    QLabel *categoryLabel;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *studentNume;
    QLabel *studentPrenume;
    QLabel *unitbvLogo;
    QLabel *miLogo;
    QLabel *timeLabel;
    QLabel *questionNumberLabel;
    QPushButton *helpButton;
    QLabel *questionLabel;

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
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(finishButton->sizePolicy().hasHeightForWidth());
        finishButton->setSizePolicy(sizePolicy1);
        finishButton->setMinimumSize(QSize(40, 40));
        finishButton->setMaximumSize(QSize(40, 40));
        finishButton->setAutoFillBackground(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("images/finishButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        finishButton->setIcon(icon4);
        finishButton->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(finishButton);

        answerChoiceBox = new QGroupBox(centralwidget);
        answerChoiceBox->setObjectName(QString::fromUtf8("answerChoiceBox"));
        answerChoiceBox->setGeometry(QRect(20, 200, 1241, 441));
        QFont font;
        font.setPointSize(13);
        answerChoiceBox->setFont(font);
        answerChoiceBox->setLayoutDirection(Qt::LeftToRight);
        answerChoiceBox->setAlignment(Qt::AlignCenter);
        answerChoiceBox->setCheckable(false);
        answerChoiceLayout = new QGridLayout(answerChoiceBox);
        answerChoiceLayout->setObjectName(QString::fromUtf8("answerChoiceLayout"));
        answerChoiceLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        categoryLabel = new QLabel(centralwidget);
        categoryLabel->setObjectName(QString::fromUtf8("categoryLabel"));
        categoryLabel->setGeometry(QRect(550, 40, 191, 31));
        sizePolicy1.setHeightForWidth(categoryLabel->sizePolicy().hasHeightForWidth());
        categoryLabel->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(12);
        categoryLabel->setFont(font1);
        categoryLabel->setAlignment(Qt::AlignCenter);
        categoryLabel->setWordWrap(true);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(140, 40, 172, 26));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        studentNume = new QLabel(layoutWidget1);
        studentNume->setObjectName(QString::fromUtf8("studentNume"));
        sizePolicy1.setHeightForWidth(studentNume->sizePolicy().hasHeightForWidth());
        studentNume->setSizePolicy(sizePolicy1);
        studentNume->setMaximumSize(QSize(150, 16777215));
        studentNume->setFont(font1);

        horizontalLayout_4->addWidget(studentNume, 0, Qt::AlignVCenter);

        studentPrenume = new QLabel(layoutWidget1);
        studentPrenume->setObjectName(QString::fromUtf8("studentPrenume"));
        sizePolicy1.setHeightForWidth(studentPrenume->sizePolicy().hasHeightForWidth());
        studentPrenume->setSizePolicy(sizePolicy1);
        studentPrenume->setMaximumSize(QSize(150, 16777215));
        studentPrenume->setFont(font1);

        horizontalLayout_4->addWidget(studentPrenume, 0, Qt::AlignVCenter);

        unitbvLogo = new QLabel(centralwidget);
        unitbvLogo->setObjectName(QString::fromUtf8("unitbvLogo"));
        unitbvLogo->setGeometry(QRect(22, 23, 45, 45));
        unitbvLogo->setMaximumSize(QSize(50, 50));
        unitbvLogo->setPixmap(QPixmap(QString::fromUtf8("images/unitbvLogo.png")));
        miLogo = new QLabel(centralwidget);
        miLogo->setObjectName(QString::fromUtf8("miLogo"));
        miLogo->setGeometry(QRect(78, 23, 50, 50));
        miLogo->setMaximumSize(QSize(50, 50));
        miLogo->setPixmap(QPixmap(QString::fromUtf8("images/miLogo.png")));
        miLogo->setScaledContents(true);
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(1000, 30, 161, 41));
        sizePolicy1.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy1);
        timeLabel->setFont(font1);
        timeLabel->setLayoutDirection(Qt::LeftToRight);
        timeLabel->setWordWrap(false);
        questionNumberLabel = new QLabel(centralwidget);
        questionNumberLabel->setObjectName(QString::fromUtf8("questionNumberLabel"));
        questionNumberLabel->setGeometry(QRect(480, 10, 331, 31));
        questionNumberLabel->setFont(font1);
        questionNumberLabel->setAlignment(Qt::AlignCenter);
        helpButton = new QPushButton(centralwidget);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setGeometry(QRect(1217, 23, 45, 45));
        helpButton->setMinimumSize(QSize(45, 45));
        helpButton->setMaximumSize(QSize(45, 45));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        helpButton->setIcon(icon5);
        helpButton->setIconSize(QSize(45, 45));
        questionLabel = new QLabel(centralwidget);
        questionLabel->setObjectName(QString::fromUtf8("questionLabel"));
        questionLabel->setGeometry(QRect(21, 91, 1241, 111));
        sizePolicy1.setHeightForWidth(questionLabel->sizePolicy().hasHeightForWidth());
        questionLabel->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(16);
        questionLabel->setFont(font2);
        questionLabel->setAlignment(Qt::AlignCenter);
        QuestionWindow->setCentralWidget(centralwidget);

        retranslateUi(QuestionWindow);
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
        answerChoiceBox->setTitle(QCoreApplication::translate("QuestionWindow", "Choices", nullptr));
        categoryLabel->setText(QCoreApplication::translate("QuestionWindow", "Category:", nullptr));
        studentNume->setText(QCoreApplication::translate("QuestionWindow", "[Nume]", nullptr));
        studentPrenume->setText(QCoreApplication::translate("QuestionWindow", "[Prenume]", nullptr));
        unitbvLogo->setText(QString());
        miLogo->setText(QString());
        timeLabel->setText(QCoreApplication::translate("QuestionWindow", "Time left: ?", nullptr));
        questionNumberLabel->setText(QCoreApplication::translate("QuestionWindow", "Question: 0/?", nullptr));
        helpButton->setText(QString());
        questionLabel->setText(QCoreApplication::translate("QuestionWindow", "Question", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionWindow: public Ui_QuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONFORM_H
