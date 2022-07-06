#include <iostream>
#include <fstream>
#include <cmath>

#include "funzioni.h"
#include "rang.h"

using namespace std;

int main(){
    //apre i file sui quali poi stampa
    intro("esiti.out" ,"statistiche.out" );
    //inizializzazione array val
    int n = domande("schema.dat");
    val *m = new val[n];
    m = load(m , n , "schema.dat");
    print_ov_array(m , n );
    //inizializzazione array elaborato
    int N = conta("letture.dat" , n);
    elaborato *e = new elaborato[N];
    e = load1("letture.dat", e , N , n);
    print_ov_primi(e , N , 5 );
    print_ov_ultimi(e , N , 5 );
    //calcoloe caricamento dei voti
    e = voto(e ,N  , m);
    print_ov_primi_2(e , N ,5);
    print_ov_ultimi_2(e , N , 5);
    //calcolo statistiche
    sort_array(e , N);
    stampa_esiti(e , N ,"esiti.out");
    print_stats(e , N , "statistiche.out");

    delete[] m;
    delete[] e;
    return 0;
}