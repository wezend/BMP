#include "read.h"

Read::Read(){}


void Read::setBmp(BMP *value)
{
    bmp = value;
}

void Read::bmpRead()
{
//  проверка на bmp
    bmp->bmpFileHeadr.bfType=read_u16(bmp->pFile);

    if(bmp->bmpFileHeadr.bfType!=0x4d42){
        error=1;
        return;
    }

    //считываем первый заголовок
    bmp->bmpFileHeadr.bfSize      = read_u32(bmp->pFile);
    bmp->bmpFileHeadr.bfReserved1 = read_u16(bmp->pFile);
    bmp->bmpFileHeadr.bfReserved2 = read_u16(bmp->pFile);
    bmp->bmpFileHeadr.bfOffBits   = read_u32(bmp->pFile);

    //считываем второй заголовок
    bmp->bmpInfoHeader.biSize          = read_u32(bmp->pFile);
    bmp->bmpInfoHeader.biWidth         = read_s32(bmp->pFile);
    bmp->bmpInfoHeader.biHeight        = read_s32(bmp->pFile);
    bmp->bmpInfoHeader.biPlanes        = read_u16(bmp->pFile);
    bmp->bmpInfoHeader.biBitCount      = read_u16(bmp->pFile);
    bmp->bmpInfoHeader.biCompression   = read_u32(bmp->pFile);
    bmp->bmpInfoHeader.biSizeImage     = read_u32(bmp->pFile);
    bmp->bmpInfoHeader.biXPelsPerMeter = read_s32(bmp->pFile);
    bmp->bmpInfoHeader.biYPelsPerMeter = read_s32(bmp->pFile);
    bmp->bmpInfoHeader.biClrUsed       = read_u32(bmp->pFile);
    bmp->bmpInfoHeader.biClrImportant  = read_u32(bmp->pFile);

    //создаём матрицу струкрур для хранения RGB значений пикселя
    bmp->rgb = new RGBQUAD*[bmp->bmpInfoHeader.biWidth];
    for (int i = 0; i < bmp->bmpInfoHeader.biWidth; i++) {
        bmp->rgb[i] = new RGBQUAD[bmp->bmpInfoHeader.biHeight];
    }


    //заполняем матрицу структур
    for (int i = 0; i < bmp->bmpInfoHeader.biWidth; i++) {
            for (int j = 0; j < bmp->bmpInfoHeader.biHeight; j++) {
                bmp->rgb[i][j].rgbBlue = getc(bmp->pFile);
                bmp->rgb[i][j].rgbGreen = getc(bmp->pFile);
                bmp->rgb[i][j].rgbRed = getc(bmp->pFile);
            }
        }

    fclose(bmp->pFile);


//    вывод в консоль матриц
    for (int i = 0; i < bmp->bmpInfoHeader.biWidth; i++) {
            for (int j = 0; j < bmp->bmpInfoHeader.biHeight; j++) {
//                printf("%d %d %d\n", bmp->rgb[i][j].rgbRed, bmp->rgb[i][j].rgbGreen, bmp->rgb[i][j].rgbBlue);
            }
//            printf("\n");
        }


//    qDebug() <<hex<<;

}



static unsigned short read_u16(FILE *fp)
{
    unsigned char b0, b1;

    b0 = getc(fp);
    b1 = getc(fp);

    return ((b1 << 8) | b0);
}


static unsigned int read_u32(FILE *fp)
{
    unsigned char b0, b1, b2, b3;

    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);

    return ((((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
}


static int read_s32(FILE *fp)
{
    unsigned char b0, b1, b2, b3;

    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);

    return ((int)(((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
}



/*
static unsigned short read_u8(FILE *fp)
{
    unsigned char b0;

    b0 = getc(fp);

    return b0;
}

static unsigned short read_u16(FILE *fp)
{
    unsigned char b0, b1;

    b1 = getc(fp);
    b0 = getc(fp);


    return ( (b1 << 8)|b0);
}

static unsigned int read_u32(FILE *fp)
{
    unsigned char b0, b1, b2, b3;

    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);

    return ((((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
*/
