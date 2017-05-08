#ifndef RTSPHERE_H
#define RTSPHERE_H

#include "rtobject.h"



class rtSphere : public rtObject
{
public:
    rtSphere(double x, double y, double z, double radius);
protected:
    double radius;
    rtVector3d front = rtVector3d(1,0,0);

    // rtObject interface
public:
    rtLightIntensity intersect(const rtRay &ray, double &cur_distance, const QVector<rtObject *> objects, const QVector<rtAbstractLight *> &lights);



    // rtObject interface
public:
    bool isInPath(const rtRay &ray, const double &distance);
};

#endif // RTSPHERE_H
