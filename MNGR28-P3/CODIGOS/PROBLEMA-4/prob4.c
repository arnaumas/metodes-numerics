#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "integracio.h"

int main(int argc, char* argv[]) {
    double t, *fv; //s guardara el resultat de simpson, t guardara el resultat dels trapezis, fv guardara els valors d'avaluar la funció en els punts que divideixen l'interval.
    int n; //nombre de divisions de l'interval (necesitem n+1 valors de la funció)
    
    /* Comprovem que s'ha introduït un argument */
    if((argc == 1) || (argc > 2)){
    fprintf(stderr, "ERROR: Cal introduir un argument.\n");
    return 1;
    }

    /* Comprovem que el paràmetre introduït dóna un valor vàlid */
    if(!(n = atoi(argv[1]))) {
            fprintf(stderr, "ERROR: Introduïu un nombre vàlid.\n");
            return 1;
    }
	
    fv=malloc((n+1)*sizeof(double));
    f2(n, 1, 5, fv); //guardem els resultats d'avaluar la funció en n+1 punts, interval [1, 5], en el vector fv
    t=trapezis(n, 1, 5, fv); //regla composta dels trapezis
    printf("Trapezis=%.15lf\n", t);
    printf("Estimació error=%.15lf\n", 10*(4./n)*(4./n));
    return 0;
}