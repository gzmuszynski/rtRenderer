#ifndef RTPERSPECTIVECAMERAMULTITHREAD_H
#define RTPERSPECTIVECAMERAMULTITHREAD_H

#include "rtperspectivecamera.h"
#include <QRunnable>



class rtPerspectiveCameraMultiThread : public rtPerspectiveCamera
{
public:
    class rtCameraInfo{
    public:
        rtCameraInfo(const rtVector3d &origin, const rtVector3d &direction, const double &near,
                     const double &far, const double &fov, const int &width, const int &height, const int &msaa,
                     const rtVector3d &xVector, const rtVector3d &yVector, const double &step,
                     const QVector<rtObject *> &scene, const QVector<rtAbstractLight *> &lights);

        rtVector3d xVector() const;
        rtVector3d yVector() const;
        double step() const;
        QVector<rtObject *> scene() const;
        QVector<rtAbstractLight *> lights() const;
        int msaa() const;
        rtVector3d origin() const;
        rtVector3d direction() const;
        double near() const;
        double far() const;
        double fov() const;
        int width() const;
        int height() const;
    private:
        const rtVector3d _xVector;
        const rtVector3d _yVector;
        const double _step;
        const QVector<rtObject *> _scene;
        const QVector<rtAbstractLight *> _lights;
        const int _msaa;
        const rtVector3d _origin;
        const rtVector3d _direction;
        const double _near;
        const double _far;
        const double _fov;
        const int _width;
        const int _height;
    };


    rtPerspectiveCameraMultiThread(rtImageWindow *parent, rtVector3d origin, rtVector3d direction, double near, double far, double fov, rtVector3d up);

private:
    void renderPixel(int y, const rtCameraInfo &info, rtFilm &film);
    rtFilm* film;
    // rtAbstractCamera interface
public:
    rtFilm &operator ()(rtFilm &film, const QVector<rtObject *> &scene, const QVector<rtAbstractLight *> &lights, int msaa);

    // QRunnable interface
public:
};

#endif // RTPERSPECTIVECAMERAMULTITHREAD_H
