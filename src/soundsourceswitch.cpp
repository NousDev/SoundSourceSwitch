#include "soundsourceswitch.h"

/*************************************
 *  C-Tor / D-Tor
 ************************************/

SoundSourceSwitch::SoundSourceSwitch(QObject *parent) : QObject(parent)
{
    _TrayIcon = new QSystemTrayIcon();

    connect(_TrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(switchSoundSource(QSystemTrayIcon::ActivationReason)));

    activateSpeaker();
    _TrayIcon->show();
}

/*************************************
 *  Public
 ************************************/

void SoundSourceSwitch::switchSoundSource(QSystemTrayIcon::ActivationReason Reason)
{
    switch(_ActiveSoundSource)
    {
    case SPEAKER:
        activateHeadphones();
        break;

    case HEADPHONES:
        activateSpeaker();
        break;
    default:
        break;
    }
}

//------------------------------------

void SoundSourceSwitch::activate(SoundSource SoundSource)
{
    switch(_ActiveSoundSource)
    {
    case SPEAKER:
        activateSpeaker();
        break;

    case HEADPHONES:
        activateHeadphones();
        break;
    default:
        break;
    }
}

/*************************************
 *  Private
 ************************************/

void SoundSourceSwitch::activateSpeaker()
{
    _ActiveSoundSource = SPEAKER;

    _TrayIcon->setIcon(QIcon(":/img/res/img/ic_speaker.png"));

    QProcess* process = new QProcess();
    process->start("amixer -c 0 sset \"Auto-Mute Mode\" Disabled");
    process->start("amixer -c 0 sset \"Headphone,1\" mute");
}

//------------------------------------

void SoundSourceSwitch::activateHeadphones()
{
    _ActiveSoundSource = HEADPHONES;

    _TrayIcon->setIcon(QIcon(":/img/res/img/ic_headphones.png"));

    QProcess* process = new QProcess();
    process->start("amixer -c 0 sset \"Auto-Mute Mode\" Enabled");
    process->start("amixer -c 0 sset \"Headphone,1\" unmute");
}
