#ifndef RTIMAGE_H
#define RTIMAGE_H

#include "rtlightintensity.h"

#include <QImage>
#include <QVector>

// Film object. Represents a matrix of discrete points, representing light intensity as a floating point value and distance from camera

class rtFilm
{
public:
    rtFilm(int width, int height); // prepare a film of nxm resolution
    rtFilm(QVector<QVector<rtLightIntensity> > image); // prepare a film and copy values of existing film
    QVector<rtLightIntensity>& operator[](int x); // getter of rows from point matrix
    operator QImage(); // Renders points into RGB image
    QImage fromDepth(); // Renders distance (depth) into RGB image
    int size();
    QVector<QVector<double> > &depth();

protected:
    int _width, _height; // resolution of the film
    QVector<QVector<rtLightIntensity> > _image; // point matrix
    QVector<QVector<double> > _depth; // point distances matrix
};

#endif // RTIMAGE_H
