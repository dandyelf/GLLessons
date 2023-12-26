#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButtonFile_clicked() {
  QString path = "/home/leftrana/projects/GLLessons/src/tests/obj/";
  QString file_name = QFileDialog::getOpenFileName(
      this, tr("Open Obj File"), path, tr("OBJ Files (*.obj)"));
  if (file_name != "") {
    try {
      ui->lineEditFile->setText(file_name);
      std::string string = file_name.toStdString();
      controller_obj_->OpenObj(string);
      qDebug() << "File OK" << string.c_str() << QDate::currentDate();
      obj_ = controller_obj_->GetObject();
    } catch (std::exception &e) {
      qDebug() << "Parce or file fail.";
    }
  }
  
  std::vector<GLfloat>vector(8);

  for(size_t i = 0; i < vector.size(); i++) {
    if((i + 1) % 2 == 0) {
      vector[i] = 0.14f;
    } else {
      vector[i] = -0.14f;
    }
  }
  logo_ = new Logo(obj_);
  ui->openGLWidget->LoadLogo(logo_);
}
