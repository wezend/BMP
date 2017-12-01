#ifndef MODEL_H
#define MODEL_H

#include "read.h"
#include "bmp.h"
#include "write.h"
#include "qdebug.h"



class Model
{
public:
    Model();
    BMP getBmp() const;
    void setBmp(const char *pFile);
    void read();
    void write();

private:
    BMP bmp;
    Read reader;
    Write writer;

};

#endif // MODEL_H
