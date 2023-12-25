#include <QApplication>
#include <QSurfaceFormat>
#include <QScreen>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "../controller/s21_controller_obj.h"
#include "mainwindow.h"
#include "scenegl.h"

void InitCoreApp(QCommandLineParser& parser, QApplication& app, QSurfaceFormat& fmt, MainWindow& mainwindow);

int main(int argc, char *argv[]) {
  s21::Controller controller_obj;
  s21::Facade facade_model_obj;
  QSurfaceFormat format;
  QCommandLineParser parser;
  QApplication a(argc, argv);
  MainWindow w;

  InitCoreApp(parser, a, format, w);
  controller_obj.SetModel(&facade_model_obj);
  w.SetControllerObj(&controller_obj);
  
  w.show();
  return a.exec();
}


void InitCoreApp(QCommandLineParser& parser, QApplication& app, QSurfaceFormat& fmt, MainWindow& mainwindow) {
  QCoreApplication::setApplicationName("Qt Hello GL 2 Example");
  QCoreApplication::setOrganizationName("QtProject");
  QCoreApplication::setApplicationVersion(QT_VERSION_STR);
  parser.setApplicationDescription(QCoreApplication::applicationName());
  parser.addHelpOption();
  parser.addVersionOption();
  QCommandLineOption multipleSampleOption("multisample", "Multisampling");
  parser.addOption(multipleSampleOption);
  QCommandLineOption coreProfileOption("coreprofile", "Use core profile");
  parser.addOption(coreProfileOption);
  QCommandLineOption transparentOption("transparent", "Transparent window");
  parser.addOption(transparentOption);
  parser.process(app);

  fmt.setDepthBufferSize(24);
  if (parser.isSet(multipleSampleOption))
      fmt.setSamples(4);
  if (parser.isSet(coreProfileOption)) {
      fmt.setVersion(3, 2);
      fmt.setProfile(QSurfaceFormat::CoreProfile);
  }
  QSurfaceFormat::setDefaultFormat(fmt);
  
  SceneGL::setTransparent(parser.isSet(transparentOption));
  if (SceneGL::isTransparent()) {
        mainwindow.setAttribute(Qt::WA_TranslucentBackground);
        mainwindow.setAttribute(Qt::WA_NoSystemBackground, false);
    }
    mainwindow.resize(mainwindow.sizeHint());
    int desktopArea = QGuiApplication::primaryScreen()->size().width() *
                      QGuiApplication::primaryScreen()->size().height();
    int widgetArea = mainwindow.width() * mainwindow.height();
    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        mainwindow.show();
        // mainwindow.showMaximized();
    else
        mainwindow.showMaximized();
}