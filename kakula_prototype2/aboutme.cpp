#include "aboutme.h"
#include "ui_aboutme.h"

AboutMe::AboutMe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutMe)
{
    ui->setupUi(this);
    this->ui->textEdit->hide();
}

AboutMe::~AboutMe()
{
    delete ui;
}

void AboutMe::on_checkBox_toggled(bool checked)
{
    if (!checked){
        this->ui->textEdit->hide();
    }
    else {
        this->ui->textEdit->show();
    }
}
