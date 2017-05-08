#ifndef RTLIGHTINTENSITY_H
#define RTLIGHTINTENSITY_H

#include <QColor>

// Class representing a lit point in space or on film. Represented as floating point RGBA value. Must be greater than 0, but doesn't have upper bound

class rtLightIntensity
{
public:
    rtLightIntensity();
    rtLightIntensity(const rtLightIntensity &color); // copy constructor
    rtLightIntensity(double red, double green, double blue, double alpha=1.0);
    double red() const; // get red value
    double green() const; // get green value
    double blue() const; // get blue value
    double alpha() const; // get alpha value

    // Here are overloaded operators for arithetic operations between two intensities with consts.
    rtLightIntensity operator +(rtLightIntensity operand);
    rtLightIntensity operator +=(rtLightIntensity operand);
    rtLightIntensity operator -(rtLightIntensity operand);
    rtLightIntensity operator -();
    rtLightIntensity operator *(rtLightIntensity operand);
    rtLightIntensity operator *(double value);
    rtLightIntensity operator /=(int divisor);
    rtLightIntensity operator =(rtLightIntensity operand);
    operator QRgb(); // convert light intensity in floating point value to int RGBA (0-255)

protected:
    double _red,_green,_blue,_alpha;

};

#endif // RTLIGHTINTENSITY_H
