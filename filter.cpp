#include "filter.h"

Filter::Filter()
{

}

void Filter::setBmp(BMP *value)
{
    bmp = value;
}

void Filter::filter(int min, int max)
{
    for(int i=0;i<bmp->bmpInfoHeader.biWidth;i++){
        for(int j=0;j<bmp->bmpInfoHeader.biHeight;j++){
            if(bmp->rgb[i][j].rgbBlue<min){
                bmp->rgb[i][j].rgbBlue=0;
                bmp->rgb[i][j].rgbGreen=0;
                bmp->rgb[i][j].rgbRed=0;
            }
            if(bmp->rgb[i][j].rgbBlue>max){
                bmp->rgb[i][j].rgbBlue=255;
                bmp->rgb[i][j].rgbGreen=255;
                bmp->rgb[i][j].rgbRed=255;
            }

        }
    }

    int **rgbFilter = new int*[bmp->bmpInfoHeader.biWidth+2];
    for (int i = 0; i < bmp->bmpInfoHeader.biWidth+2; i++) {
        rgbFilter[i] = new int[bmp->bmpInfoHeader.biHeight+2];
    }


    for (int i=0; i<bmp->bmpInfoHeader.biWidth; i++) {
            for (int j=0; j<bmp->bmpInfoHeader.biHeight; j++) {
                rgbFilter[i+1][j+1]=bmp->rgb[i][j].rgbBlue;

                //края
                if(i==0)
                    rgbFilter[i][j+1]=bmp->rgb[i][j].rgbBlue;
                if(j==0)
                    rgbFilter[i+1][j]=bmp->rgb[i][j].rgbBlue;
                if(i==bmp->bmpInfoHeader.biWidth-1)
                    rgbFilter[i+2][j+1]=bmp->rgb[i][j].rgbBlue;
                if(j==bmp->bmpInfoHeader.biHeight-1)
                    rgbFilter[i+1][j+2]=bmp->rgb[i][j].rgbBlue;

                //углы
                if(i==0 && j==0)
                    rgbFilter[i][j]=bmp->rgb[i][j].rgbBlue;
                if(i==0 && j==bmp->bmpInfoHeader.biHeight-1)
                    rgbFilter[i][j+2]=bmp->rgb[i][j].rgbBlue;
                if(i==bmp->bmpInfoHeader.biWidth-1 && j==0)
                    rgbFilter[i+2][j]=bmp->rgb[i][j].rgbBlue;
                if(i==bmp->bmpInfoHeader.biWidth-1 && j==bmp->bmpInfoHeader.biHeight-1)
                    rgbFilter[i+2][j+2]=bmp->rgb[i][j].rgbBlue;
            }
        }


    for (int i=0; i<bmp->bmpInfoHeader.biWidth; i++) {
        for (int j=0; j<bmp->bmpInfoHeader.biHeight; j++){
            int A[3][3]={
                {rgbFilter[i][j],rgbFilter[i][j+1],rgbFilter[i][j+2]},
                {rgbFilter[i+1][j],rgbFilter[i+1][j+1],rgbFilter[i+1][j+2]},
                {rgbFilter[i+2][j],rgbFilter[i+2][j+1],rgbFilter[i+2][j+2]}
            };

            for(int k=0;k<3;k++)
                for(int z=0;z<3;z++){
                    if(k!=1 && z!=1 && A[k][z]==255)
                        bmp->rgb[i][j].rgbBlue=255;
                        bmp->rgb[i][j].rgbGreen=0;
                        bmp->rgb[i][j].rgbRed=0;
                    }
        }
    }


    for (int i=0; i<bmp->bmpInfoHeader.biWidth; i++) {
            for (int j=0; j<bmp->bmpInfoHeader.biHeight; j++) {
                rgbFilter[i+1][j+1]=bmp->rgb[i][j].rgbBlue;

                //края
                if(i==0)
                    rgbFilter[i][j+1]=bmp->rgb[i][j].rgbBlue;
                if(j==0)
                    rgbFilter[i+1][j]=bmp->rgb[i][j].rgbBlue;
                if(i==bmp->bmpInfoHeader.biWidth-1)
                    rgbFilter[i+2][j+1]=bmp->rgb[i][j].rgbBlue;
                if(j==bmp->bmpInfoHeader.biHeight-1)
                    rgbFilter[i+1][j+2]=bmp->rgb[i][j].rgbBlue;

                //углы
                if(i==0 && j==0)
                    rgbFilter[i][j]=bmp->rgb[i][j].rgbBlue;
                if(i==0 && j==bmp->bmpInfoHeader.biHeight-1)
                    rgbFilter[i][j+2]=bmp->rgb[i][j].rgbBlue;
                if(i==bmp->bmpInfoHeader.biWidth-1 && j==0)
                    rgbFilter[i+2][j]=bmp->rgb[i][j].rgbBlue;
                if(i==bmp->bmpInfoHeader.biWidth-1 && j==bmp->bmpInfoHeader.biHeight-1)
                    rgbFilter[i+2][j+2]=bmp->rgb[i][j].rgbBlue;
            }
        }

    for (int i=0; i<bmp->bmpInfoHeader.biWidth; i++) {
            for (int j=0; j<bmp->bmpInfoHeader.biHeight; j++) {
                if(bmp->rgb[i][j].rgbBlue!=0 && bmp->rgb[i][j].rgbBlue!=255){
                    bmp->rgb[i][j].rgbBlue=0;
                    bmp->rgb[i][j].rgbGreen=0;
                    bmp->rgb[i][j].rgbRed=0;
                }
            }
    }

    for (int i=0; i<bmp->bmpInfoHeader.biWidth; i++) {
            for (int j=0; j<bmp->bmpInfoHeader.biHeight; j++) {
                if(bmp->rgb[i][j].rgbBlue==0){
                    bmp->rgb[i][j].rgbBlue=255;
                    bmp->rgb[i][j].rgbGreen=255;
                    bmp->rgb[i][j].rgbRed=255;
                }else{
                    bmp->rgb[i][j].rgbBlue=0;
                    bmp->rgb[i][j].rgbGreen=0;
                    bmp->rgb[i][j].rgbRed=0;
                }
            }
    }

}
