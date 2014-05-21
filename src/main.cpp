#include <QtGui>
#include "MapWidget.h"
#include "MainWindow.h"

int main(int argc, char *argv[]){

  QApplication app(argc, argv);

  //MapWidget map;
  //map.show();
  MainWindow window;
  window.show();

  return app.exec();
}
