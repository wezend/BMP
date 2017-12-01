#ifndef BLUR_H
#define BLUR_H

#include "bmp.h"
#include "qdebug.h"
#include "math.h"


class Blur
{
public:
    Blur();
    void setBmp(BMP *value);
    void blur();

    void setG(double value);

private:
    BMP *bmp;
    double G=0;

    double gauss(double s);
};

#endif // BLUR_H
