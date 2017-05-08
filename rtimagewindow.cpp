#include "rtabstractcamera.h"
#include "rtimagewindow.h"
#include "rtmesh.h"
#include "rtortographiccamera.h"
#include "rtperspectivecamera.h"
#include "rtplane.h"
#include "rtsphere.h"
#include "ui_rtimagewindow.h"
#include <QDateTime>
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QtDebug>
#include "rtarealight.h"
#include "rtmaterial.h"
#include "rtperspectivecameramultithread.h"
#include "rtphong.h"
#include "rtphongtextured.h"

rtImageWindow::rtImageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rtImageWindow)
{
    ui->setupUi(this);
}

rtImageWindow::~rtImageWindow()
{
    delete ui;
}

void rtImageWindow::update(rtFilm &film)
{
    image = (QImage)film;
    depth = film.fromDepth();
    ui->graphicsView->setScene(new QGraphicsScene());
    ui->graphicsView->scene()->addItem(new QGraphicsPixmapItem(QPixmap::fromImage(image)));
    ui->graphicsView_2->setScene(new QGraphicsScene());
    ui->graphicsView_2->scene()->addItem(new QGraphicsPixmapItem(QPixmap::fromImage(depth)));

}

void rtImageWindow::on_actionZapisz_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,QString("Zapisz jako"),QString("."),QString("*.bmp"));
    switch(ui->tabWidget->currentIndex()){
    case 0: {
        image.save(filename);
        break;
    }
    case 1: {
        depth.save(filename);
        break;
    }
    }
}

void rtImageWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->label->setText(QString("MSAA: %1x").arg(std::pow(2,position)));
}

void rtImageWindow::on_pushButton_clicked()
{
    rtAbstractCamera* cam;
    if(ui->radioButton_2->isChecked()){
        double fov = ui->fovSlider->value();
        cam = new rtPerspectiveCamera(this,rtVector3d(0,-20,20),rtVector3d(0,1,-1),ui->nearSpinBox->value(),ui->farSpinBox->value(),fov,rtVector3d(0,0,1));
    }
    if(ui->radioButton->isChecked()){
        cam = new rtOrtographicCamera(this,rtVector3d(0,-20,0),rtVector3d(0,1,0),ui->nearSpinBox->value(),ui->farSpinBox->value(),20,rtVector3d(0,0,1));
    }
    if(ui->radioButton_3->isChecked()){
        double fov = ui->fovSlider->value();
        cam = new rtPerspectiveCameraMultiThread(this,rtVector3d(0,-20,20),rtVector3d(0,1,-1),ui->nearSpinBox->value(),ui->farSpinBox->value(),fov,rtVector3d(0,0,1));
    }
    QVector<rtObject*> objects;
    QString filename = QFileDialog::getOpenFileName(this,QString("Otwórz Obiekt OBJ"),QString("../Raytracer"),QString("*.obj"));
    QVector<rtMesh*> meshList = rtMesh::fromOBJ(filename);
    objects.push_back(meshList[0]);
    objects[0]->setMaterial(new rtPhongTextured(QImage("../Raytracer/earthlights1k.jpg"),
                                                QImage("../Raytracer/earthmap1k.jpg"),
                                                QImage("../Raytracer/earthspec1k.jpg"),10,1.0));
//    objects[0]->setMaterial(new rtPhong(rtLightIntensity(0.2,0.1,0.1),rtLightIntensity(0.5,0.1,0.1),rtLightIntensity(1,1,0),50));
    objects.push_back(new rtSphere(20,0,0,5));
    objects[1]->setMaterial(new rtPhongTextured(QImage("../Raytracer/earthlights1k.jpg"),
                                                QImage("../Raytracer/earthmap1k.jpg"),
                                                QImage("../Raytracer/earthspec1k.jpg"),10,0.0));
//    objects[1]->setMaterial(new rtPhong(rtLightIntensity(0.1,0.1,0.1),rtLightIntensity(0.1,0.5,0.1),rtLightIntensity(0.5,0,0),10,0.0));
    objects[0]->setOrigin(rtVector3d(0,0,-5));
    objects.push_back(new rtSphere(-20,0,0,5));
    objects[2]->setMaterial(new rtPhong(rtLightIntensity(0.1,0.1,0.1),rtLightIntensity(0.1,0.0,0.5),rtLightIntensity(0.0,0.5,0),40,0.0,0.1));
    objects.push_back(new rtSphere(0,-10,0,1));
    objects[3]->setMaterial(new rtPhong(rtLightIntensity(0.1,0.1,0.1),rtLightIntensity(0.1,0.5,0.5),rtLightIntensity(1,1,1),80));
    objects.push_back(new rtPlane(0,0,1,-5));
    objects[4]->setMaterial(new rtPhongTextured(QImage("../Raytracer/ambient.jpg"),
                                                QImage("../Raytracer/UV-testmap.jpg"),
                                                QImage("../Raytracer/specular.jpg"),10,0.0,1.0));
//    objects[4]->setMaterial(new rtPhong(rtLightIntensity(0.1,0.1,0.1),rtLightIntensity(0.2,0.2,0.2),rtLightIntensity(0,0,0),80));
    int width = ui->graphicsView->size().width()-2;
    int height = ui->graphicsView->size().height()-2;
    int samplesPerPixel = pow(2,ui->horizontalSlider->value());

    QVector<rtAbstractLight*> lights;
    lights.push_back(new rtAreaLight(rtVector3d(10,-10,20),rtVector3d(0,1,0),rtVector3d(0,0,-1),10,10));
    rtFilm film(width,height);
    QTime timeBefore = QTime::currentTime();
    film = (*cam)(film,objects,lights,samplesPerPixel);
    QTime timeAfter = QTime::currentTime();
    ui->statusbar->showMessage(QString("Czas renderingu: %1ms").arg(timeBefore.msecsTo(timeAfter)));
    update(film);
}

void rtImageWindow::on_fovSlider_sliderMoved(int position)
{
    ui->label_4->setText(QString("FOV: %1").arg(position));
}

void rtImageWindow::on_radioButton_toggled(bool checked)
{
    ui->label_4->setEnabled(!checked);
    ui->fovSlider->setEnabled(!checked);
}
