#ifndef RTPIXELTHREAD_H
#define RTPIXELTHREAD_H

#include "rtlightintensity.h"
#include "rtobject.h"

#include <QThread>

class rtCameraInfo;

class rtPixelThread : public QThread
{
public:
    rtPixelThread(QObject* parent=0);
    Q_OBJECT

    void render(int x, int y, const rtCameraInfo &cam);

signals:
    void renderedPixel(int x, int y, const rtLightIntensity &color, const double &depth);

    // QThread interface
protected:
    void run();
};

#endif // RTPIXELTHREAD_H
