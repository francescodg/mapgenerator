#include <QWidget>

class MapWidget : public QWidget {
  Q_OBJECT
public:
  MapWidget(QWidget *parent = 0);
  QSize sizeHint() const; // Return preferred size for widget
  QSize minimumSizeHint() const; // Return minimum size for widget
protected:
  void paintEvent(QPaintEvent*);
};
