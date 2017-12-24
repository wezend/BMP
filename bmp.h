#ifndef BMP_H
#define BMP_H

#include<iostream>

typedef struct
{
    unsigned int    bfType=0;
    unsigned long   bfSize=0;
    unsigned int    bfReserved1=0;
    unsigned int    bfReserved2=0;
    unsigned long   bfOffBits=0;
} BITMAPFILEHEADER;

typedef struct
{
    unsigned int    biSize=0;
    int             biWidth=0;
    int             biHeight=0;
    unsigned short  biPlanes=0;
    unsigned short  biBitCount=0;
    unsigned int    biCompression=0;
    unsigned int    biSizeImage=0;
    int             biXPelsPerMeter=0;
    int             biYPelsPerMeter=0;
    unsigned int    biClrUsed=0;
    unsigned int    biClrImportant=0;
} BITMAPINFOHEADER;

typedef struct
{
    int   rgbBlue=0;
    int   rgbGreen=0;
    int   rgbRed=0;

    int   rgbReserved=0;

    int   gradVector=0;
    double prinadl=0;
} RGBQUAD;

class BMP
{
public:
    BMP();
    FILE *pFile;
    BITMAPFILEHEADER bmpFileHeadr;
    BITMAPINFOHEADER bmpInfoHeader;
    RGBQUAD bmpRGBQuad;
    RGBQUAD **rgb;


};

#endif // BMP_H
