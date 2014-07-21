#ifndef MENUDIALOG_H
#define MENUDIALOG_H

#include <QDialog>
#include "latihan.h"
#include "bantuan.h"
#include "aboutme.h"

namespace Ui {
class MenuDialog;
}

class MenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MenuDialog(QWidget *parent = 0);
    ~MenuDialog();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MenuDialog *ui;
    Latihan *latihan;
    Bantuan *bantuan;
    AboutMe *about;
};

#endif // MENUDIALOG_H
