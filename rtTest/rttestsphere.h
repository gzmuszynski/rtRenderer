#ifndef RTTESTSPHERE_H
#define RTTESTSPHERE_H
#include <QObject>

class rtTestSphere : public QObject
{
    Q_OBJECT
private slots:
    void testIntersect();
    void testIntersect2();
};

#endif // RTTESTSPHERE_H
