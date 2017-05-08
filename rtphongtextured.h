#ifndef RTTEXTUREDPHONG_H
#define RTTEXTUREDPHONG_H

#include "rtmaterial.h"



class rtPhongTextured : public rtMaterial
{
public:
    rtPhongTextured(QImage ambient, QImage diffuse, QImage specular, double glossiness = 1, double refraction=0, double reflection=0);
protected:
    QImage ambientColor;
    QImage diffuseColor;
    QImage specularColor;
    double glossinessCoefficient;
    double refractionCoefficient;
    double reflectionCoefficient;
    // rtMaterial interface
public:
    rtLightIntensity operator ()(const rtRay &ray, const rtVector3d &point, const rtVector3d &normal, const rtVector3d &coords, const QVector<rtObject *> &objects, const QVector<rtAbstractLight *> &lights);
};



#endif // RTTEXTUREDPHONG_H
