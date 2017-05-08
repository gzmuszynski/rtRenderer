#ifndef RTTESTPLANE_H
#define RTTESTPLANE_H

#include <QObject>

class rtTestPlane : public QObject
{
    Q_OBJECT
private slots:
    void testIntersection();
};

#endif // RTTESTPLANE_H
