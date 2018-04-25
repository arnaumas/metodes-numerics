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

// Avaluar en el punt 'x' el polinomi de Lagrange de grau n-1 amb coeficients guardats a la llista 'v' i amb punts base guardats a 'p'
double horner(int n, double *v, double *p, double x) { 
	int i; //comptador
  double t; //anirà guardant el resultat
  t = v[n-2] + (x-p[n-2])*v[n-1];
  for(i = n-3; i>=0; i--){
    t = v[i] + (x-p[i])*t;
  }
  return t;
}