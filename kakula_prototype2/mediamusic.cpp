#include "mediamusic.h"
#include <QApplication>

MediaMusic::MediaMusic(QObject *parent) :
    QObject(parent)
{
    gongPlay = new QMediaPlayer;
    exampleMusic = new QMediaPlayer;
    chekFolder();
}

void MediaMusic::play()
{
    gongPlay->play();
}

void MediaMusic::setMedia(QString p)
{
    gongPlay->setMedia(QUrl::fromLocalFile(p));
}

void MediaMusic::setVolume(int v)
{
    gongPlay->setVolume(v);
}

void MediaMusic::playExample()
{
    exampleMusic->play();
}

void MediaMusic::setMediaExample(QString e)
{
    exampleMusic->setMedia(QUrl::fromLocalFile(e));
}

void MediaMusic::setVolumeExample(int v)
{
    exampleMusic->setVolume(v);
}

void MediaMusic::chekFolder()
{

#ifdef Q_OS_LINUX
    home = "/usr/share/kakula/";
    pathNuada =home+"nuada";
    pathKontempore = home +"kontemporer/";
    QDir resource(home);
#elif defined(Q_OS_WINDOWS)
    home = "C:/Program File/vkakula";
    pathNuada = home+"/nuada/";
    pathKontempore = home+"/kontemporer/";
#endif
    if (!resource.exists()){
        resource.mkdir(home);
    }
    QDir nuadaFolder(pathNuada);
    if (!nuadaFolder.exists()){
       nuadaFolder.mkdir(pathNuada);
    }

    QDir kontemporerFolder(pathKontempore);
    if (!kontemporerFolder.exists()){
        kontemporerFolder.mkdir(pathKontempore);
    }
}


