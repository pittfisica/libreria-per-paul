#include <iostream>
#include <fstream>
#include <cmath>

#include "rang.h"

using namespace std;

struct val{
char r; // risposta corretta
int p; // punti domanda
};

struct elaborato{
int matr; // matricola dello studente
int nd; /* numero di domande del test
(cioe’ il valore N sopra descritto)*/
char risp[10]; // per vettore delle risposte
int voto; // valutazione finale del test
};

void intro(string const& filename, string const &filename1);
int domande(string const &filename);
val *load(val m[], int N, string const &filename);
int punti_tot(val m[], int N);
void print_ov_array(val a[], int N);
int conta(string const &filename, int n);
elaborato *load1(string const& filename, elaborato m[], int N , int Nd);
void print_ov_primi(elaborato a[], int N, int V);
void print_ov_ultimi(elaborato a[], int N, int V);
elaborato *voto(elaborato m[], int N, val V[]);
void print_ov_primi_2(elaborato a[], int N, int V);
void print_ov_ultimi_2(elaborato a[], int N, int V);
void sort_array(elaborato a[], int N);
void stampa_esiti(elaborato a[], int N ,string const &filename);
int passati(elaborato m[], int N);
double media(elaborato m[], int N);
void print_stats(elaborato m[], int N ,string const &filename );
