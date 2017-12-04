#include "view.h"
#include <QGraphicsTextItem>
#include <windows.h>
#include <button.h>
#include <QDirModel>
#include <QTreeView>
//#include <controller.h>
#include <qdebug.h>


view::view(QWidget *parent)
{
    // создаём scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,GetSystemMetrics( SM_CXSCREEN ),GetSystemMetrics( SM_CYSCREEN));

    // установить scene
    setScene(scene);

    setFixedSize(GetSystemMetrics( SM_CXSCREEN ),GetSystemMetrics( SM_CYSCREEN));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QString sPath = "D:/";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setRootPath(sPath);
    treeview = new QTreeView(this);
    treeview->setModel(dirmodel);
    treeview->setFixedWidth(600);
    treeview->setFixedHeight(600);
}
void view::displayMainMenu()
{


    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("FUCK FOCC"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    button* playButton = new button(QString("Open"));
    int bxPos = 0;
    int byPos = 600;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(action()));
    scene->addItem(playButton);

        // create the quit button
        button* quitButton = new button(QString("Save"));
        int qxPos = quitButton->boundingRect().width()/2 + 150;
        int qyPos = 600;
        quitButton->setPos(qxPos,qyPos);
        //connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
        scene->addItem(quitButton);
}
void view::action(){
    QString sPath= dirmodel->fileInfo(treeview->currentIndex()).absoluteFilePath();
    sPath.replace("/","\\");

//    std::string str = sPath.toStdString();
//    const char * b = str.c_str();

    QByteArray ba = sPath.toLatin1();
    char * b= ba.data();

    //тут перевод и кустринк в чар
    qDebug() << sPath << b;
    //controller.model.setBmp(/*тут чаровская строка*/);
}
