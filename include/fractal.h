#include <QPoint>
#include <list>

int displacement(int max_displacement);
std::list<QPoint> fractalLine(std::list<QPoint> original, int seed, int n_iterations,
    int initialDispl = 20, int max_iterations = 10); 
