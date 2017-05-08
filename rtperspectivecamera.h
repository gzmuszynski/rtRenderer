#ifndef RTPERSPECTIVECAMERA_H
#define RTPERSPECTIVECAMERA_H

#include "rtabstractcamera.h"



class rtPerspectiveCamera : public rtAbstractCamera
{
public:
    rtPerspectiveCamera(rtImageWindow *parent, rtVector3d origin, rtVector3d direction, double near, double far, double fov, rtVector3d up);

    // rtAbstractCamera interface
public:
    virtual rtFilm &operator ()(rtFilm &film, const QVector<rtObject *> &scene, const QVector<rtAbstractLight *> &lights, int msaa);
protected:
    double _fov;
};

#endif // RTPERSPECTIVECAMERA_H
