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
    double *matrixMultiply(double *A, double *G, double *Result);
};

#endif // GRADIENT_H
