#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H
#include <QDialog>
#include "secdialog.h"

namespace Ui {
class ThirdDialog;
}

class ThirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdDialog(QWidget *parent = nullptr);
    ~ThirdDialog();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

private:
    Ui::ThirdDialog *ui;
};

#endif // THIRDDIALOG_H
