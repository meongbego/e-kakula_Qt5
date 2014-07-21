#include "menudialog.h"
#include "ui_menudialog.h"

MenuDialog::MenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuDialog)
{
    ui->setupUi(this);
}

MenuDialog::~MenuDialog()
{
    delete ui;
}

void MenuDialog::on_pushButton_3_clicked()
{
    latihan = new Latihan;
    latihan->exec();
}

void MenuDialog::on_pushButton_2_clicked()
{
    bantuan = new Bantuan;
    bantuan->exec();
}

void MenuDialog::on_pushButton_clicked()
{
    about = new AboutMe;
    about->exec();
}
