#ifndef EMPTYNAMEDIALOG_H
#define EMPTYNAMEDIALOG_H

#include <QDialog>

namespace Ui {
class EmptyNameDialog;
}

class EmptyNameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmptyNameDialog(QWidget *parent = nullptr);
    ~EmptyNameDialog();

private:
    Ui::EmptyNameDialog *ui;
};

#endif // EMPTYNAMEDIALOG_H
