#include <QtTest/QtTest>
#include "rttestplane.h"
#include "rttestray.h"
#include "rttestsphere.h"
#include "rttestvector3d.h"

int main(int argc,char **argv){
    QApplication app(argc,argv);
    rtTestVector3d testVector3d;
    rtTestSphere testSphere;
    rtTestRay testRay;
    rtTestPlane testPlane;
    return QTest::qExec(&testVector3d,argc,argv) |
            QTest::qExec(&testSphere,argc,argv) |
            QTest::qExec(&testRay,argc,argv)|
            QTest::qExec(&testPlane,argc,argv);
}
