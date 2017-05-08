#include "rtortographiccamera.h"
#include "rtray.h"
#include <QtAlgorithms>
#include "rtimagewindow.h"

rtOrtographicCamera::rtOrtographicCamera(rtImageWindow* parent, rtVector3d origin, rtVector3d direction, double near, double far, double size, rtVector3d up):
    rtAbstractCamera(parent, origin,direction,near,far,up),
    _size(size!=0?size:1.0)
{

}

rtFilm &rtOrtographicCamera::operator ()(rtFilm &film,const QVector<rtObject *> &scene, const QVector<rtAbstractLight *> &lights, int msaa)
{
    if(msaa<1)
        msaa = 1;
    int width = film[0].size();
    int height = film.size();
    double step = _size/(width);
    rtVector3d xOffset = _up.crossProduct(_direction).normalize();
    rtVector3d yOffset = xOffset.crossProduct(_direction).normalize();
    rtVector3d coruscant = _origin+(xOffset*(width*step/2))-(yOffset*(height*step/2));
    for(int y=0;y<height;y++)
        for(int x=0;x<width;x++){
            film[y][x]=rtLightIntensity();
            for(int n=0;n<msaa;n++)
                for(int m=0;m<msaa;m++){
                    double xVariation = (m-(step/2))/msaa;
                    double yVariation = (n-(step/2))/msaa;
                    rtVector3d point = coruscant-(xOffset*((x+xVariation)*step))+(yOffset*((y+yVariation)*step));
                    rtRay tmp = rtRay(point,_direction);
                    double distance = 100000.0;
                    film[y][x] += tmp(scene,lights,distance,_near,_far);
                    film.depth()[y][x] += distance;
                }
            film[y][x] /= msaa*msaa;
            double distance = film.depth()[y][x];
            film.depth()[y][x] = 255-((qBound(_near,distance,_far)-_near)/(_far-_near)*255/(msaa*msaa));
//            parent->update(film);
        }
    return film;
}

double rtOrtographicCamera::size() const
{
    return _size;
}
