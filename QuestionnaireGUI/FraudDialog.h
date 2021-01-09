#ifndef FRAUDDIALOG_H
#define FRAUDDIALOG_H

#include <QDialog>

namespace Ui {
class FraudDialog;
}

class FraudDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FraudDialog(QWidget *parent = nullptr);
    ~FraudDialog();

private:
    Ui::FraudDialog *ui;
};

#endif // FRAUDDIALOG_H
