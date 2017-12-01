#ifndef BLACKWHITE_H
#define BLACKWHITE_H

#include "bmp.h"
#include "qdebug.h"


class BlackWhite
{
public:
    BlackWhite();
    void blackWhiteBMP();
    void setBmp(BMP *value);

private:
    BMP *bmp;
};

#endif // BLACKWHITE_H
