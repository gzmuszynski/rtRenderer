#ifndef RTORTOGRAPHICCAMERA_H
#define RTORTOGRAPHICCAMERA_H

#include <rtabstractcamera.h>



class rtOrtographicCamera : public rtAbstractCamera
{
public:
    rtOrtographicCamera(rtImageWindow* parent, rtVector3d origin, rtVector3d direction, double near, double far, double size, rtVector3d up);

    // rtAbstractCamera interface
public:
    rtFilm &operator ()(rtFilm &film,const QVector<rtObject*> &scene, const QVector<rtAbstractLight*> &lights, int msaa);

    double size() const;
protected:
    double _size;
};

#endif // RTORTOGRAPHICCAMERA_H
