#include "jaudio.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    jAudio w;

    w.show();

    return a.exec();
}
