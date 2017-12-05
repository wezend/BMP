#ifndef MODEL_H
#define MODEL_H

#include "bmp.h"
#include "read.h"
#include "write.h"
#include "blackwhite.h"
#include "blur.h"
#include "gradient.h"
#include "notmaximums.h"
#include "filter.h"

#include "qdebug.h"



class Model
{
public:
    Model();
    BMP getBmp() const;
    void setBmp(const char *pFile);
    void read();
    void write();
    void makeBlackWhite();
    void blurBMP(double sigma);
    void gradBMP();
    void notMaximumsBMP();
    void filterBMP(int min, int max);

private:
    BMP bmp;
    Read reader;
    Write writer;
    BlackWhite blackWhiter;
    Blur blurer;
    Gradient gradienter;
    NotMaximums notMaximumer;
    Filter filterer;

};

#endif // MODEL_H
