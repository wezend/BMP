#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QObject>
#include <QFileSystemModel>
#include <QTreeView>
#include <button.h>


class view: public QGraphicsView{
Q_OBJECT
public:
    view(QWidget* parent=NULL);
    QGraphicsScene * scene;
    QTreeView * treeview;
    QFileSystemModel * dirmodel;
    void displayMainMenu();
public slots:
    void action();
};

#endif // VIEW_H
