#include "rtphongtextured.h"
#include <QtMath>
#include <QtDebug>


int modulo (int a, int b) { return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b; }

double d = 1.0/255;
rtLightIntensity filter(const QImage &image,const rtVector3d &coords){
    int h = image.height();
    int w = image.width();
    double u = coords.getX()*w;
    double v = coords.getY()*h;
    int intU = u;
    int intV = v;
    double remU = u-intU;
    double remV = v-intV;
    double weightU[] = {1-remU,remU};
    double weightV[] = {1-remV,remV};
    QColor col00 = image.pixelColor(modulo(u,w),modulo(v,h));
    QColor col10 = image.pixelColor(modulo(u+1,w),modulo(v,h));
    QColor col01 = image.pixelColor(modulo(u,w),modulo(v+1,h));
    QColor col11 = image.pixelColor(modulo(u+1,w),modulo(v+1,h));
    double red = (weightV[0]*(col00.red()*weightU[0]+col10.red()*weightU[1]))+(weightV[1]*(col01.red()*weightU[0]+col11.red()*weightU[1]));
    double green = (weightV[0]*(col00.green()*weightU[0]+col10.green()*weightU[1]))+(weightV[1]*(col01.green()*weightU[0]+col11.green()*weightU[1]));
    double blue = (weightV[0]*(col00.blue()*weightU[0]+col10.blue()*weightU[1]))+(weightV[1]*(col01.blue()*weightU[0]+col11.blue()*weightU[1]));
//    double red = (col00.red()+col01.red()+col10.red()+col11.red())*d;
//    double green = (col00.green()+col01.green()+col10.green()+col11.green())*d;
//    double blue = (col00.blue()+col01.blue()+col10.blue()+col11.blue())*d;
    return rtLightIntensity(red*d,green*d,blue*d);
}

rtPhongTextured::rtPhongTextured(QImage ambient, QImage diffuse, QImage specular, double glossiness, double refraction, double reflection):
    ambientColor(ambient),
    diffuseColor(diffuse),
    specularColor(specular),
    glossinessCoefficient(glossiness),
    refractionCoefficient(qBound(0.0,refraction,1.0)),
    reflectionCoefficient(qBound(0.0,reflection,1.0))
{

}

rtLightIntensity rtPhongTextured::operator ()(const rtRay &ray, const rtVector3d &point, const rtVector3d &normal, const rtVector3d &coords,
                                              const QVector<rtObject *> &objects, const QVector<rtAbstractLight *> &lights)
{
    rtLightIntensity amb;
    rtLightIntensity diff;
    rtLightIntensity spec;
    rtVector3d viewDirection = -ray.getDirection().normalize();
    for(rtAbstractLight* light:lights){
        rtLightIntensity ambRGB = filter(ambientColor,coords);
        amb+= ambRGB*light->getColor();                   // ambient calculation
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
                    if(diffuseValue>0){
                        rtLightIntensity diffRGB = filter(diffuseColor,coords);
                        diff+= diffRGB*lightColor*diffuseValue;
                    }

                    rtVector3d halfVector = (lightDirection+viewDirection).normalize();
                    double specAngle = halfVector.dotProduct(normal);
                    if(specAngle>0){
                        rtLightIntensity specRGB = filter(specularColor,coords);
                        spec+= specRGB*lightColor*qPow(specAngle,glossinessCoefficient);
                    }

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
            double deltaT = 1.5;
            double dirNorm = dir.dotProduct(norm);
            double st = deltaS/deltaT;
            rtVector3d b =dir - (norm*dirNorm);
            rtVector3d refracted = (b*st)-
                    (norm*qSqrt(1-(st*st)*(1-(dirNorm*dirNorm))));
            rtRay newRay(point,refracted,ray.getBounces()-1);
            double distance = 1000.0;
            refraction = newRay(objects,lights,distance,0.0001,1000.0);
            final= final+refraction*refractionCoefficient;
        }
        final/=(1+reflectionCoefficient+refractionCoefficient);
    }
    return rtLightIntensity(final);
}
