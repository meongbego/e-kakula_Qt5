#include "mainkakula.h"
#include "ui_mainkakula.h"
#include <QGraphicsPixmapItem>

MainKakula::MainKakula(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainKakula)
{
    ui->setupUi(this);
    a=50;
    b =0;

    fullScreen = false;
    max=false;

    this->resize(640,400);
    scene = new QGraphicsScene;

    this->ui->splitter->setCollapsible(1,false);
    this->ui->splitter_2->setCollapsible(1,false);
    this->ui->splitter_2->setCollapsible(0, false);

    //toggleFulscreen();
   this->ui->widget_2->hide();
    this->ui->btnHmenu->hide();
    this->ui->textEdit->hide();

    //visualisasi
    this->ui->wChart->show();
    this->ui->wBubble->hide();
    this->ui->wRandom->hide();
    defaultVisual();
    //signal
    connect(this->ui->toolButton_3, SIGNAL(clicked()), this, SLOT(on_btnFullscreen_clicked()));
}

MainKakula::~MainKakula()
{
    delete ui;
}

void MainKakula::defaultVisual()
{
    //meterVU
    meter = new QVUMeter;
    this->meter->setValueDim(50);
    this->meter->setColorValue(Qt::blue);
    this->meter->setColorBg(Qt::gray);
    this->meter->setColorHigh(Qt::red);
    this->meter->setColorLow(Qt::green);
    this->meter->setMaxValue(100);

    meter2 = new QVUMeter;
    this->meter2->setValueDim(50);
    this->meter2->setColorValue(Qt::blue);
    this->meter2->setColorBg(Qt::gray);
    this->meter2->setColorHigh(Qt::red);
    this->meter2->setColorLow(Qt::green);
    this->meter2->setMaxValue(100);

    meter3 = new QVUMeter;
    this->meter3->setValueDim(50);
    this->meter3->setColorValue(Qt::blue);
    this->meter3->setColorBg(Qt::gray);
    this->meter3->setColorHigh(Qt::red);
    this->meter3->setColorLow(Qt::green);
    this->meter3->setMaxValue(100);

    meter4 = new QVUMeter;
    this->meter4->setValueDim(50);
    this->meter4->setColorValue(Qt::blue);
    this->meter4->setColorBg(Qt::gray);
    this->meter4->setColorHigh(Qt::red);
    this->meter4->setColorLow(Qt::green);
    this->meter4->setMaxValue(100);

    meter5 = new QVUMeter;
    this->meter5->setValueDim(50);
    this->meter5->setColorValue(Qt::blue);
    this->meter5->setColorBg(Qt::gray);
    this->meter5->setColorHigh(Qt::red);
    this->meter5->setColorLow(Qt::green);
    this->meter5->setMaxValue(100);

    meter6 = new QVUMeter;
    this->meter6->setValueDim(50);
    this->meter6->setColorValue(Qt::blue);
    this->meter6->setColorBg(Qt::gray);
    this->meter6->setColorHigh(Qt::red);
    this->meter6->setColorLow(Qt::green);
    this->meter6->setMaxValue(100);

    meter7 = new QVUMeter;
    this->meter7->setValueDim(50);
    this->meter7->setColorValue(Qt::blue);
    this->meter7->setColorBg(Qt::gray);
    this->meter7->setColorHigh(Qt::red);
    this->meter7->setColorLow(Qt::green);
    this->meter7->setMaxValue(100);

    this->ui->wLayoutHchart->addWidget(meter);
    this->ui->wLayoutHchart->addWidget(meter2);
    this->ui->wLayoutHchart->addWidget(meter3);
    this->ui->wLayoutHchart->addWidget(meter4);
    this->ui->wLayoutHchart->addWidget(meter5);
    this->ui->wLayoutHchart->addWidget(meter6);
    this->ui->wLayoutHchart->addWidget(meter7);

}

void MainKakula::bubleVisual()
{

}

void MainKakula::randomVisual()
{

}

void MainKakula::on_horizontalSlider_sliderMoved(int position)
{
  this->a=position;
}


void MainKakula::on_btnFullscreen_clicked()
{
    if (this->fullScreen){
        this->showNormal();
        this->fullScreen = false;
    }
    else{
        this->showFullScreen();
        this->fullScreen = true;
    }
}

void MainKakula::on_btnMaximize_clicked()
{
    if (this->max){
        this->showNormal();
        this->max=false;
    }
    else {
        this->showMaximized();
        this->max=true;
    }
}

void MainKakula::on_btnMinimize_clicked()
{
    this->showMinimized();
}



void MainKakula::on_btnHmenu_clicked()
{
    this->ui->widget_2->hide();
    this->ui->btnHmenu->hide();
    this->ui->btnSmenu->show();
}

