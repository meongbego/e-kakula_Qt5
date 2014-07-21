#ifndef MENUKAKULA_H
#define MENUKAKULA_H

#include <QWidget>
#include <QMessageBox>
#include "nastyfft.h"
#include "settingsdialog.h"
#include "mediamusic.h"
#include "menudialog.h"
#include <QKeyEvent>

namespace Ui {
class MenuKakula;
}

class MenuKakula : public QWidget
{
    Q_OBJECT

public:
    explicit MenuKakula(QWidget *parent = 0);
    virtual void resizeEvent(QResizeEvent *);
    ~MenuKakula();
    NastyFFT* glView();

public slots:
    void showSettings();

private slots:
    void on_comboVisualisasi_activated(int index);

    void on_btnG1_clicked();

    void on_btnG2_clicked();

    void on_btnG3_clicked();

    void on_btnG4_clicked();

    void on_btnG5_clicked();

    void on_btnG6_clicked();

    void on_btnG7_clicked();

    void on_comboMode_activated(int index);

    void on_volSlider_sliderMoved(int position);

    void keyPressEvent(QKeyEvent *e);

    void on_menuHide_clicked();

    void on_menuShow_clicked();

private:
    Ui::MenuKakula *ui;
    NastyFFT *plugin;
    SettingsDialog *wInSetting;
    MediaMusic *media;
    MenuDialog *wmenudialog;

    int volume;
    QString mode;
};

#endif // MENUKAKULA_H
