#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "integracio.h"

int main() {
    double s, *fv; //s guardara el resultat de simpson, fv guardara els valors d'avaluar la funció en els punts que divideixen l'interval.
    int i; //comptador
    
    for(i=2;i<=8;i=i+2){ //tot i que amb n=2 és suficient, calculem la integral per a diversos valors de n per a comparar.
        fv=malloc((i+1)*sizeof(double));
        f3(i, 1, 2,fv);
        s=simpson(i, 1, 2, fv); //regla composta de simpson
        printf("Simpson=%.15lf\tn=%u\n", s, i);
        free(fv);
    }
    return 0;
}