#include "view.h"
#include <QGraphicsTextItem>
//#include <windows.h>
#include <button.h>
#include <QDirModel>
#include <QTreeView>
#include <qdebug.h>
#include <QMessageBox>
#include <QLineEdit>

view::view(QWidget *parent)
{
    // создаём scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);

    // установить scene
    setScene(scene);

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    lineEditBl = new QLineEdit(this);
    lineEditBl->setGeometry(10,500,100,40);
    lineEditBl->setPlaceholderText("Set Blur");

    lineEditTmin = new QLineEdit(this);
    lineEditTmin->setGeometry(120,500,100,40);
    lineEditTmin->setPlaceholderText("Set Tmin");

    lineEditTmax = new QLineEdit(this);
    lineEditTmax->setGeometry(230,500,100,40);
    lineEditTmax->setPlaceholderText("Set Tmax");

    lineEditName = new QLineEdit(this);
    lineEditName->setGeometry(340,500,100,40);
    lineEditName->setPlaceholderText("Set Name of picture");

    QString sPath = "";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setRootPath(sPath);
    treeview = new QTreeView(this);
    treeview->setModel(dirmodel);
    treeview->setFixedWidth(400);
    treeview->setFixedHeight(400);
}
void view::displayMainMenu()
{

    button* OpenButton = new button(QString("Open"));
    int bxPos = 10;
    int byPos = 410;
    OpenButton->setPos(bxPos,byPos);
    connect(OpenButton,SIGNAL(clicked()),this,SLOT(open()));
    scene->addItem(OpenButton);

    button* SaveButton = new button(QString("Save"));
    int qxPos = SaveButton->boundingRect().width()/2 + 70;
    int qyPos = 410;
    SaveButton->setPos(qxPos,qyPos);
    connect(SaveButton,SIGNAL(clicked()),this,SLOT(write()));
    scene->addItem(SaveButton);

    button* HandleButton = new button(QString("Handle"));
    int hxPos = HandleButton->boundingRect().width()/2 + 180;
    int hyPos = 410;
    HandleButton->setPos(hxPos,hyPos);
    connect(HandleButton,SIGNAL(clicked()),this,SLOT(handle()));
    scene->addItem(HandleButton);

    button* ClastButton = new button(QString("Clasterization"));
    int cxPos = ClastButton->boundingRect().width()/2 + 290;
    int cyPos = 410;
    ClastButton->setPos(cxPos,cyPos);
    connect(ClastButton,SIGNAL(clicked()),this,SLOT(clasterization()));
    scene->addItem(ClastButton);

}

void view::displayWindow(QString str)
{
    titleText = new QGraphicsTextItem(str);
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 100;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);
}

void view::open(){
    QString sPath= dirmodel->fileInfo(treeview->currentIndex()).absoluteFilePath();
    sPath.replace("/","\\");
    this->controler.model.setBmp(sPath);
    this->controler.model.read();
    if(this->controler.model.reader.error!=0)
        QMessageBox::information(this,"Title","Error");
    else
    QMessageBox::information(this,"Title","Opened");
}

void view::write(){
    QString sPath= dirmodel->fileInfo(treeview->currentIndex()).absoluteFilePath();
    sPath.replace("/","\\");
    QString Name = ".bmp";
    sPath+=lineEditName->text();
    sPath+=Name;
    this->controler.model.setBmp(sPath);
    this->controler.model.write();
    QMessageBox::information(this,"Title","Saved");
}

void view::handle()
{
    if(lineEditBl->text().toDouble())
        bl=lineEditBl->text().toDouble();
    Tmin=lineEditTmin->text().toInt();
    if(lineEditTmax->text().toInt())
        Tmax=lineEditTmax->text().toInt();
    this->controler.model.makeBlackWhite();
    this->controler.model.blurBMP(bl);
    this->controler.model.gradBMP();
    this->controler.model.notMaximumsBMP();
    this->controler.model.filterBMP(Tmin, Tmax);
    QMessageBox::information(this,"Title","Handeled");

}

void view::clasterization()
{
    QString sPath= dirmodel->fileInfo(treeview->currentIndex()).absoluteFilePath();
    sPath.replace("/","\\");
    this->controler.model.clasterisator.setSrc(sPath);
    this->controler.model.clasteriseBMP();
    QMessageBox::information(this,"Title","clasturized");

}
