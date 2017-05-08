#ifndef RTDIRECTIONALLIGHT_H
#define RTDIRECTIONALLIGHT_H

#include "rtabstractlight.h"

// Directional light. Doesn't have an origin, lights in constant direction. Rough approximation of sunlight.

class rtDirectionalLight : public rtAbstractLight
{
public:
    rtDirectionalLight(rtVector3d *direction);

protected:
    rtVector3d *_direction; // constant light direction
    // rtAbstractLight interface
public:
    void getDirection(const rtVector3d &point, QVector<QPair<rtVector3d *, rtLightIntensity *> *> &lightVectors);
};

#endif // RTDIRECTIONALLIGHT_H
