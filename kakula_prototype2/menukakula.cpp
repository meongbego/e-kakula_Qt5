#include "menukakula.h"
#include "ui_menukakula.h"
#include "glview.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <pulse/simple.h>
#include <pulse/error.h>

#include "spectrumanalyser.h"
#include "pulseaudiomonitor.h"


MenuKakula::MenuKakula(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuKakula)
{
    ui->setupUi(this);

    plugin = new NastyFFT;
    plugin->setParent(this->ui->widget);
    wInSetting = new SettingsDialog(plugin->scenePreset(), this);
    connect(ui->btnSetting, SIGNAL(clicked()), this, SLOT(showSettings()));

    media = new MediaMusic;
    mode = media->pathNuada;

    qDebug()<<mode;

    wmenudialog = new MenuDialog;
    this->ui->menuWidget->hide();
    this->ui->menuHide->hide();
    this->ui->layoutMenuWidget->addWidget(wmenudialog);
}

void MenuKakula::resizeEvent(QResizeEvent *)
{
    QSize size = this->ui->widget->size();
    plugin->resize(size);
}

MenuKakula::~MenuKakula()
{
    delete ui;
    delete plugin;
}

NastyFFT *MenuKakula::glView()
{
    return plugin;
}


void MenuKakula::showSettings()
{
    wInSetting->show();
}

void MenuKakula::on_comboVisualisasi_activated(int index)
{
    if (index == 0){
        plugin->loadPreset(0);
        this->ui->widget->show();
    }
    else if (index== 1){
        plugin->loadPreset(1);
        this->ui->widget->show();
    }
    else if (index== 2){
        plugin->loadPreset(2);
        this->ui->widget->show();
    }
    else {
        this->ui->widget->hide();
    }

}

void MenuKakula::on_btnG1_clicked()
{
    MediaMusic *media1 = new MediaMusic;
    media1->setMedia(mode+"/a1.ogg");
    media1->setVolume(volume);
    media1->play();
}

void MenuKakula::on_btnG2_clicked()
{
    MediaMusic *media2 = new MediaMusic;
    media2->setMedia(mode+"/a2.ogg");
    media2->setVolume(volume);
    media2->play();
}

void MenuKakula::on_btnG3_clicked()
{
    MediaMusic *media3 = new MediaMusic;
    media3->setMedia(mode+"/a3.ogg");
    media3->setVolume(volume);
    media3->play();
}

void MenuKakula::on_btnG4_clicked()
{
    MediaMusic *media4 = new MediaMusic;
    media4->setMedia(mode+"/a4.ogg");
    media4->setVolume(volume);
    media4->play();
}

void MenuKakula::on_btnG5_clicked()
{
    MediaMusic *media5 = new MediaMusic;
    media5->setMedia(mode+"/a5.ogg");
    media5->setVolume(volume);
    media5->play();
}

void MenuKakula::on_btnG6_clicked()
{
    MediaMusic *media6 = new MediaMusic;
    media6->setMedia(mode+"/a6.ogg");
    media6->setVolume(volume);
    media6->play();
}

void MenuKakula::on_btnG7_clicked()
{
    MediaMusic *media7 = new MediaMusic;
    media7->setMedia(mode+"/a7.ogg");
    media7->setVolume(volume);
    media7->play();
}

void MenuKakula::on_comboMode_activated(int index)
{
    if (index == 0){
        mode = media->pathNuada;
    }
    else if (index== 1){
        mode = media->pathKontempore;
    }
    else{
        mode = media->pathNuada;
    }
    qDebug()<<mode;
}

void MenuKakula::on_volSlider_sliderMoved(int position)
{
    volume = position;
}

void MenuKakula::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_D:
        this->ui->btnG1->animateClick();
        break;
    case Qt::Key_F:
        this->ui->btnG2->animateClick();
        break;
    case Qt::Key_G:
        this->ui->btnG3->animateClick();
        break;
    case Qt::Key_H:
        this->ui->btnG4->animateClick();
        break;
    case Qt::Key_J:
        this->ui->btnG5->animateClick();
        break;
    case Qt::Key_K:
        this->ui->btnG6->animateClick();
        break;
    case Qt::Key_L:
        this->ui->btnG7->animateClick();
        break;
    default:
        break;
    }
}

void MenuKakula::on_menuHide_clicked()
{
    this->ui->menuWidget->hide();
    this->ui->menuHide->hide();
    this->ui->menuShow->show();
}

void MenuKakula::on_menuShow_clicked()
{
    this->ui->menuWidget->show();
    this->ui->menuShow->hide();
    this->ui->menuHide->show();
}
