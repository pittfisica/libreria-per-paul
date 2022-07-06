#include <iostream>
#include <fstream>
#include <cmath>

#include "funzioni.h"
#include "rang.h"

using namespace std;

//apre i file sui quali scriverò e scrive su di essi un intestazione
void intro(string const &filename, string const &filename1)
{
  cerr << rang::fg::green << "    Pietro Romano     990758   " << rang::fg::reset << endl;
  cerr << rang::fg::cyan << "-------------------------------" << rang::fg::reset << endl;
  cerr << rang::fg::green << "Esame di Informatica 11/02/2022" << rang::fg::reset << endl;
  cerr << rang::fg::cyan << "-------------------------------" << rang::fg::reset << endl;

  fstream f;
  f.open(filename, ios::out);
  if (!f.good())
  {
    cerr << rang::fg::red << "problema all'apertura" << rang::fg::reset << endl;
    exit(-1);
  }
  f << "    Pietro Romano     990758   " << endl;
  f << "-------------------------------" << endl;
  f << "Esame di Informatica 11/02/2022" << endl;
  f << "-------------------------------" << endl;
  f.close();

  fstream f1;
  f1.open(filename1, ios::out);
  if (!f1.good())
  {
    cerr << rang::fg::red << "problema all'apertura" << rang::fg::reset << endl;
    exit(-1);
  }
  f1 << "    Pietro Romano     990758   " << endl;
  f1 << "-------------------------------" << endl;
  f1 << "Esame di Informatica 11/02/2022" << endl;
  f1 << "-------------------------------" << endl;
  f1.close();
}

//trova numero di domande dal file 
int domande(string const &filename)
{
  fstream f;
  f.open(filename, ios::in);
  if (!f.good())
  {
    cerr << rang::fg::red << "problema all'apertura" << rang::fg::reset << endl;
    exit(-1);
  }
  int N;
  f >> N;
  return N;
}

//carica valori sull'array
val *load(val m[], int N, string const &filename)
{
  fstream f;
  f.open(filename, ios::in);
  if (!f.good())
    cerr << "problema all'apertura" << endl;
  int K;
  f >> K;
  for (int i = 0; i < N; i++)
  {
    f >> m[i].r >> m[i].p;
  }
  f.close();
  return m;
}

//calcola quantità massima di punti ottenibili
int punti_tot(val m[], int N)
{
  int somma = 0;
  for (int i = 0; i < N; i++)
    somma += m[i].p;
  return somma;
}

//stampa a video L'array
void print_ov_array(val a[], int N)
{
  int tot = punti_tot(a, N);
  cout << "Numero di domande presenti nel test = " << N << endl;
  cout << "Risposte correte e relativo punteggio:" << endl;
  for (int i = 0; i < N; i++)
  {
    cout << rang::fg::blue << "\t Risposta corretta " << rang::fg::reset << "= " << a[i].r << rang::fg::blue << "\t Valore domanda " << rang::fg::reset << "= " << a[i].p << endl;
  }
  cout << "Punteggio Massimo = " << tot << endl;
}

//conta numero di righe nel file 
int conta(string const &filename , int n)
{
  fstream f;
  f.open(filename, ios::in);
  if (!f.good())
  {
    cerr << rang::fg::red << "problema all'apertura" << rang::fg::reset << endl;
    exit(-1);
  }
  int N = 0;

  int a;
  char c[10];
  for (;;)
  {
    if (f.eof())
    {
      break;
    }
    f >> a;
    for (int  i = 0; i < n; i++)
    {
      f>>c[i]; 
    }
    N++;
  }
  f.close();
  cout << "numero di Prove Eseguite = " << N - 1 << endl;
  return N - 1;
}

//carica da file sull'array i dati
elaborato *load1(string const &filename, elaborato m[], int N, int Nd)
{
  fstream f;
  f.open(filename, ios::in);
  if (!f.good())
    cerr << "problema all'apertura" << endl;
  for (int i = 0; i < N; i++)
  {
    f >> m[i].matr;
    for(int k = 0 ; k < Nd; k++)
      f>>m[i].risp[k];
    m[i].nd = Nd;
    m[i].voto = 0;
  }
  f.close();
  return m;
}

//stampa i primi V valori
void print_ov_primi(elaborato a[], int N, int V)
{
  cout << "Prime " << V << " Prove :" << endl;
  for (int i = 0; i < V; i++)
  {
    cout << rang::fg::blue << "\t Numero di matricola " << rang::fg::reset << "= " << a[i].matr << rang::fg::blue << "\t Domande totali " << rang::fg::reset << "=" << a[i].nd << rang::fg::blue << "\t Risposte Date " << rang::fg::reset << "= {";
    for (int k = 0; k < a[i].nd; k++)
      cout << a[i].risp[k] << ",";
    cout<<"}"<<endl;
  }
  
}

