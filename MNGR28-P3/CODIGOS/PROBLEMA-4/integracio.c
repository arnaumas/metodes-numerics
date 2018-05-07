#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double trapezis(int n, double a, double b, double *fv) {//tindrem n+1 valors de la funcio, a principi de l'interval b final de l'interval, fv vector on estan guardats els valors de la funcio en els n+1 punts.
    int i;
    double h, s;
    h=(b-a)/n;
    s=fv[0]+fv[n];
    for(i=1; i<=n-1; i++){
        s=s+2*fv[i];
    }
    return (h/2)*s;
}




double simpson(int n, double a, double b, double *fv) {
    int i;
    double h, s;
    h=(b-a)/n;
    s=fv[0]+fv[n];
    for(i=1; i<=n-1; i=i+2){ //imparells
        s=s+4*fv[i];
    }
    for(i=2; i<=n-1; i=i+2){ //parells
        s=s+2*fv[i];
    }
    return (h/3)*s;
}




void f1(int n, double a, double b, double *fv) { //n nombre de divisions de l'interval ab (tindrem n+1 valors), a principi de l'interval, b final de l'interval, fv vector on es guardaran els valors de la funció en els n+1 punts.
    int i;
    double x, h;
    h=(b-a)/n;
    for(i=0;i<=n;i++){
        x=a+i*h;
        fv[i]=1/(1+x*x);
    }
}




void f2(int n, double a, double b, double *fv) { //n nombre de divisions de l'interval ab (tindrem n+1 valors), a principi de l'interval, b final de l'interval, fv vector on es guardaran els valors de la funció en els n+1 punts.
    int i;
    double x, h;
    h=(b-a)/n;
    for(i=0;i<=n;i++){
        x=a+i*h;
        fv[i]=exp(x)/x;
    }
}



void f3(int n, double a, double b, double *fv) { //n nombre de divisions de l'interval ab (tindrem n+1 valors), a principi de l'interval, b final de l'interval, fv vector on es guardaran els valors de la funció en els n+1 punts.
    int i;
    double x, h;
    h=(b-a)/n;
    for(i=0;i<=n;i++){
        x=a+i*h;
        fv[i]=log(x);
    }
}

