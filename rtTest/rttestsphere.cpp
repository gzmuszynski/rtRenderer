#include "rttestsphere.h"
#include "rtsphere.h"
#include <QtTest/QtTest>
#include "rtray.h"


void rtTestSphere::testIntersect()
{
    rtSphere sphereX(10,0,0,1);
    rtRay rayX(rtVector3d(0,0,0),rtVector3d(1,0,0));
    double distanceX = 10;
    rtVector3d intersectionX= sphereX.intersect(rayX,distanceX);
    QCOMPARE(intersectionX.getX(),9.0);
    QCOMPARE(intersectionX.getY(),0.0);
    QCOMPARE(intersectionX.getZ(),0.0);
    QCOMPARE(distanceX,9.0);

    rtSphere sphereY(0,10,0,1);
    rtRay rayY(rtVector3d(0,0,0),rtVector3d(0,1,0));
    double distanceY = 10;
    rtVector3d intersectionY= sphereY.intersect(rayY,distanceY);
    QCOMPARE(intersectionY.getX(),0.0);
    QCOMPARE(intersectionY.getY(),9.0);
    QCOMPARE(intersectionY.getZ(),0.0);
    QCOMPARE(distanceY,9.0);

    rtSphere sphereZ(0,0,10,1);
    rtRay rayZ(rtVector3d(0,0,0),rtVector3d(0,0,1));
    double distanceZ = 10;
    rtVector3d intersectionZ= sphereZ.intersect(rayZ,distanceZ);
    QCOMPARE(intersectionZ.getX(),0.0);
    QCOMPARE(intersectionZ.getY(),0.0);
    QCOMPARE(intersectionZ.getZ(),9.0);
    QCOMPARE(distanceZ,9.0);
}

void rtTestSphere::testIntersect2()
{
    rtSphere sphere(10,0,0,1);
    rtRay rayTangent(rtVector3d(0,0,1),rtVector3d(1,0,0));
    double distanceTangent = 10;
    rtVector3d intersectionTangent= sphere.intersect(rayTangent,distanceTangent);
    QCOMPARE(intersectionTangent.getX(),10.0);
    QCOMPARE(intersectionTangent.getY(),0.0);
    QCOMPARE(intersectionTangent.getZ(),1.0);
    QCOMPARE(distanceTangent,10.0);

    rtRay rayHalf(rtVector3d(0,0.5,0),rtVector3d(1,0,0));
    double distanceHalf = 10;
    rtVector3d intersectionHalf= sphere.intersect(rayHalf,distanceHalf);
    QCOMPARE((int)(intersectionHalf.getX()*100000),913397);
    QCOMPARE(intersectionHalf.getY(),0.5);
    QCOMPARE(intersectionHalf.getZ(),0.0);
    QCOMPARE((int)(distanceHalf*100000),913397);
}
