#ifndef RTCAMERA_H
#define RTCAMERA_H

#include "rtfilm.h"
#include "rtvector3d.h"
#include "rtobject.h"

// An abstract class for Cameras. Takes film object and projects image onto it.

class rtImageWindow;

class rtAbstractCamera
{
public:
    // default constructior
    rtAbstractCamera(rtImageWindow* parent, rtVector3d origin, rtVector3d direction, double near, double far, rtVector3d up);
    // Main function of taking picture. Takes film, genrerates image and return lit image.
    virtual rtFilm& operator()(rtFilm& film, const QVector<rtObject*> &scene, const QVector<rtAbstractLight*> &lights, int msaa) =0;

protected:
    rtVector3d _origin; // A point in space representing position of the camera
    rtVector3d _direction; // A vector representing line of sight of the camera
    double _near; // Near clip plane distance
    double _far; // Far clip plane distance
    rtVector3d _up; // Vector representing upnode. Controls barrel roll of the camera
    rtImageWindow* parent; // Parent object

};

#endif // RTCAMERA_H
