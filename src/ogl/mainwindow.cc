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
  Draw();
}

void MainWindow::Draw() {
        ui->openGLWidget->makeCurrent();
    QSize viewport_size = size();
    glViewport(0, 0, viewport_size.width(), viewport_size.height());

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 5, 7); // near and far match your triangle Z distance

    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_TRIANGLES);
     glVertex3f( 0.0f, 1.0f, 0.0f);
     glVertex3f(-1.0f,-1.0f, 0.0f);
     glVertex3f( 1.0f,-1.0f, 0.0f);
    glEnd();
//    ui->openGLWidget->makeCurrent();
//    glVertexPointer(3, GL_DOUBLE, 0, obj_->vertex_vector.data());
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glColor3f(1, 0, 1);
//    glDrawElements(GL_LINES, obj_->count_of_facets, GL_UNSIGNED_INT, obj_->polygon_vector.data());
}
