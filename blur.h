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

    void setG(int value);

private:
    BMP *bmp;
    int G=0;

    double gauss(int s);
};

#endif // BLUR_H
