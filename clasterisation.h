#ifndef CLASTERISATION_H
#define CLASTERISATION_H

#include "bmp.h"
#include "qdebug.h"
#include "math.h"
#include "ctime"

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Clasterisation
{
public:
    Clasterisation();
//    void setSrc(const char *pFile);
    void setSrc(QString pFile);
    void clasterisation();



private:
    Mat src;

};

#endif // CLASTERISATION_H
