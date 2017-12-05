#include "gradient.h"

Gradient::Gradient()
{

}

void Gradient::setBmp(BMP *value)
{
    bmp = value;
}

void Gradient::gradient()
{

    int robinson[8][3][3]={
        {
            {-1, 0, 1},
            {-2, 0, 2},
            {-1, 0, 1}
        },
        {
            { 0, 1, 2},
            {-1, 0, 1},
            {-2,-1, 0}
        },
        {
            { 1, 2, 1},
            { 0, 0, 0},
            {-1,-2,-1}
        },
        {
            { 2, 1, 0},
            { 1, 0,-1},
            { 0,-1,-2}
        },
        {
            { 1, 0,-1},
            { 2, 0,-2},
            { 1, 0,-1}
        },
        {
            { 0,-1,-2},
            { 1, 0,-1},
            { 2, 1, 0}
        },
        {
            {-1,-2,-1},
            { 0, 0, 0},
            { 1, 2, 1}
        },
        {
            {-2,-1, 0},
            {-1, 0, 1},
            { 0, 1, 2}
        }
    };

    double **rgbGrad = new double*[bmp->bmpInfoHeader.biWidth+2];
    for (int i = 0; i < bmp->bmpInfoHeader.biWidth+2; i++) {
        rgbGrad[i] = new double[bmp->bmpInfoHeader.biHeight+2];
    }


    for (int i=0; i<bmp->bmpInfoHeader.biWidth; i++) {
            for (int j=0; j<bmp->bmpInfoHeader.biHeight; j++) {
                rgbGrad[i+1][j+1]=bmp->rgb[i][j].rgbBlue;

                //края
                if(i==0)
                    rgbGrad[i][j+1]=bmp->rgb[i][j].rgbRed;
                if(j==0)
                    rgbGrad[i+1][j]=bmp->rgb[i][j].rgbRed;
                if(i==bmp->bmpInfoHeader.biWidth-1)
                    rgbGrad[i+2][j+1]=bmp->rgb[i][j].rgbRed;
                if(j==bmp->bmpInfoHeader.biHeight-1)
                    rgbGrad[i+1][j+2]=bmp->rgb[i][j].rgbRed;

                //углы
                if(i==0 && j==0)
                    rgbGrad[i][j]=bmp->rgb[i][j].rgbRed;
                if(i==0 && j==bmp->bmpInfoHeader.biHeight-1)
                    rgbGrad[i][j+2]=bmp->rgb[i][j].rgbRed;
                if(i==bmp->bmpInfoHeader.biWidth-1 && j==0)
                    rgbGrad[i+2][j]=bmp->rgb[i][j].rgbRed;
                if(i==bmp->bmpInfoHeader.biWidth-1 && j==bmp->bmpInfoHeader.biHeight-1)
                    rgbGrad[i+2][j+2]=bmp->rgb[i][j].rgbRed;
            }
        }



    for (int i=0; i<bmp->bmpInfoHeader.biWidth; i++) {
        for (int j=0; j<bmp->bmpInfoHeader.biHeight; j++){
            double A[3][3]={
                {rgbGrad[i][j],rgbGrad[i][j+1],rgbGrad[i][j+2]},
                {rgbGrad[i+1][j],rgbGrad[i+1][j+1],rgbGrad[i+1][j+2]},
                {rgbGrad[i+2][j],rgbGrad[i+2][j+1],rgbGrad[i+2][j+2]}
            };

            double B[3][3];
            int sum=0;

            for(int k=0;k<8;k++){
                int tmpSum=0;
                for(int z=0;z<3;z++){
                    for(int y=0;y<3;y++){
                        B[z][y]=A[z][y] * robinson[k][z][y];
                        tmpSum+=B[z][y];
                    }
                }
                if(sum<tmpSum){
                    bmp->rgb[i][j].gradVector=k;
                    bmp->rgb[i][j].rgbBlue=tmpSum;
                    bmp->rgb[i][j].rgbGreen=tmpSum;
                    bmp->rgb[i][j].rgbRed=tmpSum;
                    sum=tmpSum;

                }
            }


        }
    }

}


