#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QMessageBox"
#include "QRandomGenerator"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Вы довольны своей зарплатой?");

ui->pb2->installEventFilter(this);
connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(message()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event){

   if (event->type()==QEvent::HoverEnter||event->type()==QEvent::HoverMove ||event->type()==QEvent::Enter  )
   {
       int x=this->width();
       int y=this->height();
      QRect w =ui->pb2->geometry();
    // const  int wy=ui->pb2->y;
      int choice=QRandomGenerator::global()->bounded(4);
      int n=70;
      switch (choice){
      case 0:
      if(w.x()+n+100<x){ if(w.y()+n+40<y) ui->pb2->move(w.x()+n,w.y()+n);
          else ui->pb2->move(w.x()+n,w.y()-n); }
      else { if(w.y()+n+40<y) ui->pb2->move(w.x()-n,w.y()+n);
          else ui->pb2->move(w.x()-n,w.y()-n); }
          break;
      case 1:
      if(w.x()-n>0){ if(w.y()-n>0) ui->pb2->move(w.x()-n,w.y()-n);
          else ui->pb2->move(w.x()-n,w.y()+n); }
      else { if(w.y()-n>0) ui->pb2->move(w.x()+n,w.y()-n);
          else ui->pb2->move(w.x()+n,w.y()+n); } break;
      case 2:
      if(w.x()-n>0){ if(w.y()+n+40<y) ui->pb2->move(w.x()-n,w.y()+n);
          else ui->pb2->move(w.x()-n,w.y()-n); }
      else { if(w.y()+n+40<y) ui->pb2->move(w.x()+n,w.y()+n);
          else ui->pb2->move(w.x()+n,w.y()-n); } break;
      case 3:
          if(w.x()+n+100<x){ if(w.y()-n>0) ui->pb2->move(w.x()+n,w.y()-n);
              else ui->pb2->move(w.x()+n,w.y()+n); }
          else { if(w.y()-n>0) ui->pb2->move(w.x()-n,w.y()-n);
              else ui->pb2->move(w.x()-n,w.y()+n); } break;

      }
   qDebug()<<choice;}
};

void MainWindow::message(){
    QMessageBox* mes = new QMessageBox(this);
    mes->setText("мы так и думали");
    mes->show();
};
