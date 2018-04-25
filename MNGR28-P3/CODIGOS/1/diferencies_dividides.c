#include<stdio.h>
#include<math.h>
#include"diferencies_dividides.h"

void diferencies_dividides(double* x, double* f, double** difs, int n) {
	//Omplim la matriu de diferències dividides
  int i, j;
	for(i = 1; i < n; i++) {
		for(j = 1; j < n; j++) {
			difs[i][j] = 0;
		}
	}


  //Inicialitzem la primera columna
  for(i = 0; i < n ; i++) {
    difs[i][0] = f[i];
  }

  //Apliquem la recursió
  for(j = 1; j < n; j++) {
    for(i = j; i < n; i++) {
      difs[i][j] = (difs[i][j-1] - difs[i-1][j-1]) / (x[i] - x[i-j]);
    }
  }
}

double horner(int n, double *v, double *p, double x) { //avaluar en x el polinomi de grau n-1 que té els coeficients de les diferencies dividides guardats en v, el vector p guarda els punts base
    int i; //comptador
    double t; //anirà guardant el resultat
    t=v[n-2]+(x-p[n-2])*v[n-1];
    for(i=n-3;i>=0;i--){
       t=v[i]+(x-p[i])*t;
    }
    return t;
}




double ff(double x) {
    double f;
    f=1/(1+25*x*x);
    return f;
}

void nodosequi(int n, double *v) {
    int j; //comptador
    for(j=0;j<=n;j++){
        v[j]=-1+j*2./n;
    }
}

void nodoscheb(int n, double *v) {
    int j; //comptador
    for(j=0;j<=n; j++) {
        v[j]=cos(((2.*j+1)/(n+1))*M_PI/2);
    }
}

void puntosk(double *v) {
    int j;
    for(j=0;j<=180;j++){
        v[j]=-0.989+j*0.011;
    }
}

