#ifndef GRADIENT_H
#define GRADIENT_H

#include "bmp.h"
#include "qdebug.h"

class Gradient
{
public:
    Gradient();
    void setBmp(BMP *value);
    void gradient();

private:
    BMP *bmp;

};

#endif // GRADIENT_H
