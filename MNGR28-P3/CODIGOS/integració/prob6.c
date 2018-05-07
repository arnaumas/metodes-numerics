#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "integracio.h"

int main() {
    double s; //s guardara el resultat de simpson, fv guardara els valors d'avaluar la funció en els punts que divideixen l'interval.
    int n=14; //nombre de divisions de l'interval (necesitem n+1 valors de la funció)
    
    double fv[15]={37.2, 40.2, 44.4, 40.8, 44.1, 39.9, 36.3, 32.7, 29.7, 25.5, 23.4, 26.7, 31.2, 34.8, 36.9}; //valors donats
    s=simpson(n, 0, 84, fv); //regla composta de simpson
    printf("Simpson=%.15lf\n", s);
    return 0;
}