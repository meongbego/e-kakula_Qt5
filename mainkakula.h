#ifndef MAINKAKULA_H
#define MAINKAKULA_H

#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QMultimedia>
#include <QAudioOutput>
#include <QAudioDeviceInfo>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QFileDialog>
#include <QGraphicsScene>

class MainKakula : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainKakula(QWidget *parent = 0);
    ~MainKakula();

public slots:
    void ketukGong1();
    void ketukGong2();
    void ketukGong3();
    void ketukGong4();
    void ketukGong5();
    void ketukGong6();
    void ketukGong7();
    void soundVolume(int volume);

    void pdfReader();
    
private:
        QWidget *centralWidget;
        QVBoxLayout *verticalLayout_4;
        QHBoxLayout *horizontalLayout_3;
        QTabWidget *TOptionPintas;
        QWidget *TEqual;
        QHBoxLayout *horizontalLayout_6;
        QSlider *sa3;
        QSlider *sa2;
        QSlider *sa1;
        QSlider *sa4;
        QSlider *sa5;
        QSlider *sa6;
        QSlider *sa7;
        QWidget *TEffect;
        QHBoxLayout *horizontalLayout_2;
        QFormLayout *formEffect;
        QLabel *label;
        QSlider *horizontalSlider;
        QLabel *label_2;
        QSlider *horizontalSlider_2;
        QVBoxLayout *verticalLayout_3;
        QGraphicsView *graphicsView;
        QHBoxLayout *horizontalLayout_4;
        QLineEdit *lineEdit;
        QToolButton *toolButton;
        QVBoxLayout *verticalLayout_2;
        QPushButton *btnRekam;
        QHBoxLayout *horizontalLayout;
        QComboBox *comboExample;
        QToolButton *toolButton_2;
        QTimeEdit *exampleTime;
        QPushButton *btnPlay;
        QPushButton *pushButton_2;
        QPushButton *pushButton;
        QHBoxLayout *horizontalLayout_5;
        QPushButton *Gong1;
        QPushButton *Gong2;
        QPushButton *Gong3;
        QPushButton *Gong4;
        QPushButton *Gong5;
        QPushButton *Gong6;
        QPushButton *Gong7;
        QHBoxLayout *LTombolT;


        QMediaPlayer *SGong;

        int suara;

        void keyPressEvent(QKeyEvent *e);

        void gongSpace();
};

#endif // MAINKAKULA_H
