#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "nastyfft.h"
#include "settingsdialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void resizeEvent(QResizeEvent *);
    NastyFFT* glView();
    SettingsDialog *dialog;

public slots:
    void changePreset();
    void showSettings();

private:
    Ui::MainWindow *ui;
    NastyFFT *plugin;
};

#endif // MAINWINDOW_H
