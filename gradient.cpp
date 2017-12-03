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

    double **rgbGrad = new double*[bmp->bmpInfoHeader.biWidth];
    for (int i = 0; i < bmp->bmpInfoHeader.biWidth; i++) {
        rgbGrad[i] = new double[bmp->bmpInfoHeader.biHeight];
    }


    for (int i=0; i<bmp->bmpInfoHeader.biWidth; i++) {
            for (int j=0; j<bmp->bmpInfoHeader.biHeight; j++) {
                rgbGrad[i][j]=bmp->rgb[i][j].rgbBlue;
            }
        }

    int Gx[3][3]={{1,0,-1},{2,0,-2},{1,0,-1}};
    int Gy[3][3]={{1,2,1},{0,0,0},{-1,-2,-1}};

    for(int i=1;i<bmp->bmpInfoHeader.biWidth-1;i++){
        for(int j=1;j<bmp->bmpInfoHeader.biHeight-1;j++){
            double Ax[3][3]={{rgbGrad[i-1][j-1],rgbGrad[i-1][j],rgbGrad[i-1][j+1]},
                             {rgbGrad[i][j-1],rgbGrad[i][j],rgbGrad[i][j+1]},
                             {rgbGrad[i+1][j-1],rgbGrad[i+1][j],rgbGrad[i+1][j+1]}};
            double Ay[3][3]={{rgbGrad[i-1][j-1],rgbGrad[i-1][j],rgbGrad[i-1][j+1]},
                             {rgbGrad[i][j-1],rgbGrad[i][j],rgbGrad[i][j+1]},
                             {rgbGrad[i+1][j-1],rgbGrad[i+1][j],rgbGrad[i+1][j+1]}};;

//            double G[3][3];


            double res1[3][3];

            for (int k = 0; k < 3; k++){
                   for (int z = 0; z < 3; z++){
                      res1[k][z] = 0.0;
                       for (int t = 0; t < 3; t++){
                           res1[k][z] += Ax[k][t] * Gx[t][z];
                       }
                   }
               }


            double res2[3][3];


            for (int k = 0; k < 3; k++){
                   for (int z = 0; z < 3; z++){
                      res2[k][z] = 0.0;
                       for (int t = 0; t < 3; t++){
                           res2[k][z] += Ay[k][t] * Gy[t][z];
                       }
                   }
               }

            double r2=0;
            double r1=0;

            for (int k = 0; k < 3; k++){
                   for (int z = 0; z < 3; z++){
                      r1+=res1[k][z];
                      r2+=res2[k][z];
                   }
               }



//            for(int t=0;t<3;t++)
//                for(int z=0;z<3;z++){
//                    Ax*Gx
//                    Ax[t][z]*=Gx[t][z];
//                    Ax^2
//                    Ax[t][z]*=Ax[t][z];
//                    Ay[t][z]*=Gy[t][z];
//                    Ay[t][z]*=Ay[t][z];

//                    G[t][z]=sqrt(res1[t][z]+res2[t][z]);
            double G=sqrt(pow(r1,2)+pow(r2,2));
//                }
//                qDebug() <<G;
//            __int16 G=Gd;

                for(int k=i-1;k<3;k++)
                    for(int z=j-1;z<3;z++){
                        bmp->rgb[i+k][j+z].rgbBlue=G/*[k][z]*/;
                        bmp->rgb[i+k][j+z].rgbGreen=G/*[k][z]*/;
                        bmp->rgb[i+k][j+z].rgbRed=G/*[k][z]*/;
                    }


            }


        }

}

double *Gradient::matrixMultiply(double *A, double *G,double *Result)
{

//    for (int i = 0; i < 3; i++){             //умножение матриц А и (В - Е)
//           for (int j = 0; j < 3; j++){
//              Result[i][j] = 0.0;
//               for (int t = 0; t < 3; t++){
//                   Result[i][j] += (A[i][t]) * (G[t][j]);
//               }
//           }
//       }

//    return Result;


}

