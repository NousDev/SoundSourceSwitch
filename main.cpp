#include "src/soundsourceswitch.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SoundSourceSwitch soundSourceSwitch;

    return a.exec();
}
