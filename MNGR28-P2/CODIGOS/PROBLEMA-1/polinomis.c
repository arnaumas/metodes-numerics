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


double newtonpolinomi(double x0, int k, double *v, int n) { //x0 punt inicial, k nombre d'iteracions, *v polinomi, n grau polinomi
    double *dv, x, y, t; //a dv guardarem el polinomi derivada, a x anirem guardant la succesió x_n, y serà el resultat d'avaluar f(x_n), t serà el resultat d'avaluar f'(x_n)
    int i; //és un comptador
    
    dv=malloc(n*sizeof(double)); //creem dv
    
    if((v==NULL) || (dv==NULL)) {
        printf("Error al reservar memòria\n");
    }
    
    derivarpolinomi(v, n, dv); //guardem el polinomi derivada en dv
    
    x=x0; //comencem la succesió
    for(i=1;i<=k;i++) {
        y=avaluarpolinomi(v,n,x);
        t=avaluarpolinomi(dv,n-1,x);
        if(t!=0){ //si la derivada en x_n es diferent de zero fa un nou pas
            x=x-(y/t);
            printf("x[%u]=%.15lf\n", i, x); //imprimim els valors de la succesió
            if(y==0){ //el resultat d'avaluar f(x_n) és zero, per tant x_n=arrel
                printf("Arrel trobada.\n");
                return x;
            }
        }
        else{
            printf("Error, derivada 0\n");
            return 1;
        }
    }
    free(dv);
    return x; //retornem x_k després de k iteracions
}


double secantpolinomi(double a, double b, int k, double *v, int n) { //[a,b] interval s'agafa x0=a, x1=b, k nombre d'iteracions, *v coeficients polinomi, n grau polinomi
    int i; //comptador
    double x, y, z, f2, f1; //x=x_(n-1), y=x_n, f2=f(x_n), f1=f(x_(n-1)), z és un auxiliar per a guardar momentaniament una variable
    x=a; //iniciem la succesió
    y=b;
    for(i=1;i<=k;i++) {
        f1=avaluarpolinomi(v, n, x);
        //printf("f1=%.15lf\n",f1);
        f2=avaluarpolinomi(v, n, y);
        //printf("f2=%.15lf\n",f2);
        if((f2-f1)!=0) { //si el denominador es diferent de zero
             z=y; //z=x_n
             y=(x*f2-y*f1)/(f2-f1); //y=x_n+1
             x=z; //x=x_n
             printf("x[%u]=%.15lf\n", i, y);
        }
        else {
            printf("f(x_n)=f(x_(n-1))\n"); 
            return y;
        }
    }
    return y;
}


double bisecciopolinomi(double a, double b, int k, double *v, int n) {//[a,b] interval s'agafa x0=a, x1=b, k nombre d'iteracions, *v coeficients polinomi, n grau polinomi
    int i; //comptador
    double x, y, p, f2, f1; //interval [x,y], punt mig p, f1=f(x), f2=f(p)
    x=a; //iniciem interval [a,b]
    y=b;
    for(i=1; i<=k; i++) {
        p=(x+y)/2; //calculem punt mig
        printf("p[%u]=%.15lf\n", i , p);
        f1=avaluarpolinomi(v, n, x);
        f2=avaluarpolinomi(v, n, p);
        if(f2==0){
            printf("Arrel trobada p[%u]=%.15lf\n", i, p);
            return p;
        }
        if((f1*f2)<=0){ //arrel entre x i p, nou interval [x,p]
            y=p;
        }
        else{ //arrel entre p i y, nou interval [p,y]
            x=p;
        }
    }
    return p;
}













void llegirpolinomifl(int argc, char* argv[], float *v, int n) {//argc nombre d'arguments main, argv[] arguments main, *v vector on guardarem el polinomi, n grau del polinomi
    
    int i, j; //són comptadors, utilitzem dos perque el primer argument de la funció és el coeficient n, el segon el n-1, el tercer el...
    
    j=1;
    
    for(i=n;i>=0;i=i-1) {
        if( !(v[i] = atof(argv[j]) )) { //guardem dins del vector v els coeficients del polinomi v[n]=a_n 
            printf("\n");
        }
        //printf("v[%u]=%.8f\n", i, v[i]);
        j=j+1;
    }
}


void derivarpolinomifl(float *v, int n, float *dv) {//deriva el polinomi de grau n guardat en v i guarda el polinomi derivada en dv
    int i;
    
    for(i=n;i>0;i=i-1) { //i*a_i*x^{i-1}
        dv[i-1]=i*v[i];
        //printf("dv[%u]=%.8f\n", i-1, dv[i-1]);
    }
    
}

float avaluarpolinomifl(float *v, int n, float x) {//avalua x al polinomi de grau n guardat a v. Aquesta no és la manera més eficient d'avaluar polinomis, però com que a la práctica només avaluarem fins a polinomis de grau 3, tampoc suposa massa problema.
    int i, j; //són comptadors
    float *r, rr; //a r copiarem v, rr anirà guardant la suma de l'avaluació del polinomi.
    rr=v[0]; //inicialitzem rr amb a_0
    r=malloc((n+1)*sizeof(float)); 
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


float newtonpolinomifl(float x0, int k, float *v, int n) { //x0 punt inicial, k nombre d'iteracions, *v polinomi, n grau polinomi
    float *dv, x, y, t; //a dv guardarem el polinomi derivada, a x anirem guardant la succesió x_n, y serà el resultat d'avaluar f(x_n), t serà el resultat d'avaluar f'(x_n)
    int i; //és un comptador
    
    dv=malloc(n*sizeof(float)); //creem dv
    
    if((v==NULL) || (dv==NULL)) {
        printf("Error al reservar memòria\n");
    }
    
    derivarpolinomifl(v, n, dv); //guardem el polinomi derivada en dv
    
    x=x0; //comencem la succesió
    for(i=1;i<=k;i++) {
        y=avaluarpolinomifl(v,n,x);
        t=avaluarpolinomifl(dv,n-1,x);
        if(t!=0){ //si la derivada en x_n es diferent de zero fa un nou pas
            x=x-(y/t);
            printf("x[%u]=%.8f\n", i, x); //imprimim els valors de la succesió
            if(y==0){ //el resultat d'avaluar f(x_n) és zero, per tant x_n=arrel
                printf("Arrel trobada.\n");
                return x;
            }
        }
        else{
            printf("Error, derivada 0\n");
            return 1;
        }
    }
    free(dv);
    return x; //retornem x_k després de k iteracions
}

