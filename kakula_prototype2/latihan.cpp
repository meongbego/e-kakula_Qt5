#include "latihan.h"
#include "ui_latihan.h"

Latihan::Latihan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Latihan)
{
    ui->setupUi(this);

}

Latihan::~Latihan()
{
    delete ui;
}
