#include "mainwindow.h"
#include <QApplication>
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //это босс на деревне. он хранит в себе модель и вью
    Controller controller;

    //так подключается бмп. только тут. всё остальное в модели.
    //и то потому что я не умею с визуалкой работать
    //а так надо через проводник и всё твакое(хз)
    //тоесть пользователь нажал кнопку, открылся проводник(в идеале)
    //выбрал, нажал "OK". сработала эта штука
    controller.model.setBmp("D:\\test.bmp");

    //и сразу эта штука. если это не бмп или не то бмп, должна вылетить ошибка.
    //в идеале, если всё норм, то должно появиться слово "DONE" в кнопке где было написано "OK"
    controller.model.read();


    //а ещё было бы здорово запихать выбор директории записи
    //тоесть юзер выбирает что читать, и куда записать, а потом жмёт "чёрнобелизировать"
    controller.model.setBmp("D:\\test1.bmp");

    //а это запись. она болжна быть везде.
    //типа считали, запустили чёрнобелизатор и там же записали.
    controller.model.write();









    w.show();

    return a.exec();
}
