#ifndef BANTUAN_H
#define BANTUAN_H

#include <QDialog>

namespace Ui {
class Bantuan;
}

class Bantuan : public QDialog
{
    Q_OBJECT

public:
    explicit Bantuan(QWidget *parent = 0);
    ~Bantuan();

private:
    Ui::Bantuan *ui;
};

#endif // BANTUAN_H
