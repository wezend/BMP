#ifndef FILTER_H
#define FILTER_H

#include "bmp.h"
#include "qdebug.h"

class Filter
{
public:
    Filter();
    void setBmp(BMP *value);
    void filter(int min, int max);

private:
    BMP *bmp;
};

#endif // FILTER_H
