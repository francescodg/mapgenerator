#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QPoint>
#include <QDebug>
#include "MapWidget.h"
#include <cmath>

MapWidget::MapWidget(QWidget *parent) : QWidget(parent){}

QSize MapWidget::sizeHint() const {
  return QSize(400, 200);
}

QSize MapWidget::minimumSizeHint() const {
  return QSize(100, 50);
}

void MapWidget::paintEvent(QPaintEvent*){
  // Define the painter used
  QPainter painter(this);
  QBrush brush(QColor(255, 0, 0));
  QPen pen;
  
  pen.setWidth(3);
  painter.setBrush(brush);
  painter.setPen(pen);

  // Start painting

  const int count = 20;
  double t = 2 * 3.14 / count;
  const int radious = 30;
  const QPoint origin(0, 0);

  QPoint points[count];

  for(int i = 0; i < count; i++)
  {
    int x = round(radious * cos(i * t));
    int y = round(radious * sin(i * t));
    points[i] = QPoint( origin.x() + x, origin.y() + y);      
  }

  

  painter.drawPolygon(points, count);  
}
