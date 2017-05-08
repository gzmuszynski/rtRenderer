#ifndef RTMESH_H
#define RTMESH_H

#include "rtobject.h"

#include <QVector>

// Basic class for representing 3D models as a vertex-edge-triangle mesh from .OJB file.

class rtMesh : public rtObject
{
public:
    class rtTriangle{
    public:
        rtTriangle(rtVector3d *&v1, rtVector3d *&v2, rtVector3d *&v3); // creates a triangle from 3 vertices
        bool intersect(const rtRay &ray, double &cur_distance); // for shadow checks
        bool intersect(const rtRay &ray, double &cur_distance, double &alfa, double &beta, double &delta); // See rtObject.h
        void setNormals(rtVector3d* vn1, rtVector3d* vn2, rtVector3d* vn3); // adds infromation about normals in triangle's vertices
        void setCoords(rtVector3d* vt1, rtVector3d* vt2, rtVector3d* vt3); // adds information about ST/UV coordinates
        rtVector3d getNormal() const; // get Triangle normal
        rtVector3d* getNormals() const; // get vertices normal
        rtVector3d* getVerts() const; // get vertices
        rtVector3d* getCoords() const; // get ST/UV coordinates

    protected:
        rtVector3d* v1,*v2,*v3; // vertices
        rtVector3d* vt1,*vt2,*vt3; // vertices ST/UV coordinates
        rtVector3d* vn1,*vn2,*vn3; // vertices normal
        rtVector3d normal; // triangle normal
    };
    rtMesh();
    rtMesh(QVector<rtTriangle *> *triangles, QVector<rtVector3d *> *vertices); // build mesh from triangles and vertices



protected:
    QVector<rtTriangle*> triangles;
    QVector<rtVector3d*> vertices;
    QVector<rtVector3d*> normals;
    QVector<rtVector3d*> coords;
    // rtObject interface
public:
    // load objects from .OBJ file (all faces must be triangles)
    static QVector<rtMesh*> fromOBJ(QString filename);
    // see rtObject
    rtLightIntensity intersect(const rtRay &ray, double &cur_distance, const QVector<rtObject *> objects, const QVector<rtAbstractLight *> &lights);
    void addTriangle(int a, int b, int c);
    void addVertex(double x, double y, double z);
    void addNormal(double x, double y, double z);
    void addCoords(double u, double v, double w);
    void setOrigin(const rtVector3d &origin); // sets a new position of the object in space

    // rtObject interface
public:
    bool isInPath(const rtRay &ray, const double &distance); // for shadow checks
};

#endif // RTMESH_H
