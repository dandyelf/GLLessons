#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QDate>
#include <QFileDialog>
#include "../controller/s21_controller_obj.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetControllerObj(s21::Controller *controller_obj) {
      controller_obj_ = controller_obj;
    }

private slots:
    void on_pushButtonFile_clicked();

private:
    Ui::MainWindow *ui;
    s21::Controller *controller_obj_;
    const s21::ObjT *obj_;
    // Private methods
    void draw();
};
#endif // MAINWINDOW_H
