#include "rtpixelthread.h"
#include "rtperspectivecameramultithread.h"

rtPixelThread::rtPixelThread(QObject *parent):QThread(parent)
{

}

void rtPixelThread::render(int x, int y, const rtCameraInfo &cam)
{
//    film[y][x]=rtLightIntensity();
//    for(int n=0;n<msaa;n++)
//        for(int m=0;m<msaa;m++){
//            double xVariation = (m-(step/2))/msaa;
//            double yVariation = (n-(step/2))/msaa;
//            rtVector3d moveVecX = xOffset*((x+xVariation-((double)width/2))/(width*fov));
//            rtVector3d moveVecY = yOffset*((y+yVariation-((double)height/2))/(width*fov));
//            rtVector3d moveVec = (moveVecX+moveVecY);
//            rtVector3d point = (_direction+moveVec).normalize();
//            rtRay tmp = rtRay(_origin,point);
//            double distance = 100000.0;
//            film[y][x] += tmp(scene,lights,distance,_near,_far);
//            film.depth()[y][x] += distance;
//        }
//    film[y][x] /= msaa*msaa;
//    double distance = film.depth()[y][x];
    //    film.depth()[y][x] = 255-((qBound(_near,distance,_far)-_near)/(_far-_near)*255/(msaa*msaa));
}

void rtPixelThread::run()
{

}
