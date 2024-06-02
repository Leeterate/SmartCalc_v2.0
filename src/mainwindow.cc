#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(war::Controller *controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , controller_obj(controller)
{
    ui->setupUi(this);
    ui->radioButton_calc->clicked(true);

    ui->lineEdit_money->setValidator(new QIntValidator(0, 2000000000, this));
    ui->lineEdit_period->setValidator(new QIntValidator(0, 2000000000, this));
    ui->lineEdit_rate->setValidator(new QDoubleValidator(0, 0, 5, this));

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_e,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_dot,SIGNAL(clicked()),this,SLOT(pressbutton_digits()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(pressbutton_arithmetic()));
    connect(ui->pushButton_sqr,SIGNAL(clicked()),this,SLOT(pressbutton_arithmetic()));
    connect(ui->pushButton_sum,SIGNAL(clicked()),this,SLOT(pressbutton_arithmetic()));
    connect(ui->pushButton_sub,SIGNAL(clicked()),this,SLOT(pressbutton_arithmetic()));
    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(pressbutton_arithmetic()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(pressbutton_arithmetic()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(pressbutton_func()));
    connect(ui->pushButton_asin,SIGNAL(clicked()),this,SLOT(pressbutton_func()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(pressbutton_func()));
    connect(ui->pushButton_acos,SIGNAL(clicked()),this,SLOT(pressbutton_func()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(pressbutton_func()));
    connect(ui->pushButton_atan,SIGNAL(clicked()),this,SLOT(pressbutton_func()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(pressbutton_func()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(pressbutton_func()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(pressbutton_func()));
    connect(ui->pushButton_bracket_left,SIGNAL(clicked()),this,SLOT(pressbutton_bracket()));
    connect(ui->pushButton_bracket_right,SIGNAL(clicked()),this,SLOT(pressbutton_bracket()));

    connect(ui->pushButton_AC,SIGNAL(clicked()),this,SLOT(pressbutton_clear()));
    connect(ui->pushButton_equal,SIGNAL(clicked()),this,SLOT(pressbutton_equal()));
    connect(ui->pushButton_credit,SIGNAL(clicked()),this,SLOT(pressbutton_credit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pressbutton_digits(){
    QPushButton *button = (QPushButton *)sender();
    if (ui->lineEdit->text() == "0" && button->text() != ".") {
        ui->lineEdit->clear();
    }
    ui->lineEdit->setText(ui->lineEdit->text() + button->text());
}

void MainWindow::pressbutton_arithmetic(){
    QPushButton *button = (QPushButton *)sender();
    int stop = 0;

    if (ui->lineEdit->text().right(2) == "+ " || ui->lineEdit->text().right(2) == "- " || ui->lineEdit->text().right(2) == "% " ||
            ui->lineEdit->text().right(2) == "/ " || ui->lineEdit->text().right(2) == "* " || ui->lineEdit->text().right(2) == "^ ") {
        ui->lineEdit->cursorBackward(true, 3);
        ui->lineEdit->backspace();
        ui->lineEdit->setText(ui->lineEdit->text() + " " + button->text() + " ");
        stop = 1;
    }

    if (!stop && ui->lineEdit->cursorPosition() && ui->lineEdit->text().right(1) != '(') {
        ui->lineEdit->setText(ui->lineEdit->text() + " " + button->text() + " ");
    }
}

void MainWindow::pressbutton_func(){
    QPushButton *button = (QPushButton *)sender();

    if (ui->lineEdit->text() == "0") {
        ui->lineEdit->clear();
    }

    if (!ui->lineEdit->cursorPosition() || ui->lineEdit->text().right(1) == ' ' || ui->lineEdit->text().right(1) == '(') {
        ui->lineEdit->setText(ui->lineEdit->text() + button->text() + "(");
    }
}

void MainWindow::pressbutton_bracket(){
    QPushButton *button = (QPushButton *)sender();

    if (button == ui->pushButton_bracket_right &&
                  (ui->lineEdit->text() == "0" || ui->lineEdit->text().right(1) == ' ' || ui->lineEdit->text().right(1) == '(')) {

    } else {
        if (ui->lineEdit->text() == "0") {
            ui->lineEdit->clear();
        }
        ui->lineEdit->setText(ui->lineEdit->text() + button->text());
    }
}

void MainWindow::pressbutton_clear(){

    ui->lineEdit->setText("0");
}

void MainWindow::equals_operation(){
    std::string tmp_src = ui->lineEdit->text().replace(" ", "").toStdString();
    double X = ui->Xinput->value();
    controller_obj->LaunchModel(X, tmp_src);
    ui->lineEdit->setText(
        QString::fromStdString(controller_obj->GetFinalResult()));
}

void MainWindow::pressbutton_equal() {
    if (ui->pushButton_equal->text() == "=") {
    equals_operation();
    } else if (ui->pushButton_equal->text() == "draw") {
    draw_graph();
    }
}

void MainWindow::draw_graph() {
ui->widget_graph->clearGraphs();
      double Xmin = ui->lineEdit_xmin->text().toDouble();
      double Xmax = ui->lineEdit_xmax->text().toDouble();
      double Ymin = ui->lineEdit_ymin->text().toDouble();
      double Ymax = ui->lineEdit_ymax->text().toDouble();
      if (Xmax <= Xmin) Xmax = Xmin +1;
      if (Ymax <= Ymin) Ymax = Ymin +1;
  try {
    double X, h = 0.01;
    double s = abs(Xmax) + abs(Xmin);
    if (s > 100) h = h * 10;
    for (X = Xmin; X <= Xmax; X += h) {
        QString tmp_expression = ui->lineEdit->text();

        std::string tmp_src2 = tmp_expression.replace(" ", "").toStdString();
        std::string input_line = tmp_src2;
             controller_obj->LaunchModel(X, input_line);
             std::string res2 = controller_obj->GetFinalResult();
             if (controller_obj->CheckException()) {
                 ui->lineEdit->setText(
                 QString::fromStdString(res2));
                 break;}
      x.push_back(X);
      y.push_back(std::stod(res2));
    }
  } catch (std::exception& err) {
  }

  ui->widget_graph->xAxis->setRange(Xmin, Xmax);
  ui->widget_graph->yAxis->setRange(Ymin, Ymax);
  ui->widget_graph->clearGraphs();
  ui->widget_graph->addGraph();
  ui->widget_graph->graph(0)->setLineStyle(QCPGraph::lsNone);
  ui->widget_graph->graph(0)->setPen(QPen(Qt::red));
  ui->widget_graph->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCircle, 3));
  ui->widget_graph->graph(0)->addData(x, y);
  ui->widget_graph->replot();
  ui->widget_graph->setInteraction(QCP::iRangeZoom, true);
  ui->widget_graph->setInteraction(QCP::iRangeDrag, true);
  x.clear();
  y.clear();
}

void MainWindow::on_radioButton_graph_clicked()
{
    ui->widget_grapharea->setVisible(true);
    ui->widget_calcarea->setVisible(true);
    ui->lineEdit->setVisible(true);
    ui->widget_credit->setVisible(false);
    ui->pushButton_equal->setText("draw");
    resize(1020, 300);
}

void MainWindow::on_radioButton_calc_clicked()
{
    ui->widget_grapharea->setVisible(false);
    ui->widget_credit->setVisible(false);
    ui->widget_calcarea->setVisible(true);
    ui->lineEdit->setVisible(true);
    ui->pushButton_equal->setText("=");
    resize(510, 300);
}

void MainWindow::pressbutton_credit() {
//in development
}

void MainWindow::on_pushButton_clear_clicked()
{
//in development
}
