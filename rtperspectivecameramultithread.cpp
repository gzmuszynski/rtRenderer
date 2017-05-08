#include "rtperspectivecameramultithread.h"
#include "rtpixelthread.h"
#include "rtray.h"
#include <QtConcurrent/QtConcurrent>
#include <QtDebug>

rtPerspectiveCameraMultiThread::rtPerspectiveCameraMultiThread(rtImageWindow *parent,
                                                               rtVector3d origin,
                                                               rtVector3d direction,
                                                               double near,
                                                               double far,
                                                               double fov,
                                                               rtVector3d up):
    rtPerspectiveCamera(parent,origin,direction,near,far,fov,up)
{

}

void rtPerspectiveCameraMultiThread::renderPixel(int y, const rtPerspectiveCameraMultiThread::rtCameraInfo &info, rtFilm &film)
{
    int width = info.width();
    double step = info.step();
    int msaa = info.msaa();
    double fov = info.fov();
    int height = info.height();
    double near = info.near();
    double far = info.far();
    for(int x=0;x<width;x++){
        film[y][x]=rtLightIntensity();
        film.depth()[y][x] = 0.0;
        for(int n=0;n<msaa;n++)
            for(int m=0;m<msaa;m++){
                double xVariation = (m-(step/2))/msaa;
                double yVariation = (n-(step/2))/msaa;
                rtVector3d moveVecX = info.xVector()*((x+xVariation-((double)width/2))/(width*fov));
                rtVector3d moveVecY = info.yVector()*((y+yVariation-((double)height/2))/(width*fov));
                rtVector3d moveVec = (moveVecX+moveVecY);
                rtVector3d point = (info.direction()+moveVec).normalize();
                rtRay tmp = rtRay(info.origin(),point,2);
                double distance = 100000.0;
                film[y][x] += tmp(info.scene(),info.lights(),distance,near,far);
                film.depth()[y][x] += distance;
            }
        film[y][x] /= msaa*msaa;
        double distance = film.depth()[y][x];
        film.depth()[y][x] = 255-((qBound(near,distance,far)-near)/(far-near)*255/(msaa*msaa));
    }
}


rtFilm &rtPerspectiveCameraMultiThread::operator ()(rtFilm &film, const QVector<rtObject *> &scene, const QVector<rtAbstractLight *> &lights, int msaa)
{
    if(msaa<1)
        msaa = 1;
    int width = film[0].size();
    int height = film.size();
    double step = _fov/(width*2);
    double fov = 90.0/(2*_fov);
    rtVector3d xVector = _up.crossProduct(_direction).normalize();
    rtVector3d yVector = xVector.crossProduct(_direction).normalize();
    rtCameraInfo info(_origin,_direction,_near,_far,fov,width,height,msaa,xVector,yVector,step,scene,lights);
    for(int y=0;y<height;y++){
        QtConcurrent::run(this,&rtPerspectiveCameraMultiThread::renderPixel,y,std::ref(info),std::ref(film));
    }
    QThreadPool::globalInstance()->waitForDone();
    return film;
}


rtVector3d rtPerspectiveCameraMultiThread::rtCameraInfo::xVector() const
{
    return _xVector;
}

rtVector3d rtPerspectiveCameraMultiThread::rtCameraInfo::yVector() const
{
    return _yVector;
}

double rtPerspectiveCameraMultiThread::rtCameraInfo::step() const
{
    return _step;
}

QVector<rtObject *> rtPerspectiveCameraMultiThread::rtCameraInfo::scene() const
{
    return _scene;
}

QVector<rtAbstractLight *> rtPerspectiveCameraMultiThread::rtCameraInfo::lights() const
{
    return _lights;
}

int rtPerspectiveCameraMultiThread::rtCameraInfo::msaa() const
{
    return _msaa;
}

rtVector3d rtPerspectiveCameraMultiThread::rtCameraInfo::origin() const
{
    return _origin;
}

rtVector3d rtPerspectiveCameraMultiThread::rtCameraInfo::direction() const
{
    return _direction;
}

double rtPerspectiveCameraMultiThread::rtCameraInfo::near() const
{
    return _near;
}

double rtPerspectiveCameraMultiThread::rtCameraInfo::far() const
{
    return _far;
}

double rtPerspectiveCameraMultiThread::rtCameraInfo::fov() const
{
    return _fov;
}

int rtPerspectiveCameraMultiThread::rtCameraInfo::width() const
{
    return _width;
}

int rtPerspectiveCameraMultiThread::rtCameraInfo::height() const
{
    return _height;
}

rtPerspectiveCameraMultiThread::rtCameraInfo::rtCameraInfo(const rtVector3d &origin, const rtVector3d &direction,
                                                           const double &near, const double &far, const double &fov, const int &width, const int &height, const int &msaa, const rtVector3d &xVector,
                                                           const rtVector3d &yVector, const double &step,
                                                           const QVector<rtObject *> &scene, const QVector<rtAbstractLight *> &lights):
    _origin(origin), _direction(direction), _near(near), _far(far), _fov(fov), _msaa(msaa), _xVector(xVector), _yVector(yVector), _step(step),
    _scene(scene), _lights(lights), _width(width), _height(height)
{

}
