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

//    qDebug() <<"I redy to blur it! - 3";

    for (int i = 1; i < bmp->bmpInfoHeader.biWidth+1; i++){
        double sum = 0;
            for (int j = 1; j < bmp->bmpInfoHeader.biHeight+1; j++) {

                double x[3][3];



                sum=rgbBig[i-1][j-1]+rgbBig[i][j-1]+rgbBig[i+1][j-1]+
                        rgbBig[i-1][j]+rgbBig[i][j]+rgbBig[i+1][j]+
                        rgbBig[i-1][j+1]+rgbBig[i][j+1]+rgbBig[i+1][j+1];

//                //нормируем
                x[0][0]=rgbBig[i-1][j-1]/sum;
                x[0][1]=rgbBig[i][j-1]/sum;
                x[0][2]=rgbBig[i+1][j-1]/sum;

                x[1][0]=rgbBig[i-1][j]/sum;
                x[1][1]=rgbBig[i][j]/sum;
                x[1][2]=rgbBig[i+1][j]/sum;

                x[2][0]=rgbBig[i-1][j+1]/sum;
                x[2][1]=rgbBig[i][j+1]/sum;
                x[2][2]=rgbBig[i+1][j+1]/sum;





//                qDebug() <<sum;

                for(int k=0;k<3;k++)
                    for(int z=0;z<3;z++){
                        if(k==1 && z==1)
                            x[k][z]*=gauss(0);
                        else
                            x[k][z]*=gauss(1);

                        sum+=x[k][z];
                    }



//                rgbBig[i-1][j-1]=rgbBig[i-1][j-1]*gauss(1);
//                rgbBig[i][j-1]*=gauss(1);
//                rgbBig[i+1][j-1]*=gauss(1);

//                rgbBig[i-1][j]*=gauss(1);
//                rgbBig[i][j]*=gauss(0);
//                rgbBig[i+1][j]*=gauss(1);

//                rgbBig[i-1][j+1]*=gauss(1);
//                rgbBig[i][j+1]*=gauss(1);
//                rgbBig[i+1][j+1]*=gauss(1);

                rgbBig[i][j]*=sum;

//                rgbBig[i-1][j-1]+rgbBig[i][j-1]+rgbBig[i+1][j-1]+
//                        rgbBig[i-1][j]+rgbBig[i][j]+rgbBig[i+1][j]+
//                        rgbBig[i-1][j+1]+rgbBig[i][j+1]+rgbBig[i+1][j+1];

//                qDebug() <<rgbBig[i][j];

//                rgbBig[i][j]*=bmp->rgb[i-1][j-1].rgbBlue;


            }
    }

    for (int i = 0; i < bmp->bmpInfoHeader.biWidth; i++) {
            for (int j = 0; j < bmp->bmpInfoHeader.biHeight; j++) {

                bmp->rgb[i][j].rgbBlue=(int)rgbBig[i+1][j+1];
                bmp->rgb[i][j].rgbGreen=(int)rgbBig[i+1][j+1];
                bmp->rgb[i][j].rgbRed=(int)rgbBig[i+1][j+1];
            }
        }


}

void Blur::setG(double value)
{
    G = value;
}

double Blur::gauss(double s)
{
    double value=0;

    value=1/(G*sqrt(2*M_PI));
    value*=exp(-1*s/(2*pow(G,2)));


//    value=1/(2*M_PI*pow(G,2));
//    value*= exp(-1*s/pow(G,2));

    return value;
}

