#ifndef RTPHONG_H
#define RTPHONG_H

#include "rtmaterial.h"



class rtPhong : public rtMaterial
{
public:
    rtPhong(rtLightIntensity ambient, rtLightIntensity diffuse, rtLightIntensity specular, double glossiness = 1, double refraction=0, double reflection=0);
protected:
    rtLightIntensity ambientColor;
    rtLightIntensity diffuseColor;
    rtLightIntensity specularColor;
    double glossinessCoefficient;
    double refractionCoefficient;
    double reflectionCoefficient;

    // rtMaterial interface
public:
    rtLightIntensity operator ()(const rtRay &ray, const rtVector3d &point, const rtVector3d &normal,const rtVector3d &coords, const QVector<rtObject *> &objects, const QVector<rtAbstractLight *> &lights);
};

#endif // RTPHONG_H
