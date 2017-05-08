#include "rttestray.h"
#include <QtTest/QtTest>
#include <rtray.h>


void rtTestRay::testFunction()
{
    rtRay ray(rtVector3d(0,0,0),rtVector3d(1,0,0));
    rtVector3d finalLocation = ray(10);
    QCOMPARE(finalLocation.getX(), 10.0);
    QCOMPARE(finalLocation.getY(), 0.0);
    QCOMPARE(finalLocation.getZ(), 0.0);
}
