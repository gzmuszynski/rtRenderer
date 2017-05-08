#ifndef RTTESTRAY_H
#define RTTESTRAY_H

#include <QObject>

class rtTestRay : public QObject
{
    Q_OBJECT
private slots:
    void testFunction();
};

#endif // RTTESTRAY_H
