#include "view.h"
#include <QApplication>
#include "controller.h"

view * View;


int main(int argc, char *argv[])
{



    QApplication a(argc, argv);



    Controller  controller;
    View = new view();
    View->controler =  controller;
    View->show();
    View->displayMainMenu();





//    так подключается бмп. только тут. всё остальное в модели.
//    и то потому что я не умею с визуалкой работать
//    а так надо через проводник и всё твакое(хз)
//    тоесть пользователь нажал кнопку, открылся проводник(в идеале)
//    выбрал, нажал "OK". сработала эта штука
//    controller.model.setBmp("D:\\test9.bmp");
//    controller.model.clasterisator.setSrc("D:\\snow\\original\\25.jpg");

//    и сразу эта штука. если это не бмп или не то бмп, должна вылетить ошибка.
//    в идеале, если всё норм, то должно появиться слово "DONE" в кнопке где было написано "OK"
//    controller.model.read();


    //чёрнобелизируем
//    controller.model.makeBlackWhite();

    //блюрим
//    controller.model.blurBMP(1.0);

    //градиентируем
//    controller.model.gradBMP();

    //ищем не максимумы
//    controller.model.notMaximumsBMP();

    //пороговая фильтрация
//    controller.model.filterBMP(2, 90);

//    controller.model.clasteriseBMP();







//    //а ещё было бы здорово запихать выбор директории записи
//    //тоесть юзер выбирает что читать, и куда записать, а потом жмёт "чёрнобелизировать"
//    controller.model.setBmp("D:\\test1.bmp");

//    //а это запись. она болжна быть везде.
//    //типа считали, запустили чёрнобелизатор и там же записали.
//    controller.model.write();









    return a.exec();
}
