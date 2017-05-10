#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<stack>

QString s;
QString ss;
double pre=0;
double sumsum=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator");
    //this->setWindowIcon(QIcon(":/new/prefix1/image/calculator.ico"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button1_clicked()
{
    s+="1";
    ui->show->setText(s);
}

void MainWindow::on_button2_clicked()
{
    s+="2";
    ui->show->setText(s);
}


void MainWindow::on_button3_clicked()
{
    s+="3";
    ui->show->setText(s);
}

void MainWindow::on_button4_clicked()
{
    s+="4";
    ui->show->setText(s);
}

void MainWindow::on_button5_clicked()
{
    s+="5";
    ui->show->setText(s);
}

void MainWindow::on_button6_clicked()
{
    s+="6";
    ui->show->setText(s);
}

void MainWindow::on_button7_clicked()
{
    s+="7";
    ui->show->setText(s);
}

void MainWindow::on_button8_clicked()
{
    s+="8";
    ui->show->setText(s);
}

void MainWindow::on_button9_clicked()
{
    s+="9";
    ui->show->setText(s);
}

void MainWindow::on_button0_clicked()
{
    s+="0";
    ui->show->setText(s);
}

void MainWindow::on_dot_clicked()
{
    s+=".";
    ui->show->setText(s);
}

void MainWindow::on_science_clicked()
{
    s+="×10^";
    ui->show->setText(s);
}

void MainWindow::on_chen_clicked()
{
    s+="×";
    ui->show->setText(s);
}

void MainWindow::on_chu_clicked()
{
    s+="÷";
    ui->show->setText(s);
}

void MainWindow::on_jia_clicked()
{
    s+="+";
    ui->show->setText(s);
}

void MainWindow::on_jian_clicked()
{
    s+="-";
    ui->show->setText(s);
}

void MainWindow::on_Ans_clicked()
{
    s+="Ans";
    ui->show->setText(s);
}

void MainWindow::on_DEL_clicked()
{
    if(s.length()==0);
    else
    {
        if(s[s.length()-1]=='^')
        {
            s.chop(4);
        }
        else
        {
            if(s[s.length()-1]=='s')
            {
                s.chop(3);
            }
            else
            s.chop(1);
        }
        ui->show->setText(s);
    }
}

void MainWindow::on_AC_clicked()
{
    s="";
    ui->show->setText(s);
}

int MainWindow::before(QChar c)
{
    switch(c.toLatin1())
    {
    case'^':return 4;
    case'*':
    case'/':return 2;
    case'+':
    case'-':return 1;
    }
}

int MainWindow::after(QChar c)
{
    switch(c.toLatin1())
    {
    case'^':return 3;
    case'*':
    case'/':return 2;
    case'+':
    case'-':return 1;
    case'$':return -1;
    }
}


QString MainWindow::tran(QString s)
{
    QString newone="";
    for(int i=0;i<s.length();i++)
    {
       QString temp="";
       temp+=s[i];
       if(temp!="×"&&temp!="÷"&&temp!="A")
       {
           newone+=s[i];
       }
       else
       {
           if(temp=="×")
           {
               newone+="*";
           }
           else
           {
               if(s[i]=='A')
               {
                   newone+=QString::number(pre);
                   i+=2;
               }
               else
                    newone+="/";
           }
       }
    }
    return newone;
}
double MainWindow::func(double a,double b,QChar c)
{
    switch(c.toLatin1())
    {
    case'+':return a+b;
    case'-':return a-b;
    case'*':return a*b;
    case'/':return a/b;
    case'^':return pow(a,int(b));
    }
}

double MainWindow::count(QString s)
{
    stack<double> num;
    stack<QChar> sign;

    for(int i=0;i<s.length();i++)
    {
        double tempnum=0;double exp=0.1;
        while(s[i].isNumber()||s[i]=='.'&&i<s.length())
        {
             if(s[i]=='.')
             {
                 i++;
                 while(s[i].isNumber()&&i<s.length())
                 {
                     tempnum+=exp*(s[i].toLatin1()-'0');
                     exp*=0.1;
                     i++;
                 }
                 break;
                 //return exp;
             }
            tempnum=tempnum*10+(s[i].toLatin1()-'0');
            i++;

        }
        num.push(tempnum);
        if(i<s.length())
        {
            if(sign.empty())
            {
                sign.push(s[i]);
            }
            else
            {
                while(!sign.empty()&&before(s[i])<=after(sign.top()))
                {
                    double temp1=num.top();
                    num.pop();
                    double temp2=num.top();
                    num.pop();
                    double result;
                    result=func(temp2,temp1,sign.top());
                    sign.pop();
                    num.push(result);

                }
                sign.push(s[i]);
            }
        }
    }
    while(!sign.empty())
    {
        double temp1=num.top();
        num.pop();
        double temp2=num.top();
        num.pop();
        double result;
        result=func(temp2,temp1,sign.top());
        sign.pop();
        num.push(result);
    }
    return num.top();
}


void MainWindow::on_equal_clicked()
{
    QString newone=tran(s);
    double temp=count(newone);
    //ui->lineEdit->setText(QString::number(temp));
    //ui->lineEdit->setText(ss);
    pre=temp;
    ss=s;
    ui->lineEdit->setText(QString::number(pre));
    //ui->lineEdit->setText(newone);
    //double sumsum=count(s);
    //ui->lineEdit->setText(QString::number(sumsum));
    //ui->lineEdit->setText(count(s));
}
