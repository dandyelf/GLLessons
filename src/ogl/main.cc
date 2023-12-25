#include <QApplication>
#include <QSurfaceFormat>
#include <QScreen>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "../controller/s21_controller_obj.h"
#include "mainwindow.h"



void InitFormat(QSurfaceFormat format);

int main(int argc, char *argv[]) {
  s21::Controller controller_obj;
  s21::Facade facade_model_obj;
  QSurfaceFormat format;
  InitFormat(format);
  QApplication a(argc, argv);
  MainWindow w;

  controller_obj.SetModel(&facade_model_obj);
  QSurfaceFormat::setDefaultFormat(format);
  w.SetControllerObj(&controller_obj);
  w.show();

  return a.exec();
}

void InitFormat(QSurfaceFormat format) {
  format.setDepthBufferSize(24);
  format.setStencilBufferSize(8);
  format.setVersion(3, 2);
  format.setProfile(QSurfaceFormat::CoreProfile);
}

void InitCoreApp() {
    QCoreApplication::setApplicationName("Qt Hello GL 2 Example");
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption multipleSampleOption("multisample", "Multisampling");
    parser.addOption(multipleSampleOption);
    QCommandLineOption coreProfileOption("coreprofile", "Use core profile");
    parser.addOption(coreProfileOption);
    QCommandLineOption transparentOption("transparent", "Transparent window");
    parser.addOption(transparentOption);
}