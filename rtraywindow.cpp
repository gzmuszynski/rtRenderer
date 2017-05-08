#include "rtraywindow.h"
#include "rtplane.h"
#include "rtray.h"
#include "rtvector3d.h"
#include "rtsphere.h"
#include "ui_rtraywindow.h"

rtRayWindow::rtRayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rtRayWindow)
{
    ui->setupUi(this);
}

rtRayWindow::~rtRayWindow()
{
    delete ui;
}

void rtRayWindow::on_calculateButton_clicked()
{
    QVector<rtObject*> v1;
    QVector<rtObject*> v2;
    QVector<rtObject*> v3;
    v1.push_back(new rtSphere(ui->sphereXSpinBox->value(),
                              ui->sphereYSpinBox->value(),
                              ui->sphereZSpinBox->value(),
                              ui->sphereRadiusSpinBox->value()));
    v2.push_back(new rtPlane(ui->sphereXSpinBox_2->value(),
                             ui->sphereYSpinBox_2->value(),
                             ui->sphereZSpinBox_2->value(),
                             ui->sphereRadiusSpinBox_2->value()));
    v3.push_back(v1[0]);
    v3.push_back(v2[0]);

    rtRay r1(rtVector3d(ui->r1XSpinBox->value(),
                        ui->r1YSpinBox->value(),
                        ui->r1ZSpinBox->value()),
             rtVector3d(ui->r1DirXSpinBox->value(),
                        ui->r1DirYSpinBox->value(),
                        ui->r1DirZSpinBox->value()).normalize());
    rtRay r2(rtVector3d(ui->r2XSpinBox->value(),
                        ui->r2YSpinBox->value(),
                        ui->r2ZSpinBox->value()),
             rtVector3d(ui->r2DirXSpinBox->value(),
                        ui->r2DirYSpinBox->value(),
                        ui->r2DirZSpinBox->value()).normalize());
    rtRay r3(rtVector3d(ui->r3XSpinBox->value(),
                        ui->r3YSpinBox->value(),
                        ui->r3ZSpinBox->value()),
             rtVector3d(ui->r3DirXSpinBox->value(),
                        ui->r3DirYSpinBox->value(),
                        ui->r3DirZSpinBox->value()).normalize());
    double distance;
//    QString textR1 = QString("R1 vs Sfera: %1, głębokość: %2\n").arg(r1(v1,distance,1.0,40.0)).arg(distance);
//    QString textR2 = QString("R2 vs Sfera: %1, głębokość: %2\n").arg(r2(v1,distance,1.0,40.0)).arg(distance);
//    QString textR3 = QString("R3 vs Sfera: %1, głębokość: %2\n").arg(r3(v1,distance,1.0,40.0)).arg(distance);
//    QString textR1Plane = QString("R1 vs Płaszczyzna: %1, głębokość: %2\n").arg(r1(v2,distance,1.0,40.0)).arg(distance);
//    QString textR2Plane = QString("R2 vs Płaszczyzna: %1, głębokość: %2\n").arg(r2(v2,distance,1.0,40.0)).arg(distance);
//    QString textR3Plane = QString("R3 vs Płaszczyzna: %1, głębokość: %2\n").arg(r3(v2,distance,1.0,40.0)).arg(distance);
//    QString textR1All = QString("R1 vs Reszta świata: %1, głębokość: %2\n").arg(r1(v3,distance,1.0,40.0)).arg(distance);
//    QString textR2All = QString("R2 vs Reszta świata: %1, głębokość: %2\n").arg(r2(v3,distance,1.0,40.0)).arg(distance);
//    QString textR3All = QString("R3 vs Reszta świata: %1, głębokość: %2\n").arg(r3(v3,distance,1.0,40.0)).arg(distance);
//    QString final = textR1+textR2+textR3+
//            textR1Plane+textR2Plane+textR3Plane+
//            textR1All+textR2All+textR3All;
//    ui->textDisplay->setText(final);
}
