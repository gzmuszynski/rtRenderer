#include "rtplane.h"
#include "rtmaterial.h"


rtPlane::rtPlane(rtVector3d normal, double d): rtObject(rtRay(normal,rtVector3d(0,0,0))(d)), _normal(normal.normalize()), _distance(d)
{
    rtVector3d flat(0,0,1);
    UVside = normal.crossProduct(flat);
    UVside = UVside.normalize();
    UVup = UVside.crossProduct(_normal);
    UVup = UVup.normalize();
    UVscale = 20;
}

rtPlane::rtPlane(double a, double b, double c, double d): rtObject(rtRay(rtVector3d(a,b,c),rtVector3d(0,0,0))(d)), _normal(rtVector3d(a,b,c).normalize()), _distance(d)
{
    rtVector3d flat(0,0,1);
    rtVector3d normal = _normal;
    UVside = normal.crossProduct(flat);
    UVside = UVside.normalize();
    UVup = UVside.crossProduct(_normal);
    UVup = UVup.normalize();
    UVscale = 20;
}

rtLightIntensity rtPlane::intersect(const rtRay &ray, double &cur_distance, const QVector<rtObject *> objects, const QVector<rtAbstractLight*> &lights)
{
    rtVector3d norm = _normal;

    double up = norm.dotProduct(ray.getOrigin());
    double down = norm.dotProduct(ray.getDirection());
    double calc = (_distance-up)/down;
    cur_distance = calc>0?calc:cur_distance;
    rtVector3d hit = ray(cur_distance);
//    rtVector3d hitFromOrigin = rtVector3d(rtVector3d(0,0,0),hit);
    double side = hit.dotProduct(UVside);
    double up2 = hit.dotProduct(UVup);
    rtVector3d coords = rtVector3d((-hit.getX()/UVscale+1)/2,(-hit.getY()/UVscale-1)/2,1);
    return (*material)(ray, hit, norm,coords,objects,lights);
}

bool rtPlane::isInPath(const rtRay &ray, const double &distance)
{
    rtVector3d norm = _normal;
    double up = norm.dotProduct(ray.getOrigin());
    double down = norm.dotProduct(ray.getDirection());
    double calc = (_distance-up)/down;
    if(calc>0.0001 && calc<distance)
        return true;
    return false;

}

