#ifndef RTAMBIENTLIGHT_H
#define RTAMBIENTLIGHT_H

#include "rtabstractlight.h"

// Ambient Light. Doesn't have a position

class rtAmbientLight : public rtAbstractLight
{
public:
    rtAmbientLight();

    // rtAbstractLight interface
public:
    void getDirection(const rtVector3d &point, QVector<QPair<rtVector3d *, rtLightIntensity *> *> &lightVectors);
};

#endif // RTAMBIENTLIGHT_H
