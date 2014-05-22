#include "mainkakula.h"

MainKakula::MainKakula(QWidget *parent) :
    QMainWindow(parent)
{
    centralWidget = new QWidget(this);

    verticalLayout_4 = new QVBoxLayout(centralWidget);
    verticalLayout_4->setSpacing(6);
    verticalLayout_4->setContentsMargins(11, 11, 11, 11);
    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setSpacing(6);

    TOptionPintas = new QTabWidget(centralWidget);

    TEqual = new QWidget();
    horizontalLayout_6 = new QHBoxLayout(TEqual);
    horizontalLayout_6->setSpacing(1);
    horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
    horizontalLayout_6->setContentsMargins(0, 0, 0, 0);

    sa3 = new QSlider(TEqual);
    sa3->setMaximum(100);
    sa3->setValue(50);
    sa3->setSliderPosition(50);
    sa3->setOrientation(Qt::Vertical);
    sa3->setInvertedAppearance(false);
    sa3->setInvertedControls(false);
    sa3->setTickPosition(QSlider::TicksBothSides);

    horizontalLayout_6->addWidget(sa3);

    sa2 = new QSlider(TEqual);
    sa2->setMaximum(100);
    sa2->setValue(50);
    sa2->setOrientation(Qt::Vertical);
    sa2->setTickPosition(QSlider::TicksBothSides);

    horizontalLayout_6->addWidget(sa2);

    sa1 = new QSlider(TEqual);
    sa1->setMaximum(100);
    sa1->setValue(50);
    sa1->setOrientation(Qt::Vertical);
    sa1->setTickPosition(QSlider::TicksBothSides);
    sa1->setTickInterval(0);

    horizontalLayout_6->addWidget(sa1);

    sa4 = new QSlider(TEqual);
    sa4->setMaximum(100);
    sa4->setValue(50);
    sa4->setOrientation(Qt::Vertical);
    sa4->setTickPosition(QSlider::TicksBothSides);

    horizontalLayout_6->addWidget(sa4);

    sa5 = new QSlider(TEqual);
    sa5->setMaximum(100);
    sa5->setValue(50);
    sa5->setOrientation(Qt::Vertical);
    sa5->setTickPosition(QSlider::TicksBothSides);

    horizontalLayout_6->addWidget(sa5);

    sa6 = new QSlider(TEqual);
    sa6->setMaximum(100);
    sa6->setValue(50);
    sa6->setOrientation(Qt::Vertical);
    sa6->setTickPosition(QSlider::TicksBothSides);

    horizontalLayout_6->addWidget(sa6);

    sa7 = new QSlider(TEqual);
    sa7->setMaximum(100);
    sa7->setValue(50);
    sa7->setOrientation(Qt::Vertical);
    sa7->setTickPosition(QSlider::TicksBothSides);

    horizontalLayout_6->addWidget(sa7);

    TOptionPintas->addTab(TEqual, QString());
    TEffect = new QWidget();
    horizontalLayout_2 = new QHBoxLayout(TEffect);
    horizontalLayout_2->setSpacing(6);
    horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
    formEffect = new QFormLayout();
    formEffect->setSpacing(6);
    formEffect->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    formEffect->setHorizontalSpacing(4);
    formEffect->setVerticalSpacing(8);
    label = new QLabel(TEffect);

    formEffect->setWidget(0, QFormLayout::LabelRole, label);

    horizontalSlider = new QSlider(TEffect);
    horizontalSlider->setOrientation(Qt::Horizontal);
    horizontalSlider->setTickPosition(QSlider::TicksBelow);
    horizontalSlider->setValue(50);

    formEffect->setWidget(0, QFormLayout::FieldRole, horizontalSlider);

    label_2 = new QLabel(TEffect);

    formEffect->setWidget(1, QFormLayout::LabelRole, label_2);

    horizontalSlider_2 = new QSlider(TEffect);
    horizontalSlider_2->setOrientation(Qt::Horizontal);
    horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
    horizontalSlider_2->setValue(50);

    formEffect->setWidget(1, QFormLayout::FieldRole, horizontalSlider_2);


    horizontalLayout_2->addLayout(formEffect);

    TOptionPintas->addTab(TEffect, QString());

    horizontalLayout_3->addWidget(TOptionPintas);

    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setSpacing(6);
    graphicsView = new QGraphicsView(centralWidget);

    verticalLayout_3->addWidget(graphicsView);

    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setSpacing(6);
    lineEdit = new QLineEdit(centralWidget);

    horizontalLayout_4->addWidget(lineEdit);

    toolButton = new QToolButton(centralWidget);
    QIcon icon;
    icon.addFile(QStringLiteral(":/icon/icon/open.png"), QSize(), QIcon::Normal, QIcon::Off);
    toolButton->setIcon(icon);
    toolButton->setCheckable(false);
    toolButton->setToolButtonStyle(Qt::ToolButtonFollowStyle);

    horizontalLayout_4->addWidget(toolButton);


    verticalLayout_3->addLayout(horizontalLayout_4);


    horizontalLayout_3->addLayout(verticalLayout_3);

    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setSpacing(6);
    btnRekam = new QPushButton(centralWidget);
    verticalLayout_2->addWidget(btnRekam);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    comboExample = new QComboBox(centralWidget);

    horizontalLayout->addWidget(comboExample);

    toolButton_2 = new QToolButton(centralWidget);

    horizontalLayout->addWidget(toolButton_2);

    verticalLayout_2->addLayout(horizontalLayout);

    exampleTime = new QTimeEdit(centralWidget);
    exampleTime->setWrapping(false);
    exampleTime->setFrame(false);
    exampleTime->setAlignment(Qt::AlignCenter);
    exampleTime->setReadOnly(true);
    exampleTime->setButtonSymbols(QAbstractSpinBox::NoButtons);
    exampleTime->setKeyboardTracking(true);

    verticalLayout_2->addWidget(exampleTime);

    btnPlay = new QPushButton(centralWidget);
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
   // sizePolicy.setHorizontalStretch(100);
    //sizePolicy.setVerticalStretch(100);
    //sizePolicy.setHeightForWidth(btnPlay->sizePolicy().hasHeightForWidth());
   // btnPlay->setSizePolicy(sizePolicy);
    QIcon icon1;
    icon1.addFile(QStringLiteral(":/icon/icon/video-play-512.png"), QSize(), QIcon::Normal, QIcon::Off);
    btnPlay->setIcon(icon1);
    btnPlay->setIconSize(QSize(80, 80));

    verticalLayout_2->addWidget(btnPlay);

    pushButton_2 = new QPushButton(centralWidget);
    QIcon icon2;
    icon2.addFile(QStringLiteral(":/icon/icon/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
    pushButton_2->setIcon(icon2);

    verticalLayout_2->addWidget(pushButton_2);

    pushButton = new QPushButton(centralWidget);

    verticalLayout_2->addWidget(pushButton);


    horizontalLayout_3->addLayout(verticalLayout_2);


    verticalLayout_4->addLayout(horizontalLayout_3);

    horizontalLayout_5 = new QHBoxLayout();
    horizontalLayout_5->setSpacing(6);
    horizontalLayout_5->setContentsMargins(-1, 0, -1, 0);
    Gong1 = new QPushButton(centralWidget);
    QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(Gong1->sizePolicy().hasHeightForWidth());
    Gong1->setSizePolicy(sizePolicy1);
    Gong1->setSizeIncrement(QSize(0, 0));
    QIcon icon3;
    icon3.addFile(QStringLiteral(":/icon/icon/gong1.png"), QSize(), QIcon::Normal, QIcon::Off);
    Gong1->setIcon(icon3);
    Gong1->setIconSize(QSize(150, 200));
    Gong1->setAutoDefault(true);
    Gong1->setFlat(true);

    horizontalLayout_5->addWidget(Gong1);

    Gong2 = new QPushButton(centralWidget);
    sizePolicy1.setHeightForWidth(Gong2->sizePolicy().hasHeightForWidth());
    Gong2->setSizePolicy(sizePolicy1);
    Gong2->setIcon(icon3);
    Gong2->setIconSize(QSize(150, 200));
    Gong2->setAutoDefault(true);
    Gong2->setFlat(true);

    horizontalLayout_5->addWidget(Gong2);

    Gong3 = new QPushButton(centralWidget);
    sizePolicy1.setHeightForWidth(Gong3->sizePolicy().hasHeightForWidth());
    Gong3->setSizePolicy(sizePolicy1);
    Gong3->setIcon(icon3);
    Gong3->setIconSize(QSize(150, 200));
    Gong3->setAutoDefault(true);
    Gong3->setFlat(true);

    horizontalLayout_5->addWidget(Gong3);

    Gong4 = new QPushButton(centralWidget);
    sizePolicy1.setHeightForWidth(Gong4->sizePolicy().hasHeightForWidth());
    Gong4->setSizePolicy(sizePolicy1);
    Gong4->setIcon(icon3);
    Gong4->setIconSize(QSize(150, 200));
    Gong4->setAutoDefault(true);
    Gong4->setFlat(true);

    horizontalLayout_5->addWidget(Gong4);

    Gong5 = new QPushButton(centralWidget);
    sizePolicy1.setHeightForWidth(Gong5->sizePolicy().hasHeightForWidth());
    Gong5->setSizePolicy(sizePolicy1);
    Gong5->setIcon(icon3);
    Gong5->setIconSize(QSize(150, 200));
    Gong5->setAutoDefault(true);
    Gong5->setFlat(true);

    horizontalLayout_5->addWidget(Gong5);

    Gong6 = new QPushButton(centralWidget);
    sizePolicy1.setHeightForWidth(Gong6->sizePolicy().hasHeightForWidth());
    Gong6->setSizePolicy(sizePolicy1);
    Gong6->setIcon(icon3);
    Gong6->setIconSize(QSize(150, 200));
    Gong6->setAutoDefault(true);
    Gong6->setFlat(true);

    horizontalLayout_5->addWidget(Gong6);

    Gong7 = new QPushButton(centralWidget);
    sizePolicy1.setHeightForWidth(Gong7->sizePolicy().hasHeightForWidth());
    Gong7->setSizePolicy(sizePolicy1);
    Gong7->setIcon(icon3);
    Gong7->setIconSize(QSize(150, 200));
    Gong7->setAutoDefault(true);
    Gong7->setFlat(true);

    horizontalLayout_5->addWidget(Gong7);


    verticalLayout_4->addLayout(horizontalLayout_5);

    LTombolT = new QHBoxLayout();
    LTombolT->setSpacing(6);
    LTombolT->setContentsMargins(-1, 0, -1, 0);



    verticalLayout_4->addLayout(LTombolT);

    this->setCentralWidget(centralWidget);

    TOptionPintas->setCurrentIndex(0);


    //nama tombol

    TOptionPintas->setTabText(TOptionPintas->indexOf(TEqual), QApplication::translate("MainKakula", "Setting", 0));
    label->setText(QApplication::translate("MainKakula", "Volume", 0));
    label_2->setText(QApplication::translate("MainKakula", "Effect", 0));
    TOptionPintas->setTabText(TOptionPintas->indexOf(TEffect), QApplication::translate("MainKakula", "Effect", 0));
    toolButton->setText(QString());
    btnRekam->setText(QApplication::translate("MainKakula", "Rekam", 0));
    toolButton_2->setText(QApplication::translate("MainKakula", "...", 0));
    btnPlay->setText(QString());
    pushButton_2->setText(QApplication::translate("MainKakula", "Quit", 0));
    pushButton->setText(QApplication::translate("MainKakula", "About Me", 0));
    Gong1->setText(QString());
    Gong2->setText(QString());
    Gong3->setText(QString());
    Gong4->setText(QString());
    Gong5->setText(QString());
    Gong6->setText(QString());
    Gong7->setText(QString());

    //volume

    suara =50;

    //signal

    connect(Gong1, SIGNAL(clicked()), this, SLOT(ketukGong1()));
    connect(Gong2, SIGNAL(clicked()), this, SLOT(ketukGong2()));
    connect(Gong3, SIGNAL(clicked()), this, SLOT(ketukGong3()));
    connect(Gong4, SIGNAL(clicked()), this, SLOT(ketukGong4()));
    connect(Gong5, SIGNAL(clicked()), this, SLOT(ketukGong5()));
    connect(Gong6, SIGNAL(clicked()), this, SLOT(ketukGong6()));
    connect(Gong7, SIGNAL(clicked()), this,SLOT(ketukGong7()));

    connect(horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(soundVolume(int)));

    //shortcut keyboard
}

MainKakula::~MainKakula()
{

}

void MainKakula::ketukGong1()
{
    SGong = new QMediaPlayer;
    this->SGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/kakula_SRC/KAKULA/assets/a7.ogg"));
    this->SGong->setVolume(suara);
    this->SGong->play();
}

void MainKakula::ketukGong2()
{
    SGong = new QMediaPlayer;
    this->SGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/kakula_SRC/KAKULA/assets/a6.ogg"));
    this->SGong->setVolume(suara);
    this->SGong->play();
}

void MainKakula::ketukGong3()
{
    SGong = new QMediaPlayer;
    this->SGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/kakula_SRC/KAKULA/assets/a5.ogg"));
    this->SGong->setVolume(suara);
    this->SGong->play();
}

void MainKakula::ketukGong4()
{
    SGong = new QMediaPlayer;
    this->SGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/kakula_SRC/KAKULA/assets/a4.ogg"));
    this->SGong->setVolume(suara);
    this->SGong->play();
}

void MainKakula::ketukGong5()
{
    SGong = new QMediaPlayer;
    this->SGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/kakula_SRC/KAKULA/assets/a3.ogg"));
    this->SGong->setVolume(suara);
    this->SGong->play();
}

void MainKakula::ketukGong6()
{
    SGong = new QMediaPlayer;
    this->SGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/kakula_SRC/KAKULA/assets/a2.ogg"));
    this->SGong->setVolume(suara);
    this->SGong->play();
}

void MainKakula::ketukGong7()
{
    SGong = new QMediaPlayer;
    this->SGong->setMedia(QUrl::fromLocalFile("/run/media/meong/2187ace6-be97-4e16-aff1-37c2c9802a99/PROJECT/kakula_SRC/KAKULA/assets/a1.ogg"));
    this->SGong->setVolume(suara);
    this->SGong->play();
}

void MainKakula::soundVolume(int volume)
{
    this->suara=volume;
}

void MainKakula::keyPressEvent(QKeyEvent *e)
{
    /*
    if (e->key() == Qt::Key_A){
        ketukGong1();
    }
    else if()
    */
    switch (e->key()) {
    case Qt::Key_A :
        ketukGong1();
        break;
    case Qt::Key_S:
        ketukGong2();
        break;
    case Qt::Key_D:
        ketukGong3();
        break;
    case Qt::Key_F:
        ketukGong4();
        break;
    case Qt::Key_G:
        ketukGong5();
        break;
    case Qt::Key_H:
        ketukGong6();
        break;
    case Qt::Key_J:
        ketukGong7();
        break;
    default:
        break;
    }
}
