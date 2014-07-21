#ifndef LATIHAN_H
#define LATIHAN_H

#include <QDialog>

namespace Ui {
class Latihan;
}

class Latihan : public QDialog
{
    Q_OBJECT

public:
    explicit Latihan(QWidget *parent = 0);
    ~Latihan();

private:
    Ui::Latihan *ui;
};

#endif // LATIHAN_H
