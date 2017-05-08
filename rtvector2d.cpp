#include "rtvector2d.h"
#include "cmath"

rtVector2d::rtVector2d(double _x, double _y): x(_x), y(_y)
{

}

double rtVector2d::getY() const
{
    return y;
}

double rtVector2d::length()
{
    return std::sqrt((x*x)+(y*y));
}

double rtVector2d::dotProduct(rtVector2d vec)
{
    return x*vec.x+y*vec.y;
}

rtVector2d rtVector2d::normalize()
{
    double a=length();
    return rtVector2d(x/a,y/a);
}

rtVector2d rtVector2d::multiply(double a)
{
    return rtVector2d(x*a,y*a);
}

rtVector2d rtVector2d::subtract(double a)
{
    return rtVector2d(x-a,y-a);
}

rtVector2d rtVector2d::add(double a)
{
    return rtVector2d(x+a,y+a);
}

rtVector2d rtVector2d::subtract(rtVector2d vec)
{
    return rtVector2d(x-vec.x,y-vec.y);
}

rtVector2d rtVector2d::add(rtVector2d vec)
{
    return rtVector2d(x+vec.x,y+vec.y);
}
double rtVector2d::LengthSquare()
{
    return std::abs((x*x)+(y*y));
}

double rtVector2d::getX() const
{
    return x;
}
