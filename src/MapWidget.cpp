#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QPoint>
#include <QDebug>
#include "MapWidget.h"
#include <cmath>
#include <list>

#include "fractal.h"

MapWidget::MapWidget(QWidget *parent) : QWidget(parent){
  _maxIter = 0;
  _seed = 0;
}

QSize MapWidget::sizeHint() const {
  return QSize(800, 600);
}

QSize MapWidget::minimumSizeHint() const {
  return QSize(400, 200);
}

void MapWidget::paintEvent(QPaintEvent*){
 
  // Define the painter used
  QPainter painter(this);
  QBrush brush(QColor(255, 0, 0));
  QPen pen;
  
  pen.setWidth(1);
  painter.setBrush(brush);
  painter.setPen(pen);

  // Start painting

  const int scale = 120;
  QPoint origin(width() / 2., height() / 2);

  std::list<QPoint> seed_points = {
      QPoint(-1, -1),
      QPoint(1, -1),
      QPoint(1, 1),
      QPoint(-1, 1)
  };

  srand(_seed); // Set seed
 
  for(auto& point: seed_points)
  {
    point *= scale; // Scale points to appropriate size;

    // Intial displacement of seed points (optional)
    int displ_x = displacement(_initialDispl);
    int displ_y = displacement(_initialDispl);
    point += QPoint(displ_x, displ_y);
  }

  // Can be replaced by proper Render object in future release
  std::list<QPoint> new_points = fractalLine(seed_points, _seed, _maxIter, _initialDispl);

  size_t n_points = new_points.size(); // Returns size for new set of points
  QPoint *points = new QPoint[n_points]; // Create new array of points (used to draw polygon)

  int i = 0;
  for(auto& point: new_points)
    points[i++] = point + origin; // Translation to origin

  painter.drawPolygon(points, n_points);

  if(_showPoints) // Trigger show points
  {
    pen.setWidth(5);
    pen.setColor(QColor(0, 0, 255));
    painter.setPen(pen);
    painter.drawPoints(points, n_points);
  }
}
