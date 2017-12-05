#include "blackwhite.h"

BlackWhite::BlackWhite()
{

}

void BlackWhite::blackWhiteBMP()
{



    for (int i = 0; i < bmp->bmpInfoHeader.biWidth; i++) {
            for (int j = 0; j < bmp->bmpInfoHeader.biHeight; j++) {

                //высчитываем значение в конкретном пикселе
                int value=(int)(0.3*((int)bmp->rgb[i][j].rgbRed)+
                                0.59*((int)bmp->rgb[i][j].rgbGreen)+
                                0.11*((int)bmp->rgb[i][j].rgbBlue));


                //записываем
                bmp->rgb[i][j].rgbBlue=value;
                bmp->rgb[i][j].rgbGreen=value;
                bmp->rgb[i][j].rgbRed=value;
            }
        }

}

void BlackWhite::setBmp(BMP *value)
{
    bmp = value;
}
