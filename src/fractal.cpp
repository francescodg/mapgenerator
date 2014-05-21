#include "fractal.h"
#include <QDebug>
#include <cmath>

int noise(int max_offset){
  return (rand()%3 - 1) * - 1 * rand()%max_offset;
}

std::list<QPoint> fractalLine(std::list<QPoint> original, int seed, int n_iterations,
      int max_offset, int max_iterations)
{
  srand(seed);

  std::list<QPoint> tmp(original); // Copy of original set of points

  for(int iteration = 0; iteration < n_iterations + 1; iteration++) // Consider iteration 0 as first
  {
   
    std::list<QPoint>::iterator i = tmp.begin();
    std::list<QPoint>::iterator next = i; // Initially set next = i, following step it will be updated
  
    qDebug() << "fractal::Iteration\nSeed: " << seed;
    while( i != tmp.end() )
    {
      next++; // Next has to be next element after i

      // We assume that the curve is closed. We need to check
      // if next is at the end of the list, if so it means that 
      // we need the value at beginning of the list.
      QPoint next_point = ( next == tmp.end() ) ? *tmp.begin() : *next; 

      // Compute new middle point
      int next_x = (i->x() + next_point.x()) / 2;
      int next_y =(i->y() + next_point.y()) / 2;

      //int intensity = max_offset * (1 - (float) iteration / max_iterations); // Max offset is 20, max number of iterations is 10
      double displ_factor = 50 / pow((iteration + 1), 2); // Displacement factor
      displ_factor = (rand() % 2) ? displ_factor : -displ_factor; // Displacement value +/- displacement factor on y coord

      int displ_x = displ_factor; // Displacement value +/- displacement factor on x coord
      int displ_y = displ_factor; // Displacement value +/- displacement factor on x coord
      
      qDebug() << "fractal::Displacement:" << QPoint(displ_x, displ_y);
      QPoint new_point(next_x + displ_x, next_y + displ_y); // Create point and add noise

      tmp.emplace(next, new_point); // Place element in between the two elements
      i = next; // Jump the element just created
    }
  }

  return tmp;
}


