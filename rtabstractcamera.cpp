#include "rtabstractcamera.h"

rtAbstractCamera::rtAbstractCamera(rtImageWindow *parent, rtVector3d origin, rtVector3d direction, double near, double far, rtVector3d up = rtVector3d(0,0,1)):
    _origin(origin),
    _direction(direction),
    _near(near),
    _far(far),
    _up(up)
{
    this->parent = parent;
}
