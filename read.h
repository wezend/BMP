#ifndef READ_H
#define READ_H

#include "fstream"
#include "bmp.h"
#include "qdebug.h"

class Read
{
public:
    Read();
    void bmpRead();
    void setBmp(BMP *value);
    int error=0;

private:
    BMP *bmp;


};

//static unsigned short read_u8(FILE *fp);
static unsigned short read_u16(FILE *fp);
static unsigned int read_u32(FILE *fp);
static int read_s32(FILE *fp);

#endif // READ_H
