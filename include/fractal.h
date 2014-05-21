#include <QPoint>
#include <list>

int noise(int max_offset);
std::list<QPoint> fractalLine(std::list<QPoint> original, int seed, int n_iterations,
    int max_offset = 20, int max_iterations = 10); 
