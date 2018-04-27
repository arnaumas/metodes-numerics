#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include"diferencies_dividides.h"

// Guarda en un fitxer una llista que conté n nodes equidistants dins de l'interval [-1,1]
int main(int argc, char* argv[]) { 
  int i, n; 
	// La llista 'x' guardarà les ordenades, i 'f' guardarà les imatges dels nodes
  double *x, *f; 

	if(argc != 3) {
		fprintf(stderr, "ERROR: Introduïu el tipus de nodes i un paràmetre enter.\n");
	}
	n = atoi(argv[2]);

	// Inicialitzem les llistes
  x = malloc(n*sizeof(double));
  f = malloc(n*sizeof(double));

	char nom[50];
	sprintf(nom, "%02d", n);
	if(strcmp(argv[1], "cheb") == 0) {
		strcat(nom, "-cheb.dat");
	} else if(strcmp(argv[1], "eq") == 0) {
		strcat(nom, "-eq.dat");
	}	
	FILE* nodes = fopen(nom, "w");
	fprintf(nodes, "%s\n", argv[1]);

	// Omplim les llistes
	if(strcmp(argv[1], "eq") == 0) {
  	nodosequi(n, x); 
	} else if(strcmp(argv[1], "cheb") == 0) {
		nodoscheb(n, x);
	}

	// Calculem les imatges i ho volquem a la sortida
  for(i = 0; i < n; i++){
    f[i] = ff(x[i]);
    fprintf(nodes, "%lf\t%lf\n",x[i], f[i]);
  }

  return 0;
}
