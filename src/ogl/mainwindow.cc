#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonFile_clicked()
{
    QString path = "/home/";
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open Obj File"), path,
                                                tr("OBJ Files (*.obj)"));
    if (file_name != "") {
        try {
            ui->lineEditFile->setText(file_name);
            std::string string = file_name.toStdString();
            controller_obj_->OpenObj(string.c_str());
            qDebug() << "File OK" << string.c_str() << QDate::currentDate();
            obj_ = &controller_obj_->GetObject();
            ui->openGLWidget->update();
        }  catch (std::exception e) {
        qDebug() << "Parce or file fail.";
        }
    }
}
