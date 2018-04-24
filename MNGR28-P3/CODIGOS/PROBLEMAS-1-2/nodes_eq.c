#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "diferencies_dividides.h"

int main(int argc, char* argv[]) { //argv[1] serà el número de nodes que es vol.
    int i, n; //número de nodes menys 1
    double *eq, *cheb, *feq, *fcheb; //*eq guardara els nodes equidistants, *cheb guardarà els nodes de chebyshev.
    
    FILE* fitxer1; //nodes equidistants
    FILE* fitxer2; //nodes chebyshev
    
    fitxer1=fopen("equidistants.txt", "w");
    fitxer2=fopen("chebyshev.txt", "w");
    
    if(argc==1){
       printf("Cal introduir el nombre de nodes\n");
    }
    n=atoi(argv[1])-1;
    eq=malloc((n+1)*sizeof(double));
    cheb=malloc((n+1)*sizeof(double));
    feq=malloc((n+1)*sizeof(double));
    fcheb=malloc((n+1)*sizeof(double));

    nodosequi(n, eq); //plenem els vectors
    nodoscheb(n, cheb);
   
    for(i=0;i<=n;i++){
        feq[i]=ff(eq[i]);
        fprintf(fitxer1, "%lf\t%lf\n",eq[i], feq[i]);
    }
    for(i=0;i<=n;i++){
        fcheb[i]=ff(cheb[i]);
        fprintf(fitxer2, "%lf\t%lf\n",cheb[i], fcheb[i]);
    }
    
    return 0;
}
