#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double g(double x);

int main() {
    int i; //comptador
    double x; //per a calcular arrel de 2, x ha de ser 1
    x=1; //x_0=1
    for(i=0;i<=2;i++){
        x=g(x);
        printf("g[a%u]=%e\n",i, x);
    }
    return 0;
    
}


double g(double x) { //funcio g(x) amb polinomis de grau 3
    int i; //comptador
    double v[7], y, g; //v guarda els x^i, y auxiliar, g valor de la funció en x
    v[0]=x;
    y=x;
    for (i=1;i<=6;i++){
        y=y*x;
        v[i]=y;
        //printf("v[%u]=%lf\n",i, v[i]);
    }
    g=v[6]/(49*v[5]+784*v[4]+470*v[3]+13440*v[2]+19712*v[1]+14336*v[0]+4096);
    return g;
}

