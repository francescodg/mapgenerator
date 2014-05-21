#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>

class MapWidget : public QWidget {
  Q_OBJECT
public:
  MapWidget(QWidget *parent = 0);
  QSize sizeHint() const; // Return preferred size for widget
  QSize minimumSizeHint() const; // Return minimum size for widget

  void setMaxIterations(int max_iterations){ _maxIter = max_iterations; };
  void setInitialDispl(int value){ _initialDispl = value; };
  void setSeed(int seed){ _seed = seed; }
  void showPoints(bool show){ _showPoints = show; }
protected:
  void paintEvent(QPaintEvent*);
private:
  int _seed;
  int _maxIter;
  bool _showPoints;
  int _initialDispl;
};

#endif
