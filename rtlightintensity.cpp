#include "rtlightintensity.h"
#include <QtAlgorithms>

rtLightIntensity::rtLightIntensity()
{
    _red = _green = _blue = 0.0;
    _alpha = 1.0;
}

rtLightIntensity::rtLightIntensity(const rtLightIntensity &color)
{
    _red=color._red;
    _green=color._green;
    _blue=color._blue;
    _alpha=color._alpha;
}

rtLightIntensity::rtLightIntensity(double red, double green, double blue, double alpha): _red(red), _green(green), _blue(blue), _alpha(alpha)
{

}

double rtLightIntensity::red() const
{
    return _red;
}

double rtLightIntensity::green() const
{
    return _green;
}

double rtLightIntensity::blue() const
{
    return _blue;
}

rtLightIntensity rtLightIntensity::operator +(rtLightIntensity operand)
{
    return rtLightIntensity(_red+operand.red(),_green+operand.green(),_blue+operand.blue(),_alpha+operand.alpha());
}

rtLightIntensity rtLightIntensity::operator +=(rtLightIntensity operand)
{
    _red+=operand.red();
    _green+=operand.green();
    _blue+=operand.blue();
    _alpha=std::max(_alpha,operand.alpha());
    return *this;
}

rtLightIntensity rtLightIntensity::operator -(rtLightIntensity operand)
{
    double red = _red-operand.red();
    double green = _green-operand.green();
    double blue = _blue-operand.blue();
    return rtLightIntensity(red>0?red:0.0,green>0?green:0.0,blue>0?blue:0.0,_alpha);
}

rtLightIntensity rtLightIntensity::operator -()
{
    return rtLightIntensity(-_red,-_green,-_blue,_alpha);
}

rtLightIntensity rtLightIntensity::operator *(rtLightIntensity operand)
{
    return rtLightIntensity(_red*operand.red(),_green*operand.green(),_blue*operand.blue(),_alpha);
}

rtLightIntensity rtLightIntensity::operator *(double value)
{
    return rtLightIntensity(_red*value,_green*value,_blue*value,_alpha);
}

rtLightIntensity rtLightIntensity::operator /=(int divisor)
{
    if(divisor!=0){
        _red/=divisor;
        _green/=divisor;
        _blue/=divisor;
    }
    return *this;
}

rtLightIntensity rtLightIntensity::operator =(rtLightIntensity operand)
{
    _red = operand.red();
    _green = operand.green();
    _blue = operand.blue();
    _alpha = operand.alpha();
    return *this;
}

double rtLightIntensity::alpha() const
{
    return _alpha;
}

rtLightIntensity::operator QRgb()
{
    int red = qBound(0.0,_red*255,255.0);
    int green = qBound(0.0,_green*255,255.0);
    int blue = qBound(0.0,_blue*255,255.0);
    return qRgba(red,green,blue, _alpha*255);
}
