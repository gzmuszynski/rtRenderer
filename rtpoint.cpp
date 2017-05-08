#include "rtpoint.h"

rtPoint::rtPoint(double _x, double _y, double _z): x(_x),y(_y),z(_z)
{

}

double rtPoint::getX() const
{
    return x;
}

double rtPoint::getY() const
{
    return y;
}

double rtPoint::getZ() const
{
    return z;
}
