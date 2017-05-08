#include "rtvector3d.h"
#include "cmath"

rtVector3d::rtVector3d()
{

}

rtVector3d::rtVector3d(double x, double y, double z): _x(x), _y(y), _z(z)
{

}

rtVector3d::rtVector3d(const rtVector3d &vec): _x(vec.getX()), _y(vec.getY()), _z(vec.getZ())
{

}

rtVector3d::rtVector3d(rtVector3d begin, rtVector3d end): _x(end.getX()-begin.getX()), _y(end.getY()-begin.getY()), _z(end.getZ()-begin.getZ())
{

}

double rtVector3d::getZ() const
{
    return _z;
}

double rtVector3d::length()
{
    return std::sqrt(lengthSquare());
}

double rtVector3d::lengthSquare()
{
    return std::abs((_x*_x)+(_y*_y)+(_z*_z));
}

rtVector3d rtVector3d::crossProduct(const rtVector3d &vec)
{
    return rtVector3d((_y*vec._z)-(_z*vec._y),(_z*vec._x)-(_x*vec._z),(_x*vec._y)-(_y*vec._z));
}

double rtVector3d::dotProduct(const rtVector3d &vec)
{
    return _x*vec._x+_y*vec._y+_z*vec._z;
}

rtVector3d rtVector3d::normalize()
{
    double a=length();
    if(a==0.0) return *this;
    double revA = 1.0/a;
    return rtVector3d(_x*revA,_y*revA,_z*revA);
}

rtVector3d rtVector3d::lerp(const rtVector3d &vec, double a)
{
    return rtVector3d(_x+a*(vec._x-_x),_y+a*(vec._y-_y),_z+a*(vec._z-_z));
}

rtVector3d rtVector3d::operator =(const rtVector3d vec)
{
    _x=vec.getX();
    _y=vec.getY();
    _z=vec.getZ();
    return vec;
}

rtVector3d rtVector3d::operator *(double a)
{
    return rtVector3d(_x*a,_y*a,_z*a);
}

rtVector3d rtVector3d::operator -(double a)
{
    return rtVector3d(_x-a,_y-a,_z-a);
}

rtVector3d rtVector3d::operator -()
{
    return rtVector3d(-_x,-_y,-_z);
}

void rtVector3d::operator +=(rtVector3d vec)
{
    _x+=vec.getX();
    _y+=vec.getY();
    _z+=vec.getZ();
}

rtVector3d rtVector3d::operator +(double a)
{
    return rtVector3d(_x+a,_y+a,_z+a);
}

rtVector3d rtVector3d::operator -(const rtVector3d & vec)
{
    return rtVector3d(_x-vec._x,_y-vec._y,_z-vec._z);
}

rtVector3d rtVector3d::operator +(const rtVector3d &vec)
{
    return rtVector3d(_x+vec._x,_y+vec._y,_z+vec._z);
}

rtVector3d rtVector3d::operator /(double a)
{
    if(a==0.0) throw std::exception("Division by zero");
    double revA = 1/a;
    return rtVector3d(_x*revA,_y*revA,_z*revA);
}

rtVector3d rtVector3d::operator /(const rtVector3d &vec)
{
    rtVector3d vect = rtVector3d(vec);
    double a = vect.length();
    double revA = 1/a;
    return rtVector3d(_x*revA,_y*revA,_z*revA);
}

bool rtVector3d::operator==(const rtVector3d & vec)
{
    return _x==vec._x && _y==vec._y && _z==vec._z;
}

bool rtVector3d::operator!=(const rtVector3d & vec)
{
    return _x!=vec._x || _y!=vec._y || _z!=vec._z;
}

rtVector3d::operator QString()
{
    return QString("v=(%1,%2,%3)").arg(_x).arg(_y).arg(_z);
}

double rtVector3d::getY() const
{
    return _y;
}

double rtVector3d::getX() const
{
    return _x;
}
