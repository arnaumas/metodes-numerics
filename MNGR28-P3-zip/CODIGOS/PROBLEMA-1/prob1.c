#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"diferencies_dividides.h"

int main(int argc, char* argv[]) {
	// A 'interpol' hi guardarem el resultat d'avaluar el polinomi de Lagrange als 180 punts proposats
  FILE* interpol;
	// A 'funcio' hi guardarem el resultat d'avaluar la funcio als 180 punts proposats
  FILE* funcio;

	// Fitxer del qual llegirem els nodes
	FILE* nodes = fopen(argv[1], "r");

	// Comptem el nombre de línies de l'entrada, i per tant el nombre de nodes
	char c;
	int n = -1;
	while((c = fgetc(nodes)) != EOF) {
		if(c == '\n') {
			n++;
		}
	}
	rewind(nodes);

	// Determinem si hem de fer interpolacio amb nodes equidistants o de Chebyshev
	char tipus[50];
	fscanf(nodes, "%s\n", tipus);

	// El resultat de la interpolació es guardarà a un fitxer amb nom 'n-eq-interpolats.dat' o 'n-cheb-interpolats.dat' segons si fem servir els nodes de Chebyshev o equidistants
	char nom1[50];
	char titolcheb[50] = "-cheb-interpolats.dat";
	char titoleq[50] = "-eq-interpolats.dat";
	sprintf(nom1, "%02d", n);
	if(strcmp(tipus, "cheb") == 0) {
		strcat(nom1, titolcheb);
	} else if(strcmp(tipus, "eq") == 0) {
		strcat(nom1, titoleq);
	}
  interpol = fopen(nom1, "w");	

	// El resultat del càlcul directe mitjançant la funció es guardarà a un fitxer amb nom 'n-avaluats.dat'
	char nom2[50];
	char titol2[] = "-avaluats.dat";
	sprintf(nom2, "%02d", n);
	strcat(nom2, titol2);
  funcio = fopen(nom2, "w");	

	// Ordenades dels nodes
	double* x;
	// Abscisses dels nodes
	double* f;
	// Matriu per a fer el càlcul de diferències dividides
	double** difs;
	// Coeficients del polinomi de Lagrange
  double* coef;  

	// Ordenades dels punts proposats
  double* k; 
	// Resultat d'avaluar el polinomi de Lagrange als punts proposats
	double* pk;
	// Resultat d'avaluar la funció als punts proposats
	double* fk;
	// 'max' guardarà el màxim error entre la funció i la interpolació, 'kmax' guardarà el punt on es produeix
  double max, kmax; 

	
	// Inicialitzem les llistes
	x = (double*) malloc(n*sizeof(double));
	f = (double*) malloc(n*sizeof(double));
	coef = (double*) malloc(n*sizeof(double));
	difs = (double**) malloc(n*sizeof(double*));
	int i;
	for(i = 0; i < n; i++) {
		difs[i] = (double*) malloc(n * sizeof(double));
	}

	// Llegim els nodes
	for(i = 0; i < n; i++) {
		if((fscanf(nodes, "%lf\t%lf", &x[i], &f[i])) != 2) {
			fprintf(stderr, "ERROR: No s'han pogut llegir correctament les dades.\n");
			return 1;
		} 
	}

	// Calculem els coeficients del polinomi de Lagrange mitjançant l'algoritme de diferències dividides
	diferencies_dividides(x, f, difs, n);
	for(i = 0; i < n; i++) {
    coef[i] = difs[i][i];
	}

	k = (double*) malloc(181*sizeof(double));
	pk = (double*) malloc(181*sizeof(double));
	fk = (double*) malloc(181*sizeof(double));

	// Calculem les ordenades dels punts proposats
  puntosk(k); 

	// Avaluem el polinomi de Lagrange als punts proposats mitjançant la regla de Horner
  for(i = 0; i <= 180; i++) { 
    pk[i] = horner(n, coef, x, k[i]);
    fprintf(interpol, "%lf\t%lf\n",k[i], pk[i]);
  }

	// Avaluem la funció als punts proposats
  for(i = 0; i <= 180; i++) {
    fk[i] = ff(k[i]);
    fprintf(funcio, "%lf\t%lf\n",k[i], fk[i]);
  }

	// Busquem el màxim error comès en la interpolació
  max = 0;
  for(i = 0; i <= 180; i++){
    if(fabs(pk[i] - fk[i]) > max){
      max = fabs(pk[i] - fk[i]);
      kmax = k[i];
    }
  }
  printf("La discrepància màxima entre la funció i el polinomi de lagrange és %lf i es produeix al punt x = %lf\n", max, kmax);

	return 0;
}

