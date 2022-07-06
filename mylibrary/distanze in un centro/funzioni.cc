// implementazione
#include "funzioni.h"
#include <cmath>
using namespace std;


// assegna al membro distance la distanza tra le coordinate e il centro.
void compute_distance(point2d &p)
{
  p.distance = sqrt(pow(p.coordinate[0],2) + pow(p.coordinate[1],2));
}

/**
 * Calcola la distanza di Pitagora tra punti (x,y) e (xc, yc).
 */
double distanza(const double x, const double y,const double xc, const double yc)
{
  return sqrt(pow(x-xc, 2) + pow(y-yc, 2));
}


// calcola la media delle distanze in un array point2d
double mean(const point2d *v, int n)
{
  double sum = 0;
  for (int i = 0; i < n; i++)
    sum += v[i].distance;
  return sum / n;
}