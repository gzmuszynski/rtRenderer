#include "rtdirectionallight.h"

rtDirectionalLight::rtDirectionalLight(rtVector3d *direction): _direction(direction)
{

}

void rtDirectionalLight::getDirection(const rtVector3d &point, QVector<QPair<rtVector3d *, rtLightIntensity *> *> &lightVectors)
{
    lightVectors.push_back(new QPair<rtVector3d *, rtLightIntensity *>(_direction,color));
}
