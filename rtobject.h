#ifndef RTOBJECT_H
#define RTOBJECT_H

#include "rtabstractlight.h"
#include "rtlightintensity.h"
#include "rtvector3d.h"

class rtRay;
class rtMaterial;


class rtObject
{
public:
    rtObject(double x, double y, double z);

    virtual rtLightIntensity intersect(const rtRay &ray, double &cur_distance, const QVector<rtObject *> objects, const QVector<rtAbstractLight*> &lights);
    virtual bool isInPath(const rtRay &ray,const double &distance);
    rtVector3d origin() const;
    virtual void setOrigin(const rtVector3d &origin);

    rtVector3d rotation() const;
    void setRotation(const rtVector3d &rotation);

    rtVector3d scale() const;
    void setScale(const rtVector3d &scale);

    rtObject(rtVector3d origin);
    void setMaterial(rtMaterial *value);

protected:
    rtVector3d _origin;
    rtVector3d _rotation;
    rtVector3d _scale;
    rtMaterial* material;
};

#endif // RTOBJECT_H
