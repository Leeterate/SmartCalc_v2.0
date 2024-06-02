#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVector>

#include "model.h"
#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
 explicit MainWindow(war::Controller *controller, QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  war::Controller *controller_obj;
  int check_input_str(QString *str);
  void draw_graph();
  int combo_box_pars(QString str);
  void equals_operation();

  double xBegin, xEnd, h, X;
  int N;
  QVector<double> x, y;

 private slots:
  void pressbutton_digits();
  void pressbutton_arithmetic();
  void pressbutton_func();
  void pressbutton_bracket();
  void pressbutton_equal();
  void pressbutton_clear();
  void pressbutton_credit();
  void on_radioButton_graph_clicked();
  void on_radioButton_calc_clicked();
  void on_pushButton_clear_clicked();
};
#endif  // MAINWINDOW_H
