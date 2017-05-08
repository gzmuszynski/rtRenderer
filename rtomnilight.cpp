#include "rtomnilight.h"

rtOmniLight::rtOmniLight(rtVector3d origin): _origin(origin)
{

}

void rtOmniLight::getDirection(const rtVector3d &point,QVector<QPair<rtVector3d*,rtLightIntensity*>*> &lightVectors)
{
    rtVector3d *rayVector = new rtVector3d(point,_origin);
    lightVectors.push_back(new QPair<rtVector3d *, rtLightIntensity *>(rayVector,color));

}
