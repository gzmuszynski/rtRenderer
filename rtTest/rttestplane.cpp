#include "rttestplane.h"
#include <QtTest/QtTest>
#include <rtplane.h>


void rtTestPlane::testIntersection()
{
    rtVector3d vec(1,0,0);
    rtRay ray(rtVector3d(0,0,0),vec);
    rtPlane plane(vec,10);
    double distance = 100;
    rtVector3d intersection=plane.intersect(ray,distance);
    QCOMPARE(intersection.getX(),10.0);
    QCOMPARE(intersection.getY(), 0.0);
    QCOMPARE(intersection.getZ(), 0.0);
    QCOMPARE(distance,10.0);
}
