#include "rttestvector3d.h"
#include <QtTest/QtTest>
#include <rtvector3d.h>

void rtTestVector3d::testCrossProduct()
{
    rtVector3d testVec1(1,0,0);
    rtVector3d testVec2(0,1,0);
    rtVector3d testVec = testVec1.crossProduct(testVec2);
    QCOMPARE(testVec.getX(), 0.0);
    QCOMPARE(testVec.getY(), 0.0);
    QCOMPARE(testVec.getZ(), 1.0);
}

void rtTestVector3d::testVectorConstructor()
{
    rtVector3d begin(1.0,1.0,1.0);
    rtVector3d end(1.2,1.3,1.4);
    rtVector3d testVec(begin,end);
    QCOMPARE(testVec.getX(), 0.2);
    QCOMPARE(testVec.getY(), 0.3);
    QCOMPARE(testVec.getZ(), 0.4);
}

void rtTestVector3d::testLength()
{
    rtVector3d testVec1(2,0,0);
    rtVector3d testVec2(0,2,0);
    rtVector3d testVec3(0,0,2);
    rtVector3d testVec4(1,1,0);
    rtVector3d testVec5(1,1,1);
    QCOMPARE(testVec1.length(), 2.0);
    QCOMPARE(testVec2.length(), 2.0);
    QCOMPARE(testVec3.length(), 2.0);
    QCOMPARE(testVec4.length(), std::sqrt(2));
    QCOMPARE(testVec5.length(), std::sqrt(3));
}

void rtTestVector3d::testNormalize()
{
    rtVector3d testVec(1,1,1);
    rtVector3d testVecNormalized = testVec.normalize();
    QCOMPARE(testVecNormalized.length(), 1.0);
}
