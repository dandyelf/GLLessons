#ifndef PAINT_H_
#define PAINT_H_

namespace Ui {
class MainWindow;
}

namespace Sc {

class Paint {
 public:
  Paint(Ui::MainWindow *parent = nullptr) { mainwindow_ = parent; }
  ~Paint() {}

 private:
  Ui::MainWindow *mainwindow_;
  void Draw();
};
}  // namespace Sc

#endif  // PAINT_H_
