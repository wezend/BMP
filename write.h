#ifndef WRITE_H
#define WRITE_H

#include "fstream"
#include "bmp.h"
#include "qdebug.h"

class Write
{
public:
    Write();
    void setBmp(BMP *value);
    void write();

private:
    BMP *bmp;
};

#endif // WRITE_H
