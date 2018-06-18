#ifndef RTAREALIGHT_H
#define RTAREALIGHT_H

#include <rtabstractlight.h>

// Rectangle Area light. Generates direction from given point to random point in light's area.

class rtAreaLight : public rtAbstractLight
{
public:
    rtAreaLight(rtVector3d origin, rtVector3d up, rtVector3d direction, double width, double height);
private:
    rtVector3d _origin; // origin point
    rtVector3d _up; // orthonormal Y, controls barrel roll of the light's shape
    rtVector3d _direction; // orthonormal normal vector
    double _width; // width of the rectangle
    double _height; // height of the rectangle
    rtVector3d bottomLeft; // precalculated origin of the orthonormal origin point
    rtVector3d stepX, stepY; // precalculated steps for the calculation of random points
    // rtAbstractLight interface
	chuj();
public:
    void getDirection(const rtVector3d &point, QVector<QPair<rtVector3d *, rtLightIntensity *> *> &lightVectors);
};

#endif // RTAREALIGHT_H
