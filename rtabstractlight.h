#ifndef RTABSTRACTLIGHT_H
#define RTABSTRACTLIGHT_H

#include "rtlightintensity.h"
#include "rtvector3d.h"

#include <QVector>

// An Abstract Class for lights

class rtAbstractLight
{
public:
    rtAbstractLight();
    // Main function, that returns vectors of rays from point in to light. Vector is purely for surface lights such as rectangle lights.
    // Along with direction vector of rays, light color is paired.
    virtual void getDirection(const rtVector3d &point, QVector<QPair<rtVector3d*,rtLightIntensity*>*> &lightVectors)=0;

    // Not in use in current build
    rtLightIntensity getColor() const;
    // Sets color of the light
    void setColor(rtLightIntensity *value);

protected:
    rtLightIntensity* color = new rtLightIntensity(1.0,1.0,1.0); // basic parameter that holds the light color in RGB
};

#endif // RTABSTRACTLIGHT_H
