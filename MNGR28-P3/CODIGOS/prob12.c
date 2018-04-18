#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"diferencies_dividides.h"

int main(int argc, char* argv[]) {
	// 'nodes' és el fitxer de nom 'nom' que conté els nodes a partir dels quals es farà la interpolació
	FILE* nodes; 
	char* nom = argv[1];

	// Comprovem que el fitxer es pot obrir
	if((nodes = fopen(nom, "r")) == NULL) {
		fprintf(stderr, "ERROR: El fitxer introduït no existeix o no es pot obrir.\n");	
		return 1;
	}

	// Comptem el nombre de línies del fitxer d'entrada, i per tant el nombre de nodes
	char c;
	int n = 0;
	while((c = fgetc(nodes)) != EOF) {
		if(c == '\n') {
			n++;
		}
	}

 	// Afegim una línia si no hi ha un salt de línia després de l'última línia
  fseek(nodes, -1, SEEK_END);
  if((c = fgetc(nodes)) != '\n') {
    n++;
  }
	rewind(nodes);

	// Inicialitzem les llistes
	double* x = (double*) malloc(n*sizeof(double));
	double* f = (double*) malloc(n*sizeof(double));
	double** difs = (double**) malloc(n*sizeof(double*));
	int i;
	for(i = 0; i < n; i++) {
		difs[i] = (double*) malloc(n*sizeof(double));
	}

	// Llegim els nodes
	for(i = 0; i < n; i++) {
		if((fscanf(nodes,"%lf, %lf", &x[i], &f[i])) != 2) {
			fprintf(stderr, "ERROR: No s'han pogut llegir correctament les dades.\n");
		}
		printf("x = %lf, f = %lf\n", x[i], f[i]);
		
	}


	diferencies_dividides(x, f, difs, n);
	for(i = 0; i < n; i++) {
		printf("difs[%d][%d] = %lf \n", i, i, difs[i][i]);
	}
	return 0;
}