//stampa gli ultimi V valori
void print_ov_ultimi(elaborato a[], int N, int V)
{
  cout << "Ultime " << V << " Prove :" << endl;
  for (int i = N - V; i < N; i++)
  {
    cout << rang::fg::blue << "\t Numero di matricola " << rang::fg::reset << "= " << a[i].matr << rang::fg::blue << "\t Domande totali " << rang::fg::reset << "=" << a[i].nd << rang::fg::blue << "\t Risposte Date " << rang::fg::reset << "= {";
    for (int k = 0; k < a[i].nd; k++)
      cout << a[i].risp[k] << ",";
    cout<<"}"<<endl;
  }
}

//calcola il voto per ogni elaborato
elaborato *voto(elaborato m[], int N, val V[])
{
  for (int i = 0; i < N; i++)
  {
    for (int k = 0; k < m[i].nd; k++)
    {
      if (m[i].risp[k] == V[k].r)
        m[i].voto += V[k].p;
    }
  }
  return m;
}

void print_ov_primi_2(elaborato a[], int N, int V)
{
  cout << "Prime " << V << " Prove con voto:" << endl;
  for (int i = 0; i < V; i++)
  {
    cout << rang::fg::blue << "\t Numero di matricola " << rang::fg::reset << "= " << a[i].matr << rang::fg::blue << "\t Domande totali " << rang::fg::reset << "=" << a[i].nd << rang::fg::blue << "\t Risposte Date " << rang::fg::reset << "= {";
    for (int k = 0; k < a[i].nd; k++)
      cout << a[i].risp[k] << ",";
    cout<<"}"<< rang::fg::blue << "\t Voto " << rang::fg::reset<<"= "<<a[i].voto<<endl;
  }
  
}

//stampa gli ultimi V valori
void print_ov_ultimi_2(elaborato a[], int N, int V)
{
  cout << "Ultime " << V << " Prove con voto:" << endl;
  for (int i = N - V; i < N; i++)
  {
    cout << rang::fg::blue << "\t Numero di matricola " << rang::fg::reset << "= " << a[i].matr << rang::fg::blue << "\t Domande totali " << rang::fg::reset << "=" << a[i].nd << rang::fg::blue << "\t Risposte Date " << rang::fg::reset << "= {";
    for (int k = 0; k < a[i].nd; k++)
      cout << a[i].risp[k] << ",";
    cout<<"}"<< rang::fg::blue << "\t Voto " << rang::fg::reset<<"= "<<a[i].voto<<endl;
  }
}

//riordina l'array per num di matricola crescente
void sort_array(elaborato a[], int N)
{
  elaborato appo;
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      if (a[i].matr > a[j].matr)
      {
        appo = a[i];
        a[i] = a[j];
        a[j] = appo;
      }
    }
  }
}

//stampa gli esiti su file degli elaborati 
void stampa_esiti(elaborato a[], int N ,string const &filename)
{
  fstream f;
  f.open(filename, ios::app);
  if (!f.good())
  {
    cerr << rang::fg::red << "problema all'apertura" << rang::fg::reset << endl;
    exit(-1);
  }
  for(int i = 0;i < N; i++)
  {
    f<<"\t Numero di Matricola = "<<a[i].matr<<"\t Voto cottenuto = "<<a[i].voto<<endl;
  }
  f.close();
}

//calcola numero di passati 
int passati(elaborato m[], int N)
{
  int passati = 0;
  for(int i = 0; i < N ; i++)
  {
    if(m[i].voto >= 18)
      passati++;
  }
  return passati;
}

//calcola la media dei voti di chi è passato
double media(elaborato m[], int N)
{
  double sum = 0;
  for(int i = 0; i < N ; i++)
  {
    if(m[i].voto >= 18)
      sum += m[i].voto;
  }
  return sum/passati(m , N);
}

//stampa a video e su file le statistiche relative agli elaborati
void print_stats(elaborato m[], int N ,string const &filename )
{
  fstream f;
  f.open(filename, ios::app);
  if (!f.good())
  {
    cerr << rang::fg::red << "problema all'apertura" << rang::fg::reset << endl;
    exit(-1);
  }
  f<<" tatistiche sui risultati delle prove:"<<endl;
  f<<" \tNumero di Prove corrette = "<<N<<endl;
  f<<" \tNumero di studenti che hanno passato la prova = "<<passati(m , N)<<endl;
  f<<" \tNumero di studenti che non hanno passato la prova = "<<N-passati(m , N)<<endl;
  f<<" \tMedia di voto tra gli studenti passati = "<<media(m , N)<<endl;

  cout<<" Statistiche sui risultati delle prove:"<<endl;
  cout<< rang::fg::blue <<" \tNumero di Prove corrette "<< rang::fg::reset <<"= "<<N<<endl;
  cout<< rang::fg::blue <<" \tNumero di studenti che hanno passato la prova "<< rang::fg::reset <<"= "<<passati(m , N)<<endl;
  cout<< rang::fg::blue <<" \tNumero di studenti che non hanno passato la prova "<< rang::fg::reset <<"= "<<N-passati(m , N)<<endl;
  cout<< rang::fg::blue <<" \tMedia di voto tra gli studenti passati "<< rang::fg::reset <<"= "<<media(m , N)<<endl;
  f.close();
}