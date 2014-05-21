#include "fractal.h"
#include <QDebug>
#include <cmath>

/**
 *  Displacement function
 *  Given a max_displacement, returns a positive or negative
 *  random number in range abs(x) < r, with r = max_displacement.
 *  @param max_displacement int
 */
int displacement(int max_displacement){
   
  if(max_displacement == 0)
    return 0;
   
  int displ = rand() % max_displacement;
  displ = (rand() % 2) ? displ : -1 * displ;

  return displ; 
}

std::list<QPoint> fractalLine(std::list<QPoint> original, int seed, int n_iterations,
      int initialDispl, int max_iterations)
{
  std::list<QPoint> tmp(original); // Copy of original set of points

  for(int iteration = 0; iteration < n_iterations; iteration++) // Consider iteration 0 as first
  {
   
    // This is the radious reduction function, can be replaced by strategy
    double max_displ = initialDispl / pow(2, (iteration + 1)); 

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

      QPoint x1 = *i; // x1 point
      QPoint x2 = next_point; // x2 point

      QPoint p = (x1 + x2) / 2; // Calculate middle point

      QPoint diff = x2 - x1; // Vector difference
      QPoint normal;

      // Normal is defined as (-y, x)
      // where y = (x2_y - x1_y) / norm( x2 - x1 )
      // and x = (x2_x - x1_x) / norm( x2 - x1 )
      int mLength = diff.manhattanLength(); // manhattan length is used to compute norm because quicker
      int x = round((double) diff.x() / (double) mLength); // y = (x2_y - x1_y) / norm( x2 - x1 )
      int y = round((double) diff.y() / (double) mLength); // x = (x2_x - x1_x) / norm( x2 - x1 )
      normal.setX(-y);
      normal.setY(x);

      /*
      qDebug() << "fractal::Normal vector " << normal
           << "\nvector p = " << p
           << "\nvectors x1 = " << x1
           << "\nvector x2" << x2
           << "\ndiff" << diff
           << "\nmLength" << mLength
           << "\ndouble division" << (double) diff.x() / (double) mLength 
           << "\n" << round( (double) diff.y() / (double) mLength); 
      */
    
      int k = displacement(max_displ); // k is displacement factor
      QPoint new_point = p + k * normal; // Create point and add noise
      
      tmp.emplace(next, new_point); // Place element in between the two elements
      i = next; // Jump the element just created
    }
  }

  return tmp;
}
