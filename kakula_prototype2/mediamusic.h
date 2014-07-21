#ifndef MEDIAMUSIC_H
#define MEDIAMUSIC_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QAudioInput>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QSound>

class MediaMusic : public QObject
{
    Q_OBJECT
public:
    explicit MediaMusic(QObject *parent = 0);
    QString home;
    QString pathNuada;
    QString pathKontempore;

    void play();
    void setMedia(QString p);
    void setVolume(int v);

    //exampleMusic
    void playExample();
    void setMediaExample(QString e);
    void setVolumeExample(int v);
    void stopExample();

    //checking
    void chekFolder();

signals:

public slots:

private:
    QMediaPlayer *gongPlay;
    QMediaPlayer *exampleMusic;
};

#endif // MEDIAMUSIC_H
