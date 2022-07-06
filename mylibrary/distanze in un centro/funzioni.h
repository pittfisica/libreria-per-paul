// header, dichiarazioni funzioni

// la struttura con i punti
struct point2d {
  double *coordinate;
  double distance;
};
double distanza(const double x, const double y,const double xc, const double yc);

// assegna al membro distance la distanza tra le coordinate e il centro.
void compute_distance(point2d &p);


// calcola la media delle distanze in un array point2d
double mean(const point2d *v, int n);