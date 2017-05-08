#ifndef RTPLANE_H
#define RTPLANE_H

#include "rtobject.h"
#include "rtvector3d.h"
#include "rtray.h"



class rtPlane : public rtObject
{
public:
    rtPlane(rtVector3d normal, double d);
    rtPlane(double a, double b, double c, double d);

protected:
    const rtVector3d _normal;
    const double _distance;
    rtVector3d UVup;
    rtVector3d UVside;
    double UVscale=1;

    // rtObject interface
public:
    rtLightIntensity intersect(const rtRay &ray, double &cur_distance, const QVector<rtObject *> objects, const QVector<rtAbstractLight *> &lights);

    // rtObject interface
public:
    rtLightIntensity getColor(const rtRay &ray);

    // rtObject interface
public:
    bool isInPath(const rtRay &ray, const double &distance);
};

#endif // RTPLANE_H
