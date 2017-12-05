#include "notmaximums.h"

NotMaximums::NotMaximums()
{

}

void NotMaximums::setBmp(BMP *value)
{
    bmp = value;
}

void NotMaximums::notMaximums()
{

    int **rgbNotMaximums = new int*[bmp->bmpInfoHeader.biWidth+2];
    for (int i = 0; i < bmp->bmpInfoHeader.biWidth+2; i++) {
        rgbNotMaximums[i] = new int[bmp->bmpInfoHeader.biHeight+2];
    }


    for (int i=0; i<bmp->bmpInfoHeader.biWidth; i++) {
            for (int j=0; j<bmp->bmpInfoHeader.biHeight; j++) {
                rgbNotMaximums[i+1][j+1]=bmp->rgb[i][j].gradVector;

                //края
                if(i==0)
                    rgbNotMaximums[i][j+1]=bmp->rgb[i][j].gradVector;
                if(j==0)
                    rgbNotMaximums[i+1][j]=bmp->rgb[i][j].gradVector;
                if(i==bmp->bmpInfoHeader.biWidth-1)
                    rgbNotMaximums[i+2][j+1]=bmp->rgb[i][j].gradVector;
                if(j==bmp->bmpInfoHeader.biHeight-1)
                    rgbNotMaximums[i+1][j+2]=bmp->rgb[i][j].gradVector;

                //углы
                if(i==0 && j==0)
                    rgbNotMaximums[i][j]=bmp->rgb[i][j].gradVector;
                if(i==0 && j==bmp->bmpInfoHeader.biHeight-1)
                    rgbNotMaximums[i][j+2]=bmp->rgb[i][j].gradVector;
                if(i==bmp->bmpInfoHeader.biWidth-1 && j==0)
                    rgbNotMaximums[i+2][j]=bmp->rgb[i][j].gradVector;
                if(i==bmp->bmpInfoHeader.biWidth-1 && j==bmp->bmpInfoHeader.biHeight-1)
                    rgbNotMaximums[i+2][j+2]=bmp->rgb[i][j].gradVector;
            }
        }

    for (int i=0; i<bmp->bmpInfoHeader.biWidth; i++) {
        for (int j=0; j<bmp->bmpInfoHeader.biHeight; j++){
            int A[3][3]={
                {rgbNotMaximums[i][j],rgbNotMaximums[i][j+1],rgbNotMaximums[i][j+2]},
                {rgbNotMaximums[i+1][j],rgbNotMaximums[i+1][j+1],rgbNotMaximums[i+1][j+2]},
                {rgbNotMaximums[i+2][j],rgbNotMaximums[i+2][j+1],rgbNotMaximums[i+2][j+2]}
            };

            switch (A[1][1]) {
            case 0:
                if(A[1][0]>A[1][1] || A[1][2]>=A[1][1]){
                    bmp->rgb[i][j].rgbBlue=0;
                    bmp->rgb[i][j].rgbGreen=0;
                    bmp->rgb[i][j].rgbRed=0;
                }
                break;
            case 1:
                if(A[2][0]>A[1][1] || A[0][2]>=A[1][1]){
                    bmp->rgb[i][j].rgbBlue=0;
                    bmp->rgb[i][j].rgbGreen=0;
                    bmp->rgb[i][j].rgbRed=0;
                }
                break;
            case 2:
                if(A[0][1]>A[1][1] || A[2][1]>=A[1][1]){
                    bmp->rgb[i][j].rgbBlue=0;
                    bmp->rgb[i][j].rgbGreen=0;
                    bmp->rgb[i][j].rgbRed=0;
                }
                break;
            case 3:
                if(A[0][0]>A[1][1] || A[2][2]>=A[1][1]){
                    bmp->rgb[i][j].rgbBlue=0;
                    bmp->rgb[i][j].rgbGreen=0;
                    bmp->rgb[i][j].rgbRed=0;
                }
                break;
            case 4:
                if(A[1][0]>A[1][1] || A[1][2]>=A[1][1]){
                    bmp->rgb[i][j].rgbBlue=0;
                    bmp->rgb[i][j].rgbGreen=0;
                    bmp->rgb[i][j].rgbRed=0;
                }
                break;
            case 5:
                if(A[2][0]>A[1][1] || A[0][2]>=A[1][1]){
                    bmp->rgb[i][j].rgbBlue=0;
                    bmp->rgb[i][j].rgbGreen=0;
                    bmp->rgb[i][j].rgbRed=0;
                }
                break;
            case 6:
                if(A[0][1]>A[1][1] || A[2][1]>=A[1][1]){
                    bmp->rgb[i][j].rgbBlue=0;
                    bmp->rgb[i][j].rgbGreen=0;
                    bmp->rgb[i][j].rgbRed=0;
                }
                break;
            case 7:
                if(A[0][0]>A[1][1] || A[2][2]>=A[1][1]){
                    bmp->rgb[i][j].rgbBlue=0;
                    bmp->rgb[i][j].rgbGreen=0;
                    bmp->rgb[i][j].rgbRed=0;
                }
                break;
            default:
                break;
            }

        }
    }
}
