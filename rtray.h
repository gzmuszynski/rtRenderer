#ifndef RTRAY_H
#define RTRAY_H
#include "rtraywindow.h"
//#include "rtobject.h"
#include "rtabstractlight.h"
#include "rtpoint.h"
#include "rtvector3d.h"

#include <QVector>

class rtObject;

class rtRay
{
public:
    rtRay(const rtRay &ray);
    rtRay(const rtVector3d & origin,const rtVector3d & direction);
    rtRay(const rtVector3d & origin,const rtVector3d & direction, int bounces);
    rtVector3d getOrigin() const;
    rtVector3d getDirection() const;

    rtVector3d operator()(double t) const;
    rtRay operator -(int i) const;
    bool operator == (int i) const;
    rtLightIntensity operator()(const QVector<rtObject*> &vec, const QVector<rtAbstractLight*> &lights, double &distance, double near, double far);
    int getBounces() const;

protected:
    const rtVector3d _origin;
    const rtVector3d _direction;
    int bounces;
};

#endif // RTRAY_H
