#include <QtGui>
#include "MapWidget.h"

int main(int argc, char *argv[]){

  QApplication app(argc, argv);

  MapWidget map;
  map.show();

  return app.exec();
}
