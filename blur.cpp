#include "blur.h"

Blur::Blur()
{

}

void Blur::setBmp(BMP *value)
{
    bmp = value;
}

void Blur::blur()
{
    double rgbBig[bmp->bmpInfoHeader.biWidth+2][bmp->bmpInfoHeader.biHeight+2];
//    double **rgbBig = new double*[bmp->bmpInfoHeader.biWidth+2];
//    for (int i = 0; i < bmp->bmpInfoHeader.biWidth+2; i++) {
//        rgbBig[i] = new double[bmp->bmpInfoHeader.biHeight+2];
//    }


    for (int i = 0; i < bmp->bmpInfoHeader.biWidth+2; i++) {
            for (int j = 0; j < bmp->bmpInfoHeader.biHeight+2; j++) {
                rgbBig[i][j]=0;
            }
        }

    for (int i = 1; i < bmp->bmpInfoHeader.biWidth+1; i++) {
            for (int j = 1; j < bmp->bmpInfoHeader.biHeight+1; j++) {

                if(i==1)
                    rgbBig[i-1][j]=(double)bmp->rgb[i-1][j-1].rgbBlue;
                if(i==bmp->bmpInfoHeader.biWidth)
                    rgbBig[i+1][j]=(double)bmp->rgb[i-1][j-1].rgbBlue;

                if(j==1)
                    rgbBig[i][j-1]=(double)bmp->rgb[i-1][j-1].rgbBlue;
                if(j==bmp->bmpInfoHeader.biHeight)
                    rgbBig[i][j+1]=(double)bmp->rgb[i-1][j-1].rgbBlue;

                if(i==1 && j==1)
                    rgbBig[i-1][j-1]=(double)bmp->rgb[i-1][j-1].rgbBlue;
                if(i==bmp->bmpInfoHeader.biWidth && j==bmp->bmpInfoHeader.biHeight)
                    rgbBig[i+1][j+1]=(double)bmp->rgb[i-1][j-1].rgbBlue;

                if(i==1 && j==bmp->bmpInfoHeader.biHeight)
                    rgbBig[i-1][j+1]=(double)bmp->rgb[i-1][j-1].rgbBlue;
                if(i==bmp->bmpInfoHeader.biWidth && j==1)
                    rgbBig[i+1][j-1]=(double)bmp->rgb[i-1][j-1].rgbBlue;



                rgbBig[i][j]=(double)bmp->rgb[i-1][j-1].rgbBlue;

            }
        }

    qDebug() <<"I redy to blur it! - 3";

    for (int i = 1; i < bmp->bmpInfoHeader.biWidth+1; i++){
        double sum = 0;
            for (int j = 1; j < bmp->bmpInfoHeader.biHeight+1; j++) {

//                sum=rgbBig[i-1][j-1]+rgbBig[i][j-1]+rgbBig[i+1][j-1]+
//                        rgbBig[i-1][j]+rgbBig[i][j]+rgbBig[i+1][j]+
//                        rgbBig[i-1][j+1]+rgbBig[i][j+1]+rgbBig[i+1][j+1];




//                //нормируем
                rgbBig[i-1][j-1]/=sum;
                rgbBig[i][j-1]/=sum;
                rgbBig[i+1][j-1]/=sum;

                rgbBig[i-1][j]/=sum;
                rgbBig[i][j]/=sum;
                rgbBig[i+1][j]/=sum;

                rgbBig[i-1][j+1]/=sum;
                rgbBig[i][j+1]/=sum;
                rgbBig[i+1][j+1]/=sum;

                sum=rgbBig[i-1][j-1]+rgbBig[i][j-1]+rgbBig[i+1][j-1]+
                        rgbBig[i-1][j]+rgbBig[i][j]+rgbBig[i+1][j]+
                        rgbBig[i-1][j+1]+rgbBig[i][j+1]+rgbBig[i+1][j+1];



//                qDebug() <<sum;





                rgbBig[i-1][j-1]*=gauss(1);
                rgbBig[i][j-1]*=gauss(1);
                rgbBig[i+1][j-1]*=gauss(1);

                rgbBig[i-1][j]*=gauss(1);
                rgbBig[i][j]*=gauss(0);
                rgbBig[i+1][j]*=gauss(1);

                rgbBig[i-1][j+1]*=gauss(1);
                rgbBig[i][j+1]*=gauss(1);
                rgbBig[i+1][j+1]*=gauss(1);

                rgbBig[i][j]=rgbBig[i-1][j-1]+rgbBig[i][j-1]+rgbBig[i+1][j-1]+
                        rgbBig[i-1][j]+rgbBig[i][j]+rgbBig[i+1][j]+
                        rgbBig[i-1][j+1]+rgbBig[i][j+1]+rgbBig[i+1][j+1];

                qDebug() <<rgbBig[i][j];


                bmp->rgb[i][j].rgbBlue=(int)rgbBig[i][j];
                bmp->rgb[i][j].rgbGreen=(int)rgbBig[i][j];
                bmp->rgb[i][j].rgbRed=(int)rgbBig[i][j];
            }
    }
}

void Blur::setG(int value)
{
    G = value;
}

double Blur::gauss(int s)
{
    double value=(1/(2*M_PI*pow(G,2))) * exp(-1*s/pow(G,2));
    return value;
}

