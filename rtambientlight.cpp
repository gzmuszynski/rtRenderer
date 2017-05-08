#include "rtambientlight.h"

rtAmbientLight::rtAmbientLight()
{

}

void rtAmbientLight::getDirection(const rtVector3d &point, QVector<QPair<rtVector3d *, rtLightIntensity *> *> &lightVectors)
{
    lightVectors.push_back(new QPair<rtVector3d *, rtLightIntensity *>(new rtVector3d(0,0,0),color));
}
