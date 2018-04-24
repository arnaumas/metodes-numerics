#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "diferencies_dividides.h"

// Guarda en un fitxer una llista que conté n nodes de Chebyshev dins de l'interval [-1,1]
int main(int argc, char* argv[]) { 
  int i, n; 
	// La llista 'cheb' guardarà les ordenades, i 'fcheb' guardarà les imatges dels nodes
  double *cheb, *cheb; 

	// Fitxer on guardarem els nodes
  FILE* nodes; 

	printf("Introduïu el nombre de nodes a generar: \n");
	if(scanf("%d", &n) != 1) {
		fprintf(stderr, "ERROR: Introduïu un enter vàlid.\n");
	} else if(n <= 0) {
		fprintf(stderr, "ERROR: Introduïu un enter vàlid.\n");
	}

	char* nom;
	sprintf(nom, "%d", n);
  nodes = fopen(strcat(nom, "chebyshev.txt"), "w");

	// Inicialitzem les llistes
  cheb = malloc(n*sizeof(double));
  fcheb = malloc(n*sizeof(double));

	// Omplim les llistes
  nodoscheb(n, cheb); 

	// Calculem les imatges i ho volquem al fitxer
  for(i = 0; i < n; i++){
    fcheb[i] = ff(cheb[i]);
    fprintf(nodes, "%lf\t%lf\n",cheb[i], fcheb[i]);
  }

  return 0;
}
