#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"diferencies_dividides.h"

int main(int argc, char* argv[]) {
	// A 'spline' hi guardarem el resultat d'avaluar el polinomi de Lagrange als 180 punts proposats
  FILE* spline;

	// Fitxer del qual llegirem els nodes i els moments
	FILE* nodes = fopen(argv[1], "r");

	spline = fopen("04-splines.dat", "w");

	// Ordenades dels nodes
	double* x;
	// Abscisses dels nodes
	double* f;
	// Moments dels splines
	double* M;
	// Matriu per a fer el càlcul dels coeficients dels splines
	double** coef;

	// Ordenades dels punts proposats
  double* k; 
	// Resultat d'avaluar els splines als punts proposats
	double* sk;
	// Resultat d'avaluar la funció als punts proposats
	double* fk;
	// 'max' guardarà el màxim error entre la funció i la interpolació, 'kmax' guardarà el punt on es produeix
  double max, kmax;

	// Inicialitzem les llistes
	x = (double*) malloc(4*sizeof(double));
	f = (double*) malloc(4*sizeof(double));
	M = (double*) malloc(4*sizeof(double));
	coef = (double**) malloc(3*sizeof(double*));
	int i;
	for(i = 0; i < 3; i++) {
		coef[i] = (double*) malloc(4*sizeof(double));
	}

	// Llegim els nodes
	for(i = 0; i < 4; i++) {
		if((fscanf(nodes, "%lf\t%lf\t%lf", &x[i], &f[i], &M[i])) != 3) {
			fprintf(stderr, "ERROR: No s'han pogut llegir correctament les dades.\n");
			return 1;
		}
	} 

	// Calculem els coeficients de cada spline
	for(i = 0; i < 3; i++) {
		coef[i][0] = f[i];
		coef[i][1] = (f[i+1] - f[i])/(x[i+1]- x[i]) - (2*M[i] + M[i+1])*(x[i+1] - x[i])/6.;
		coef[i][2] = M[i]/2.;
		coef[i][3] = (M[i+1] - M[i])/(6.*(x[i+1] - x[i]));
	}

	k = (double*) malloc(181*sizeof(double));
	sk = (double*) malloc(181*sizeof(double));
	fk = (double*) malloc(181*sizeof(double));

	// Calculem les ordenades dels punts proposats
  puntosk(k);

	// Determinem a partir d'on hem d'aplicar cada spline
	int n1, n2;	
	for(i = 1; i < 181; i++) {
		if(k[i] <= x[1]) {
			n1 = i;
		} else if(k[i] <= x[2]) {
			n2 = i;
		}
	}

	double x0[3] = {x[0], x[0], x[0]};
	double x1[3] = {x[1], x[1], x[1]};
	double x2[3] = {x[2], x[2], x[2]};

	// Avaluem cada spline als corresponents punts
	for(i = 0; i <= n1; i++) {
		sk[i] = horner(4, coef[0], x0, k[i]);	
		fprintf(spline, "%lf\t%lf\n",k[i], sk[i]);
	}

	for(i = n1 + 1; i <= n2; i++) {
		sk[i] = horner(4, coef[1], x1, k[i]);	
		fprintf(spline, "%lf\t%lf\n",k[i], sk[i]);
	}

	for(i = n2 + 1; i < 181; i++) {
		sk[i] = horner(4, coef[2], x2, k[i]);	
		fprintf(spline, "%lf\t%lf\n",k[i], sk[i]);
	}

	// Avaluem la funció als punts proposats
  for(i = 0; i <= 180; i++) {
    fk[i] = ff(k[i]);
  }

	// Busquem el màxim error comès en la interpolació
  max = 0;
  for(i = 0; i <= 180; i++){
    if(fabs(sk[i] - fk[i]) > max){
      max = fabs(sk[i] - fk[i]);
      kmax = k[i];
    }
  }
  printf("La discrepància màxima entre la funció i el polinomi de lagrange és %lf i es produeix al punt x = %lf\n", max, kmax);



	return 0;

}

