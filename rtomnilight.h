#ifndef RTOMNILIGHT_H
#define RTOMNILIGHT_H

#include "rtabstractlight.h"



class rtOmniLight : public rtAbstractLight
{
public:
    rtOmniLight(rtVector3d origin);

private:
    rtVector3d _origin;
    // rtAbstractLight interface
public:
    void getDirection(const rtVector3d &point,QVector<QPair<rtVector3d*,rtLightIntensity*>*> &lightVectors);
};

#endif // RTOMNILIGHT_H
