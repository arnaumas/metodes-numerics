#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "polinomis.h"

int main(int argc, char* argv[]) {
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
    printf("Bisecció\n");
    bisecciopolinomi(2, 8, 100, v, n); //metode de la bisecció interval [2,8], com a màxim 100 iteracions, polinomi guardat a v de grau n

    printf("Secant\n");
    secantpolinomi(2, 8, 50, v, n); //métode de la secant interval [2,8], com a màxim 50 iteracions, polinomi guardat a v de grau n
    
    printf("Newton\n");
    newtonpolinomi(2, 50, v, n); //métode de newton punt inicial 2, com a màxim 50 iteracions, polinomi guardat a v de grau n
    return 0;
}
