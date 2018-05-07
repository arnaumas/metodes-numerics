#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "integracio.h"
#define I 0.785398163397448

int main() {
    double s, t, *fv; //s guardara el resultat de simpson, t guardara el resultat dels trapezis, fv guardara els valors d'avaluar la funció en els punts que divideixen l'interval.
    fv=malloc(5*sizeof(double));
    f1(4, 0, 1, fv); //guardem els resultats d'avaluar la funció en cinc punts, interval [0, 1], en el vector fv
    s=simpson(4, 0, 1, fv); //regla composta de simpson
    t=trapezis(4, 0, 1, fv); //regla composta dels trapezis
    printf("Simpson=%.15lf\n", s);
    printf("Error Simpson=%.15lf\n", fabs(s-I));
    printf("Trapezis=%.15lf\n", t);
    printf("Error trapezis=%.15lf\n", fabs(t-I));
    
    return 0;
}