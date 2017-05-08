#ifndef RTVECTOR2D_H
#define RTVECTOR2D_H


class rtVector2d
{
public:
    rtVector2d(double _x, double _y);
    double getX() const;
    double getY() const;

    double length();
    double LengthSquare();
    double dotProduct(rtVector2d vec);
    rtVector2d normalize();
    rtVector2d multiply(double a);
    rtVector2d subtract(double a);
    rtVector2d add(double a);
    rtVector2d subtract(rtVector2d vec);
    rtVector2d add(rtVector2d vec);

protected:
    const double x;
    const double y;
};

#endif // RTVECTOR2D_H
