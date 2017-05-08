#include "rtperspectivecamera.h"
#include "rtray.h"
#include <cmath>
#include <QtMath>
#include <QtAlgorithms>
#include "rtimagewindow.h"
#include <QtDebug>

rtPerspectiveCamera::rtPerspectiveCamera(rtImageWindow* parent, rtVector3d origin, rtVector3d direction, double near, double far, double fov, rtVector3d up):
    rtAbstractCamera(parent, origin,direction.normalize(),near,far,up),
    _fov(fov)
{

}

rtFilm &rtPerspectiveCamera::operator ()(rtFilm &film, const QVector<rtObject *> &scene, const QVector<rtAbstractLight*> &lights, int msaa)
{
    if(msaa<1)
        msaa = 1;
    int width = film[0].size();
    int height = film.size();
    double step = _fov/(width*2);
    double fov = 90.0/(2*_fov);
    rtVector3d xOffset = _up.crossProduct(_direction).normalize();
    rtVector3d yOffset = xOffset.crossProduct(_direction).normalize();
    for(int y=0;y<height;y++){
//        qDebug() << &film;
        for(int x=0;x<width;x++){
            film[y][x]=rtLightIntensity();
            film.depth()[y][x] = 0.0;
            for(int n=0;n<msaa;n++)
                for(int m=0;m<msaa;m++){
                    double xVariation = (m-(step/2))/msaa;
                    double yVariation = (n-(step/2))/msaa;
                    rtVector3d moveVecX = xOffset*((x+xVariation-((double)width/2))/(width*fov));
                    rtVector3d moveVecY = yOffset*((y+yVariation-((double)height/2))/(width*fov));
                    rtVector3d moveVec = (moveVecX+moveVecY);
                    rtVector3d point = (_direction+moveVec).normalize();
                    rtRay tmp = rtRay(_origin,point);
                    double distance = 100000.0;
                    film[y][x] += tmp(scene,lights,distance,_near,_far);
                    film.depth()[y][x] += distance;
                }
            film[y][x] /= msaa*msaa;
            double distance = film.depth()[y][x];
            film.depth()[y][x] = 255-((qBound(_near,distance,_far)-_near)/(_far-_near)*255/(msaa*msaa));
//            parent->update(film);
        }
    }
    return film;
}
