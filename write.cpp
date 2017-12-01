#include "write.h"

Write::Write()
{

}

void Write::setBmp(BMP *value)
{
    bmp = value;
}

void Write::write()
{

    //записываем первый заголовок
    fwrite(&bmp->bmpFileHeadr.bfType, 1, 2, bmp->pFile);
    fwrite(&bmp->bmpFileHeadr.bfSize, 1, 4, bmp->pFile);
    fwrite(&bmp->bmpFileHeadr.bfReserved1, 1, 2, bmp->pFile);
    fwrite(&bmp->bmpFileHeadr.bfReserved2, 1, 2, bmp->pFile);
    fwrite(&bmp->bmpFileHeadr.bfOffBits, 1, 4, bmp->pFile);

    //записываем второй заголовок
    fwrite(&bmp->bmpInfoHeader.biSize , 1, 4, bmp->pFile);
    fwrite(&bmp->bmpInfoHeader.biWidth , 1, 4, bmp->pFile);
    fwrite(&bmp->bmpInfoHeader.biHeight , 1, 4, bmp->pFile);
    fwrite(&bmp->bmpInfoHeader.biPlanes , 1, 2, bmp->pFile);
    fwrite(&bmp->bmpInfoHeader.biBitCount , 1, 2, bmp->pFile);
    fwrite(&bmp->bmpInfoHeader.biCompression , 1, 4, bmp->pFile);
    fwrite(&bmp->bmpInfoHeader.biSizeImage , 1, 4, bmp->pFile);
    fwrite(&bmp->bmpInfoHeader.biXPelsPerMeter , 1, 4, bmp->pFile);
    fwrite(&bmp->bmpInfoHeader.biYPelsPerMeter , 1, 4, bmp->pFile);
    fwrite(&bmp->bmpInfoHeader.biClrUsed , 1, 4, bmp->pFile);
    fwrite(&bmp->bmpInfoHeader.biClrImportant , 1, 4, bmp->pFile);

    //записываем матрицы
    char zero=0;
        for (int i = 0; i < bmp->bmpInfoHeader.biWidth; i++) {
                for (int j = 0; j < bmp->bmpInfoHeader.biHeight; j++) {
                    fwrite(&bmp->rgb[i][j].rgbBlue , 1, 1, bmp->pFile);
                    fwrite(&bmp->rgb[i][j].rgbGreen , 1, 1, bmp->pFile);
                    fwrite(&bmp->rgb[i][j].rgbRed , 1, 1, bmp->pFile);
                }
            }









}
