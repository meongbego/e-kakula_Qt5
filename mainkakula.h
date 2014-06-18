#ifndef MAINKAKULA_H
#define MAINKAKULA_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMultimedia>
#include <QMediaPlayer>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <meter.h>
#include <glwidget.h>

namespace Ui {
class MainKakula;
}

class MainKakula : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainKakula(QWidget *parent = 0);
    ~MainKakula();

    //visualisasi
    void defaultVisual();
    void bubleVisual();
    void randomVisual();
    
private slots:
    void on_Gong1_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_btnFullscreen_clicked();

    void on_btnMaximize_clicked();

    void on_btnMinimize_clicked();

    void on_btnHmenu_clicked();

    void on_btnSmenu_clicked();

    void resizeEvent(QResizeEvent *event);

    void on_checkBox_2_toggled(bool checked);

    void on_Gong2_clicked();

    void on_Gong3_clicked();

    void on_Gong4_clicked();

    void on_Gong5_clicked();

    void on_Gong6_clicked();

    void on_Gong7_clicked();

    void on_comboBox_3_activated(int index);

    void on_checkBox_toggled(bool checked);

signals:


private:
    Ui::MainKakula *ui;

    int a;
    int b;

    bool fullScreen;

    bool max;

    QGraphicsRectItem *rectangle;
    QGraphicsLineItem *line;
    QGraphicsScene *scene;

    //visualisasi
    QVUMeter *meter;
    QVUMeter *meter2;
    QVUMeter *meter3;
    QVUMeter *meter4;
    QVUMeter *meter5;
    QVUMeter *meter6;
    QVUMeter *meter7;

    GLWidget *bubleWidget;

    //testing
    void keyPressEvent(QKeyEvent *e);
    void plotting();
};

#endif // MAINKAKULA_H
