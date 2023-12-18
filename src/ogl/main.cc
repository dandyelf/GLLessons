#include "mainwindow.h"

#include <QApplication>
#include <QSurfaceFormat>
#include "../controller/s21_controller_obj.h"

int main(int argc, char *argv[])
{
    s21::Controller controller_obj;
    s21::Facade  facade_model_obj;
    controller_obj.SetModel(&facade_model_obj);
    QApplication a(argc, argv);
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(3, 2);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);
    MainWindow w;
    w.SetControllerObj(&controller_obj);
    w.show();
    return a.exec();
}
