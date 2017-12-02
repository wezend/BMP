#include "model.h"


Model::Model()
{

}

BMP Model::getBmp() const
{
    return bmp;
}

void Model::setBmp(const char *pFile)
{
    //выбор считываемого бмп файла
    if(bmp.bmpFileHeadr.bfType==0){
        bmp.pFile=fopen(pFile,"rb");
    }else {
       bmp.pFile=fopen(pFile,"wb");
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

    qDebug() <<"I redy to blur it!";

    blurer.blur();

    qDebug() <<"I blur it!";

}
