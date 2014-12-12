#ifndef SOUNDSOURCESWITCH_H
#define SOUNDSOURCESWITCH_H

#include <QObject>
#include <QSystemTrayIcon>
#include <QProcess>

enum SoundSource
{
    UNDEFINED = 0,
    SPEAKER = 1,
    HEADPHONES = 2
};

class SoundSourceSwitch : public QObject
{
    Q_OBJECT

public:

    explicit            SoundSourceSwitch(QObject *parent = 0);

    void                activate(SoundSource SoundSource);

public slots:

    void                switchSoundSource(QSystemTrayIcon::ActivationReason Reason);

private:

    QSystemTrayIcon *   _TrayIcon;
    SoundSource         _ActiveSoundSource;

    void                activateSpeaker();
    void                activateHeadphones();
};

#endif // SOUNDSOURCESWITCH_H
