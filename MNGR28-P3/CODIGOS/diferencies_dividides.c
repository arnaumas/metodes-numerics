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
		printf("difs[%d][0] = %lf\n", i, difs[i][0]);
  }

  //Apliquem la recursió
  for(j = 1; j < n; j++) {
    for(i = j; i < n; i++) {
      difs[i][j] = (difs[i][j-1] - difs[i-1][j-1]) / (x[i] - x[i-j]);
			printf("difs[%d][%d] = %lf\n", i, j, difs[i][j]);
    }
  }
}
