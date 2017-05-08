#include "rtphong.h"
#include <QtMath>

rtPhong::rtPhong(rtLightIntensity ambient, rtLightIntensity diffuse, rtLightIntensity specular, double glossiness, double refraction, double reflection):
    ambientColor(ambient),
    diffuseColor(diffuse),
    specularColor(specular),
    glossinessCoefficient(glossiness),
    refractionCoefficient(qBound(0.0,refraction,1.0)),
    reflectionCoefficient(qBound(0.0,reflection,1.0))
{

}

rtLightIntensity rtPhong::operator ()(const rtRay &ray, const rtVector3d &point, const rtVector3d &normal, const rtVector3d &coords,
                                      const QVector<rtObject *> &objects, const QVector<rtAbstractLight *> &lights)
{
    rtLightIntensity amb;
    rtLightIntensity diff;
    rtLightIntensity spec;
    rtVector3d viewDirection = -ray.getDirection().normalize();
    for(rtAbstractLight* light:lights){
        amb+= ambientColor*light->getColor();                   // ambient calculation
        QVector<QPair<rtVector3d*,rtLightIntensity*>*> lightVectors;    // getting light vectors (in case of area lights)
        light->getDirection(point,lightVectors);
        if(lightVectors.isEmpty()==false){
            for(QPair<rtVector3d*,rtLightIntensity*>* lightPair:lightVectors){   // calculating diffuse and specular for each light vector
                bool inShadow=false;
                rtVector3d lightVector = *(lightPair->first);
                int i=0;
                rtRay lightRay(point,lightVector);
                while(i<objects.size() && !inShadow){
                    inShadow = objects[i]->isInPath(lightRay,lightVector.length());
                    i++;
                }
                if(!inShadow){
                    rtVector3d lightDirection = lightVector.normalize();
                    rtLightIntensity lightColor = *(lightPair->second);
                    double diffuseValue = lightDirection.dotProduct(normal);    // lambertian diffuse
                    if(diffuseValue>0)
                        diff+= diffuseColor*lightColor*diffuseValue;

                    rtVector3d halfVector = (lightDirection+viewDirection).normalize();
                    double specAngle = halfVector.dotProduct(normal);
                    if(specAngle>0)
                        spec+= specularColor*lightColor*qPow(specAngle,glossinessCoefficient);
                }
            }
            diff/=lightVectors.size();
            spec/=lightVectors.size();
        }
    }
    rtLightIntensity final = amb+diff+spec;
    if(ray.getBounces()>0){
        if(reflectionCoefficient>0){
            rtLightIntensity reflection;
            rtVector3d norm = normal;
            rtVector3d dir = ray.getDirection();
            rtVector3d reflected = dir - (norm*(norm.dotProduct(dir))*2);
            rtRay newRay(point,reflected,ray.getBounces()-1);
            double distance = 1000.0;
            reflection = newRay(objects,lights,distance,0.0001,1000.0);
            final= final+reflection*reflectionCoefficient;
        }
        if(refractionCoefficient>0){
            rtLightIntensity refraction;
            rtVector3d norm = normal;
            rtVector3d dir = ray.getDirection();
            double deltaS = 1.0;
            double deltaT = 1.1;
            double dirNorm = norm.dotProduct(dir);
            double st = deltaS/deltaT;
            rtVector3d b = dir - (norm*dirNorm);
            double sqrt = 1-((st*st)*(1-dirNorm*dirNorm));
            rtVector3d refracted = (b*st)-
                    (norm*qSqrt(sqrt));
            rtRay newRay(point,refracted,ray.getBounces()-1);
            double distance = 1000.0;
            refraction = newRay(objects,lights,distance,0.1,1000.0);
            final= final+refraction*refractionCoefficient;
        }
        final/=(1+reflectionCoefficient+refractionCoefficient);
    }
    return rtLightIntensity(final);
}
