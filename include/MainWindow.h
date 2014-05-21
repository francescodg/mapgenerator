#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "ui_mainwindow.h"

class MainWindow : public QWidget
{
  Q_OBJECT
private:
  Ui::Form ui;
  void updateState();
public:
  MainWindow(QWidget *parent = 0);
public slots:
  void generate();
};

#endif
