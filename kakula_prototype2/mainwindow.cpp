#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glview.h"


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pulse/simple.h>
#include <pulse/error.h>
#include "spectrumanalyser.h"
#include "pulseaudiomonitor.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dialog(0)
{
    ui->setupUi(this);

    plugin = new NastyFFT();
    plugin->setParent(ui->centralWidget);

    int num_presets =  plugin->presetCount();
    for (int a=0;a<num_presets;a++) {
        QAction *act = new QAction(this);
        act->setText(plugin->presetName(a));
        act->setData(QVariant(a));

        connect(act, SIGNAL(triggered()), this, SLOT(changePreset()));
        ui->menuBar->addAction(act);

    }

    dialog = new SettingsDialog(plugin->scenePreset(), this);
    connect(ui->actionSettings, SIGNAL(triggered()), this, SLOT(showSettings()));

    connect(plugin, SIGNAL(presetChanged()), dialog, SLOT(presetChanged()));

}

MainWindow::~MainWindow()
{
    delete plugin;
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    QSize size = ui->centralWidget->size();
    plugin->resize(size);
}
NastyFFT* MainWindow::glView()
{
    return plugin;
}

void MainWindow::changePreset()
{
    QAction *act = (QAction*)QObject::sender();
    QVariant data = act->data();
    plugin->loadPreset(data.toInt());
}
void MainWindow::showSettings()
{

    dialog->show();

}
