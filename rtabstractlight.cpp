#include "rtabstractlight.h"

rtAbstractLight::rtAbstractLight()
{

}

rtLightIntensity rtAbstractLight::getColor() const
{
    return *color;
}

void rtAbstractLight::setColor(rtLightIntensity *value)
{
    color = value;
}
