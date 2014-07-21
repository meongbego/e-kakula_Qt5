#include "bantuan.h"
#include "ui_bantuan.h"

Bantuan::Bantuan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bantuan)
{
    ui->setupUi(this);
}

Bantuan::~Bantuan()
{
    delete ui;
}
