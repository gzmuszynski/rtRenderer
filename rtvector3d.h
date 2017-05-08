#ifndef RTVECTOR_H
#define RTVECTOR_H

#include "rtpoint.h"

#include <QString>



class rtVector3d
{
public:
    rtVector3d();
    rtVector3d(double x, double y, double z);
    rtVector3d(const rtVector3d& vec);
    rtVector3d(rtVector3d begin, rtVector3d end);

    double getX() const;
    double getY() const;
    double getZ() const;

    double length();
    double lengthSquare();
    rtVector3d crossProduct(const rtVector3d &vec);
    double dotProduct(const rtVector3d &vec);
    rtVector3d normalize();
    rtVector3d lerp(const rtVector3d & vec, double a);
    rtVector3d operator =(const rtVector3d vec);
    rtVector3d operator *(double a);
    rtVector3d operator -(double a);
    rtVector3d operator -();
    void operator +=(rtVector3d vec);
    rtVector3d operator +(double a);
    rtVector3d operator -(const rtVector3d &vec);
    rtVector3d operator +(const rtVector3d & vec);
    rtVector3d operator /(double a);
    rtVector3d operator /(const rtVector3d &vec);
    bool operator==(const rtVector3d & vec);
    bool operator!=(const rtVector3d & vec);
    operator QString();


protected:
    double _x;
    double _y;
    double _z;
};

#endif // RTVECTOR_H
