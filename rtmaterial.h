#ifndef RTMATERIAL_H
#define RTMATERIAL_H

#include "rtray.h"
#include "rtobject.h"
#include "rtvector3d.h"
#include "rtabstractlight.h"

#include <QVector>

// Abstract class for adding materials/shaders on an object

class rtMaterial
{
public:
    rtMaterial();
    // BRDF function abstract / reflection function
    virtual rtLightIntensity operator ()(const rtRay &ray, const rtVector3d &point, const rtVector3d &normal, const rtVector3d &coords,
                                         const QVector<rtObject *> &objects, const QVector<rtAbstractLight*> &lights)=0;
protected:


};

#endif // RTMATERIAL_H
