#ifndef RTTESTVECTOR3D_H
#define RTTESTVECTOR3D_H
#include <QObject>

class rtTestVector3d : public QObject
{
    Q_OBJECT
private slots:
    void testCrossProduct();
    void testVectorConstructor();
    void testLength();
    void testNormalize();
};

#endif // RTTESTVECTOR3D_H
