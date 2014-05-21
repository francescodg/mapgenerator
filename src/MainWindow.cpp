#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){
  ui.setupUi(this);
  updateState();
}

void MainWindow::updateState(){

  int max_iterations = ui.maxIterations_txt->text().toInt();
  int seed = ui.seed_txt->text().toInt();
  bool showPoints = ui.showPoints_chk->isChecked();  
  int initialDispl = ui.initialDispl_txt->text().toInt();

  ui.mapArea->showPoints(showPoints);
  ui.mapArea->setInitialDispl(initialDispl);
  ui.mapArea->setMaxIterations(max_iterations);
  ui.mapArea->setSeed(seed);  
}

void MainWindow::generate(){
  updateState();
  ui.mapArea->update();
}
