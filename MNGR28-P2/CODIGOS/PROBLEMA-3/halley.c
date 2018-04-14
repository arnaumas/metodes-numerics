#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void llegirpolinomi(int argc, char* argv[], double *v, int n) {//argc nombre d'arguments main, argv[] arguments main, *v vector on guardarem el polinomi, n grau del polinomi
    
    int i, j; //són comptadors, utilitzem dos perque el primer argument de la funció és el coeficient n, el segon el n-1, el tercer el... 
    
    j=1;
    
    for(i=n;i>=0;i=i-1) {
        if( !(v[i] = atof(argv[j]) )) { //guardem dins del vector v els coeficients del polinomi v[n]=a_n 
            printf("\n");
        }
        //printf("v[%u]=%.15lf\n", i, v[i]);
        j=j+1;
    }
}


void derivarpolinomi(double *v, int n, double *dv) {//deriva el polinomi de grau n guardat en v i guarda el polinomi derivada en dv
    int i; // és un comptador
    
    for(i=n;i>0;i=i-1) { //i*a_i*x^{i-1}
        dv[i-1]=i*v[i];
        //printf("dv[%u]=%.15lf\n", i-1, dv[i-1]);
    }
    
}

double avaluarpolinomi(double *v, int n, double x) {//avalua x al polinomi de grau n guardat a v. Aquesta no és la manera més eficient d'avaluar polinomis, però com que a la práctica només avaluarem fins a polinomis de grau 3, tampoc suposa massa problema.
    int i, j; //són comptadors
    double *r, rr; //a r copiarem v, rr anirà guardant la suma de l'avaluació del polinomi.
    rr=v[0]; //inicialitzem rr amb a_0
    r=malloc((n+1)*sizeof(double)); 
    for(i=0;i<=n;i++) { //copiem v a r
        r[i]=v[i];
    }
    for(i=1;i<=n;i++) { //guardem a r cada coeficient multiplicat pel valor avaluat a la potencia corresponent a_i*x^i
        for(j=1;j<=i;j++) {
            r[i]=r[i]*x;
        }
    }
    for(i=1;i<=n;i++){ //sumem tots els valors guardats a r
        rr=rr+r[i];
    }
    free(r);
    return rr; //retornem el resultat d'avaluar el polinomi
}

double halleypolinomi(double x0, int k, double *v, int n) { //punt inicial x0, k nombre d'iteracions, v guarda els coeficients del polinomi, n grau polinomi
    int i; //és un comptador
    double x, y, e, ek, ekk,f0, f1, f2, *v1, *v2, num, den; //y=x_n+1, x=x_n, e=e_k/(e_{k-1})^3, ek=e_k=x_k-x_{k-1}, ekk=e_{k-1}=x_{k-1}-x_{k-2}, f0 funcio, f1 primera derivada, f2 segona derivada, *v1 coeficients derivada *v, *v2 coeficients segona derivada *v, num numerador mètode de Halley, den denominador mètode de Halley
    v1=malloc(n*sizeof(double)); //grau n-1
    v2=malloc((n-1)*sizeof(double)); //grau n-2
    derivarpolinomi(v, n, v1); //primera derivada
    derivarpolinomi(v1, n-1, v2); //segona derivada
    x=x0; //punt inicial x0
    f0=avaluarpolinomi(v, n, x); //fem la primera iteració fóra del bucle per a poder guardar ekk
    f1=avaluarpolinomi(v1, n-1, x);
    f2=avaluarpolinomi(v2,n-2,x);
    num=2*f0*f1;
    den=2*f1*f1-f0*f2;
        if((f1!=0) && (den!=0)){
            y=x-num/den;
            printf("x[%u]=%.15lf\n", 1 , y);
            ekk=fabs(y-x); //calculem e_{1}
            x=y;
        }
        else {
            printf("Derivada o denominador 0\nf1=%.15lf\nden=%.15lf", f1, den);
            return x;
        }
    for(i=2;i<=k;i++) {
        f0=avaluarpolinomi(v, n, x);
        f1=avaluarpolinomi(v1, n-1, x);
        f2=avaluarpolinomi(v2,n-2,x);
        num=2*f0*f1;
        den=2*f1*f1-f0*f2;
        if((f1!=0) && (den!=0)){
            y=x-num/den;
           
            ek=fabs(y-x); //calculem e_k
            e=ek/(ekk*ekk*ekk); 
            ekk=ek; //per al pas següent
            if(ek==0){ //si x_k=x_{k-1} ja hem trobat l'arrel
                printf("Arrel trobada\n");
                return x;
            }
            printf("x[%u]=%.15lf\n", i , y);
            printf("e[%u]/(e[%u])^3=%.15lf\n", i, i-1, e);
            
            x=y; //per al pas següent
        }
        else {
            printf("Derivada o denominador 0\nf1=%.15lf\nden=%.15lf", f1, den);
            return x;
        }
    }
    return x;
}
