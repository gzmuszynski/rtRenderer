#include "rtobject.h"
#include "rtray.h"
#include "rtphong.h"

rtObject::rtObject(double x, double y, double z): _origin(x,y,z), _rotation(0,0,0), _scale(1,1,1)
{
    material = new rtPhong(rtLightIntensity(0.2,0.2,0.2),rtLightIntensity(0.5,0.5,0.5),rtLightIntensity(1.0,1.0,1.0),10);
}

rtObject::rtObject(rtVector3d origin): _origin(origin), _rotation(0,0,0), _scale(1,1,1)
{
    material = new rtPhong(rtLightIntensity(0.2,0.2,0.2),rtLightIntensity(0.2,0.5,0.1),rtLightIntensity(1.0,1.0,1.0),40);

}

void rtObject::setMaterial(rtMaterial *value)
{
    material = value;
}

rtLightIntensity rtObject::intersect(const rtRay &ray, double &cur_distance, const QVector<rtObject *> objects, const QVector<rtAbstractLight*> &lights)
{
    return rtLightIntensity(0,0,0);
}

bool rtObject::isInPath(const rtRay &ray, const double &distance)
{
    return false;
}

rtVector3d rtObject::origin() const
{
    return _origin;
}

void rtObject::setOrigin(const rtVector3d &origin)
{
    _origin = origin;
}

rtVector3d rtObject::rotation() const
{
    return _rotation;
}

void rtObject::setRotation(const rtVector3d &rotation)
{
    _rotation = rotation;
}

rtVector3d rtObject::scale() const
{
    return _scale;
}

void rtObject::setScale(const rtVector3d &scale)
{
    _scale = scale;
}
