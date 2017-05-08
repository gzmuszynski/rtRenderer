#include "rtfilm.h"

#include <QRgb>

rtFilm::rtFilm(int width, int height): _width(width),_height(height)
{
    for(int y=0;y<height;y++){
        _image.push_back(QVector<rtLightIntensity>());
        _depth.push_back(QVector<double>());
        for(int x=0;x<width;x++){
            _image[y].push_back(rtLightIntensity());
            _depth[y].push_back(0.0);
        }
    }

}

rtFilm::rtFilm(QVector<QVector<rtLightIntensity> > image): _image(image)
{
    _width=image.size();
    _height=image[0].size();
}

QVector<rtLightIntensity> &rtFilm::operator[](int y)
{
    return _image[y];
}

QImage rtFilm::fromDepth()
{
    QImage image(_width,_height,QImage::Format_Grayscale8);
    for(int y=0;y<_height;y++)
        for(int x=0;x<_width;x++)
            image.setPixelColor(x,y,QColor(qRgb(_depth[y][x],_depth[y][x],_depth[y][x])));
    return image;
}

rtFilm::operator QImage()
{
    QImage image(_width,_height,QImage::Format_ARGB32);
    for(int y=0;y<_height;y++)
        for(int x=0;x<_width;x++)
            image.setPixelColor(x,y,QColor::fromRgba((QRgb)_image[y][x]));
    return image;
}

int rtFilm::size()
{
    return _height;
}

QVector<QVector<double> >& rtFilm::depth()
{
    return _depth;
}
