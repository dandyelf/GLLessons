#include "mainwindow.h"

#include <QApplication>

#include "../controller/s21_controller_obj.h"

int main(int argc, char *argv[])
{
    s21::Controller * controller_obj = s21::Controller::getInstance();
    s21::Facade * facade_model_obj = new s21::Facade;
    controller_obj->SetModel(facade_model_obj);
    QApplication a(argc, argv);
    MainWindow w;
    w.SetControllerObj(controller_obj);
    w.show();
    if(facade_model_obj != nullptr) delete facade_model_obj;
    return a.exec();
}
