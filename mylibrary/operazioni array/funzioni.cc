#include "funzioni.h"
#include <iostream>
#include <fstream>

using namespace std;

#define NMAX  50000;

//open file
void open_file(string const& filename){
  fstream f;
  f.open("filename",ios::in);
  if(!f.good())
    cerr<<"problema all'apertura"<<endl;
}

//conta elementi in numero dep elementi
int conta(string const& filename){
  int N = 0;
  double dep1,dep2,dep3;
  for(;;){
    if(filename.eof()){
      break;
    }
    filename>>dep1;
            >>dep2;
            >>dep3;
    N++;
  }
  return N;
}

// load events from file
misure* load_misure(string const& filename, int &ntotal)
{
    ifstream infile;
    infile.open(filename.c_str());
    if (!infile.good())
        throw runtime_error("Cound not open file.");

    misure *read = new misure[NMAX];
    for (;;)
    {
        infile >> read[ntotal].t
               >> read[ntotal].vx
               >> read[ntotal].vy
               >> read[ntotal].vz
               >> read[ntotal].K;
        read[ntotal].massa = 0;
        if (infile.eof()) break;
        ntotal++;
    }

    // resize array for delivery
    misure *out = new misure[ntotal];
    for (int i = 0; i < ntotal; i++)
        out[i] = read[i];
    delete[] read;

    return out;
}

/**
 * Stampa contenuto array.
 */
void print_ov_array(punti a[], int N)
{
  cout << "Contenuto array:" << endl;
  for (int i = 0; i < N; i++)
    cout <<  setw(10) << " X = " << a[i].X << setw(8) << "Y = "<<a[i].Y << setw(8) << " massa = "<<a[i].massa<<endl;
}

void print_of_array(punti a[], int N, string const& filename)
{
  fstream f;
  f.open(filename,ios::out);
  cout << "Contenuto array:" << endl;
  for (int i = 0; i < N; i++)
    f << " X = " << a[i].X <<"\tY = "<<a[i].Y<<"\t massa = "<<a[i].massa<<endl;
}
void print_array(punti a[], int N, string const& filename)
{
  void print_ov_array(punti a[], int N);
  void print_of_array(punti a[], int N, nomefile);

}

/**
 * Calcola massimo valore in un array.
 */
int max_array(const int a[], int n)
{
  double max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}

/**
 * Calcola minimo valore in un array.
 */
int min_array(const int a[], int n)
{
  double min = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] < min)
      min = a[i];
  return min;
}

/**
 * Calcola minimo e massimo valore in un array.
 */
void min_max_array(const int a[], int n, int &min, int &max)
{
  max = max_array(a, n);
  min = min_array(a, n);
}

double dev_st(puntia a[], int N, double media){ 
  double sum = 0;
  for(int i = 0; i < N; i++){
    sum += pow(a[i] - media,2);
  }
  std = sqrt(sum / N-1);

  return std;
}
/**
 * Ordina un array in modo crescente.
 */
void sort_array(int a[], int n)
{
  for (int i = 0; i < n-1; i++)
    for (int j = i+1; j < n; j++)
      if (a[i] > a[j])
      {
        const int dep = a[i];
        a[i] = a[j];
        a[j] = dep;
      }
}