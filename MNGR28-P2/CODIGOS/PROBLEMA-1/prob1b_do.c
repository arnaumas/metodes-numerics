#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "polinomis.h"

int main(int argc, char* argv[]) { //argc nombre d'arguments del main, argv[] punter amb els arguments
    double *v; //v guardarà els coeficients del polinomi
    int n; //n grau polinomi
    
    if(argc == 1){
        printf("Cal introduir els coeficients.\n");
        return 1;
    }
    n=argc-2; //un polinomi de grau n té n+1 coeficients, i argc conta el nom del programa com a argument, per aixó li llevem 2 a argc
    v=malloc((n+1)*sizeof(double)); //creem v, necessitem n+1 llocs, ja que el polinomi de grau n té n+1 coeficients a_n ... a_0
    
    if(v==NULL) {
        printf("Error al reservar memòria\n");
    }
    llegirpolinomi(argc, argv, v, n); //guardem els arguments en v
    printf("Newton\n");
    newtonpolinomi(2, 20, v, n); //executem el mètode de Newton amb x_0=2 i com a màxim 20 iteracions, amb el polinomi guardat en v que té grau n.
    
    return 0;
}

