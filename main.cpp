#include "rect.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Rect w;
    w.show();
    return a.exec();
}
