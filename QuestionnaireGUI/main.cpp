#include <QuestionWindow.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuestionWindow w;
    return a.exec();
}
