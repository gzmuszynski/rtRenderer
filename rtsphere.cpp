#include "rtsphere.h"
#include "rtray.h"
#include "rtmaterial.h"
#include <QtMath>

rtSphere::rtSphere(double x, double y, double z, double radius): rtObject(x,y,z)
{
    this->radius = radius;
}

rtLightIntensity rtSphere::intersect(const rtRay &ray, double &cur_distance, const QVector<rtObject *> objects, const QVector<rtAbstractLight*> &lights)
{
    double a = ray.getDirection().dotProduct(ray.getDirection());
    if(a==0)
        return rtLightIntensity(0,0,0);
    rtVector3d oc = rtVector3d(ray.getOrigin(),_origin);
    double b = 2*ray.getDirection().dotProduct(oc);
    double c = oc.dotProduct(oc)-radius*radius;
    double delta = b*b-4*a*c;
    if(delta<0)
        return rtLightIntensity(0,0,0);
    else{
        if(delta>0){
                double t1 = (b - std::sqrt(delta))/(2*a);
                double t2 = (b + std::sqrt(delta))/(2*a);
                if(t1*t2>0.0001){
                    cur_distance = std::min(t1,t2);
                }
        }
        else{
            double t = b/(2*a);
            if(t>0.0001) cur_distance = t;
        }
        rtVector3d hit = ray(cur_distance);
        rtVector3d hitRelative = (hit-_origin).normalize();
        double u = 1.0/(2*M_PI)*(qAtan(hitRelative.getX()/hitRelative.getY()))+0.5;
        double v = -hitRelative.getZ()*0.5+0.5;
        rtVector3d coords(u,v,1);
        rtVector3d normal = rtVector3d(_origin,hit).normalize();
        return (*material)(ray, hit, normal, coords,objects,lights);
    }
}

bool rtSphere::isInPath(const rtRay &ray, const double &distance)
{
    double cur_distance = distance;
    double a = ray.getDirection().dotProduct(ray.getDirection());
    if(a==0)
        return false;
    rtVector3d oc = rtVector3d(ray.getOrigin(),_origin);
    double b = 2*ray.getDirection().dotProduct(oc);
    double c = oc.dotProduct(oc)-radius*radius;
    double delta = b*b-4*a*c;
    if(delta<0)
        return false;
    else{
        if(delta>0){
                double t1 = (b - std::sqrt(delta))/(2*a);
                double t2 = (b + std::sqrt(delta))/(2*a);
//                if(std::min(t1,t2)>0){
                if(t1*t2>0.0001)
                    cur_distance = std::min(t1,t2);
                else
                    return false;
//                }
//                else if(std::max(t1,t2)>0){
//                    cur_distance = std::max(t1,t2);

//                }
        }
        else{
            double t = b/(2*a);
            if(t>0.0001) cur_distance = t;
        }
        if(cur_distance<distance && cur_distance>0.0001)
            return true;
    }
    return false;
}

