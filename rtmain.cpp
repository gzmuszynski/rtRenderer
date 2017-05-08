#include "rtimagewindow.h"
#include "rtraywindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    rtRayWindow w;
//    w.show();
    rtImageWindow w;
    w.show();

    return a.exec();
}
