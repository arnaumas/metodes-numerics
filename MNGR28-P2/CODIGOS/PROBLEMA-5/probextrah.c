#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define tol 1e-15

double g3(double x);
double f3(double x);
double g1(double x);
double f1(double x);

int main(int argc, char* argv[]) { //l'argument serà el nombre del qual volem calcular l'arrel quadrada
    int i=0, j=0; //comptadors de les iteracions
    double z, a3, b3, a1, b1; //z serà el valor del qual volem calcular l'arrel, a3 succesió a amb polinomis de grau 3, b3 succesió b amb polinomis de grau 3, a1 succesió a amb polinomis de grau 1, b1 succesió b amb polinomis de grau 1
    
    if(argc == 1){
        printf("Cal introduir el nombre del qual vols calcular l'arrel.\n");
        return 1;
    }
    
    z=atof(argv[1]); 
    a3=z-1; //a0
    b3=f3(a3); //b0
    while(a3>tol){
        a3=g3(a3); //a_i
        printf("a=%e\n",a3); //a serveix al mateix temps per a avaluar f i com a mesura de l'error.
        b3=b3*f3(a3); //producte de b fins a i
        i=i+1;
    }
    printf("polinomis 3 arrel de %lf=%.15lf\ns'ha trobat amb %u iteracions\n", z, b3, i);
    a1=z-1; //a0
    b1=f1(a1); //b0
    while(a1>tol){
        a1=g1(a1); //a_i
        printf("a=%e\n",a1);
        b1=b1*f1(a1); //producte de b fins a i
        j=j+1;
    }
    printf("polinomis 1 arrel de %lf=%.15lf\ns'ha trobat amb %u iteracions\n", z, b1, j);
    return 0;
    
}


double g3(double x) {
    int i; //i es un comptador 
    double v[7], y, g; //en v guardarem les x^i, y serà un auxiliar, g serà el valor al avaluar la funció.
    v[0]=x;
    y=x;
    for (i=1;i<=6;i++){
        y=y*x;
        v[i]=y;
    }
    g=v[6]/(49*v[5]+784*v[4]+470*v[3]+13440*v[2]+19712*v[1]+14336*v[0]+4096);
    return g;
}

double f3(double x) { //f(x) polinomis de grau 3
    int i;
    double v[3], y, f, num, den; //f serà el valor en avaluar la funció, num i den el numerador i el denominador respectivament.
    v[0]=x;
    y=x;
    for (i=1;i<=2;i++){
        y=y*x;
        v[i]=y;
    }
    num=7*v[2]+56*v[1]+112*v[0]+64;
    den=v[2]+24*v[1]+80*v[0]+64;
    f=num/den;
    return f;
}

double g1(double x) { //g(x) polinomis de grau 1
    int i;
    double v[3], y, g;
    v[0]=x;
    y=x;
    for (i=1;i<=2;i++){
        y=y*x;
        v[i]=y;
    }
    g=v[2]/(9*v[1]+24*v[0]+16);
    return g;
}

double f1(double x) { //f(x) polinomis de grau 1
    double num, den, f;
    num=3*x+4;
    den=x+4;
    f=num/den;
    return f;
}

