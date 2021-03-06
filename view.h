#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QObject>
#include <QFileSystemModel>
#include <QTreeView>
#include <controller.h>
#include <button.h>
#include <QString>


class view: public QGraphicsView{
Q_OBJECT
public:
    void displayMainMenu();
    void displayWindow(QString str);

    view(QWidget* parent=NULL);
    Controller controler;
private:

    QGraphicsScene * scene;
    QGraphicsScene * scene1;
    QTreeView * treeview;
    QFileSystemModel * dirmodel;
    QGraphicsTextItem* titleText;
    QLineEdit * lineEditBl;
    QLineEdit * lineEditTmin;
    QLineEdit * lineEditTmax;
    QLineEdit *lineEditName;
    double bl=1.0;
    int Tmin=2;
    int Tmax=90;

public slots:
    void open();
    void write();
    void handle();
    void clasterization();
};

#endif // VIEW_H
