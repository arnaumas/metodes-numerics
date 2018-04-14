#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "halley.h"

int main(int argc, char* argv[]) {
    double *v, *dv;
    int n; //n grau polinomi, i contador.
    
    if(argc == 1){
        printf("Cal introduir els coeficients.\n");
        return 1;
    }
    n=argc-2;
    v=malloc((n+1)*sizeof(double));
    dv=malloc((n*sizeof(double)));
    
    if((v==NULL) || (dv==NULL)) {
        printf("Error al reservar memòria\n");
    }
    llegirpolinomi(argc, argv, v, n);
    printf("Halley\n");
    halleypolinomi(2, 15, v, n);
}
