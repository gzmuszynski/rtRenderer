#include "rtarealight.h"
#include <QtAlgorithms>
#include <QDateTime>

rtAreaLight::rtAreaLight(rtVector3d origin, rtVector3d up, rtVector3d direction, double width, double height):
    _origin(origin), _up(up), _width(width), _height(height), _direction(direction)
{
    stepX = _direction.crossProduct(_up).normalize();
    stepY = _up.normalize();
    bottomLeft = rtVector3d(_origin-(stepY*(_height*0.5))-(stepX*(_width*0.5)));
}

void rtAreaLight::getDirection(const rtVector3d &point, QVector<QPair<rtVector3d *, rtLightIntensity *> *> &lightVectors)
{
//    rtVector3d topLeft = bottomLeft + (stepY*_height);
//    rtVector3d bottomRight = bottomLeft + (stepX*_width);
//    rtVector3d topRight = topLeft + (stepX*_width);
    //rtLightIntensity* colorU = new rtLightIntensity(color);
//    lightVectors.push_back(new QPair<rtVector3d *, rtLightIntensity *>(new rtVector3d(point,bottomLeft),colorU));
//    lightVectors.push_back(new QPair<rtVector3d *, rtLightIntensity *>(new rtVector3d(point,topLeft),colorU));
//    lightVectors.push_back(new QPair<rtVector3d *, rtLightIntensity *>(new rtVector3d(point,bottomRight),colorU));
//    lightVectors.push_back(new QPair<rtVector3d *, rtLightIntensity *>(new rtVector3d(point,topRight),colorU));

    for(int i=0; i<16;i++){
        double x = (qrand()*_width/RAND_MAX);
        double y = (qrand()*_height/RAND_MAX);
        rtVector3d lightVector = bottomLeft+(stepY*y)+(stepX*x);
        lightVectors.push_back(new QPair<rtVector3d *, rtLightIntensity *>(new rtVector3d(point,lightVector),color));
    }
}
