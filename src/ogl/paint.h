#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Paint; }
QT_END_NAMESPACE

class Paint : public QMainWindow
{
    Q_OBJECT

public:
    Paint(QWidget *parent = nullptr){ui_ = parent;}
    Paint(const Paint&) = delete;
    Paint(Paint&&) = delete;
    ~Paint(){}
    Paint& operator=(const Paint&) = delete;
    Paint& operator=(Paint&&) = delete;    

private slots:


private:
    QWidget *ui_;
    // Private methods
};

#endif // MAINWINDOW_H_