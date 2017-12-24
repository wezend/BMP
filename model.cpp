#include "model.h"


Model::Model()
{

}

BMP Model::getBmp() const
{
    return bmp;
}


//void Model::setBmp(const char *pFile)
//{
//    //выбор считываемого бмп файла
//    if(bmp.bmpFileHeadr.bfType==0){
//        bmp.pFile=fopen(pFile,"rb");
//    }else {
//       bmp.pFile=fopen(pFile,"wb");
//    }


//}


void Model::setBmp(QString a)
{
    //выбор считываемого бмп файла
    if(bmp.bmpFileHeadr.bfType==0){
        bmp.pFile=fopen(a.toLatin1(),"rb");
    }else {
       bmp.pFile=fopen(a.toLatin1(),"wb");
    }

}

void Model::read()
{
    //передаём bmp из model(это его основное местопребывание)
    //в read для считывания.(чтобы было что считывать)
    reader.setBmp(&(this->bmp));

    //считываем
    reader.bmpRead();
    if(reader.error!=0)
        qDebug() <<"Error: "<<reader.error;
    qDebug() <<"I read it!";

}

void Model::write()
{
    //передаём bmp из model(это его основное местопребывание)
    //в write для записи.(чтобы было что записывать)
    writer.setBmp(&(this->bmp));

    //записываем
    writer.write();

    qDebug() <<"I write it!";

}

void Model::makeBlackWhite()
{
    blackWhiter.setBmp(&(this->bmp));

    blackWhiter.blackWhiteBMP();

    qDebug() <<"I blackWhite it!";

}

void Model::blurBMP(double sigma)
{
    blurer.setBmp(&(this->bmp));

    blurer.setG(sigma);

    blurer.blur();

    qDebug() <<"I blur it!";

}

void Model::gradBMP()
{
    gradienter.setBmp(&(this->bmp));

    gradienter.gradient();

    qDebug() <<"I gradient it!";

}

void Model::notMaximumsBMP()
{
    notMaximumer.setBmp(&(this->bmp));

    notMaximumer.notMaximums();

    qDebug() <<"I not maximum it!";

}

void Model::filterBMP(int min, int max)
{
   filterer.setBmp(&(this->bmp));

   for(int i=0;i<3;i++)
    filterer.filter(min, max);

   qDebug() <<"I not filter it!";
}

void Model::clasteriseBMP()
{

    clasterisator.clasterisation();

    qDebug() <<"I clasterise it!";
}

