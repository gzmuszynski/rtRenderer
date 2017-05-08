#include "rtlightintensity.h"
#include "rtray.h"
#include "rtobject.h"

rtRay::rtRay(const rtRay &ray): _origin(ray.getOrigin()), _direction(ray.getDirection())
{

}
rtRay::rtRay(const rtVector3d &origin, const rtVector3d &direction): _origin(origin), _direction(direction)
{

}
rtRay::rtRay(const rtVector3d &origin, const rtVector3d &direction, int bounces): _origin(origin), _direction(direction)
{
    this->bounces = bounces;
}

rtVector3d rtRay::getOrigin() const
{
    return _origin;
}

rtVector3d rtRay::getDirection() const
{
    return _direction;
}

rtVector3d rtRay::operator()(double t) const
{
    return rtVector3d(_origin.getX()+_direction.getX()*t,
                   _origin.getY()+_direction.getY()*t,
                      _origin.getZ()+_direction.getZ()*t);
}

rtRay rtRay::operator -(int i) const
{
    return rtRay(_origin,_direction,bounces-i);
}

bool rtRay::operator ==(int i) const
{
    return bounces==i;
}

rtLightIntensity rtRay::operator()(const QVector<rtObject*> &vec, const QVector<rtAbstractLight*> &lights, double &distance,double near, double far)
{
    distance=far;
    double min_distance=distance;
    rtLightIntensity color(0.0,0.0,0.0,1.0);
    for(rtObject* o:vec){
        rtLightIntensity tmp = o->intersect(*this,distance,vec,lights);
        if(distance<min_distance && distance>near){
            min_distance=distance;
            color = tmp;
        }
        else distance = min_distance;
    }
    return color;
}

int rtRay::getBounces() const
{
    return bounces;
}
