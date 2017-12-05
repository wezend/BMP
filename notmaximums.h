#ifndef NOTMAXIMUMS_H
#define NOTMAXIMUMS_H

#include "bmp.h"
#include "qdebug.h"


class NotMaximums
{
public:
    NotMaximums();
    void setBmp(BMP *value);
    void notMaximums();

private:
    BMP *bmp;
};

#endif // NOTMAXIMUMS_H
