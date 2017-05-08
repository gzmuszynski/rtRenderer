#ifndef RTPOINT_H
#define RTPOINT_H


class rtPoint
{
public:
    rtPoint(double x, double _y, double _z);
    double getX() const;
    double getY() const;
    double getZ() const;

protected:
    const double x;
    const double y;
    const double z;
};

#endif // RTPOINT_H