void MainKakula::on_btnSmenu_clicked()
{
    this->ui->widget_2->show();
    this->ui->btnSmenu->hide();
    this->ui->btnHmenu->show();
}

void MainKakula::resizeEvent(QResizeEvent *event)
{  
    int c = this->size().rheight();
    int d = this->size().rwidth();

    if (d > 1111 && c > 379){
        this->ui->widget_2->show();
    }
    else{
        this->ui->widget_2->hide();
    }

}


void MainKakula::plotting()
{

}


void MainKakula::on_checkBox_2_toggled(bool checked)
{
    if (checked == true){
        this->ui->textEdit->show();
        this->ui->label_7->hide();
    }
    else{
        this->ui->textEdit->hide();
        this->ui->label_7->show();
    }
}

void MainKakula::on_Gong1_clicked()
{
    QMediaPlayer *playerGong = new QMediaPlayer;
    playerGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/PENELITIAN_KAKULA/KAKULA/assets/a1.ogg"));
    playerGong->setVolume(a);
    playerGong->play();



    for (; this->b <100;){
       this->b++;
    }
    qDebug()<<"NILAI B = "<<b;
    this->meter->setLeftValue(this->b);
    this->meter->setRightValue(50);

    this->meter2->setLeftValue(50);
    this->meter2->setRightValue(0);

}

void MainKakula::on_Gong2_clicked()
{
    QMediaPlayer *playerGong = new QMediaPlayer;
    playerGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/PENELITIAN_KAKULA/KAKULA/assets/a2.ogg"));
    playerGong->setVolume(a);
    playerGong->play();

    for (; this->b <100;){
       this->b++;
    }
    this->meter2->setLeftValue(b);
    this->meter2->setRightValue(50);

    this->meter->setLeftValue(0);
    this->meter->setRightValue(0);
}

void MainKakula::on_Gong3_clicked()
{
    QMediaPlayer *playerGong = new QMediaPlayer;
    playerGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/PENELITIAN_KAKULA/KAKULA/assets/a3.ogg"));
    playerGong->setVolume(a);
    playerGong->play();
}

void MainKakula::on_Gong4_clicked()
{
    QMediaPlayer *playerGong = new QMediaPlayer;
    playerGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/PENELITIAN_KAKULA/KAKULA/assets/a4.ogg"));
    playerGong->setVolume(a);
    playerGong->play();
}

void MainKakula::on_Gong5_clicked()
{
    QMediaPlayer *playerGong = new QMediaPlayer;
    playerGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/PENELITIAN_KAKULA/KAKULA/assets/a5.ogg"));
    playerGong->setVolume(a);
    playerGong->play();
}

void MainKakula::on_Gong6_clicked()
{
    QMediaPlayer *playerGong = new QMediaPlayer;
    playerGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/PENELITIAN_KAKULA/KAKULA/assets/a6.ogg"));
    playerGong->setVolume(a);
    playerGong->play();
}

void MainKakula::on_Gong7_clicked()
{
    QMediaPlayer *playerGong = new QMediaPlayer;
    playerGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/PENELITIAN_KAKULA/KAKULA/assets/a7.ogg"));
    playerGong->setVolume(a);
    playerGong->play();
}

void MainKakula::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_L :
        this->ui->Gong7->animateClick(100);
        break;
    case Qt::Key_K:
        this->ui->Gong6->animateClick(100);
        break;
    case Qt::Key_M:
        this->ui->Gong5->animateClick(100);
        break;
    case Qt::Key_C:
        this->ui->Gong4->animateClick(100);
        break;
    case Qt::Key_D:
        this->ui->Gong3->animateClick(100);
        break;
    case Qt::Key_S:
        this->ui->Gong2->animateClick(100);
        break;
    case Qt::Key_A:
        this->ui->Gong1->animateClick(100);
        break;
    case Qt::Key_Space:
        QMessageBox::information(0,"Info Kakula", "Fitur Ini Akan Tesedia\nDirelease Berikutnya");
        break;
    default:
        break;
    }
}

void MainKakula::on_comboBox_3_activated(int index)
{
    if (index == 0){
        this->ui->wChart->show();
        this->ui->wRandom->hide();
        this->ui->wBubble->hide();
    }
    else if (index==1) {
        this->ui->wBubble->show();
        this->ui->wRandom->hide();
        this->ui->wChart->hide();
    }
    else if (index==2) {
        this->ui->wRandom->show();
        this->ui->wChart->hide();
        this->ui->wBubble->hide();
    }
}

void MainKakula::on_checkBox_toggled(bool checked)
{
    if (checked==true){
        this->ui->wRandom->hide();
        this->ui->wChart->hide();
        this->ui->wBubble->hide();
    }
    else{
        this->ui->wRandom->hide();
        this->ui->wChart->show();
        this->ui->wBubble->hide();
    }
}
