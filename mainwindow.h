#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<stack>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

    void on_button6_clicked();

    void on_button7_clicked();

    void on_button8_clicked();

    void on_button9_clicked();

    void on_button0_clicked();

    void on_dot_clicked();

    void on_science_clicked();

    void on_chen_clicked();

    void on_chu_clicked();

    void on_jia_clicked();

    void on_jian_clicked();

    void on_Ans_clicked();

    void on_DEL_clicked();

    void on_AC_clicked();

    void on_equal_clicked();

    int before(QChar c);
    int after(QChar c);
    QString tran(QString s);
    double func(double a,double b,QChar c);
    double count(QString s);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
