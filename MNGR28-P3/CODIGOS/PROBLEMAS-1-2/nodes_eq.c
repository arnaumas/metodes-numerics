#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include"diferencies_dividides.h"

// Guarda en un fitxer una llista que conté n nodes equidistants dins de l'interval [-1,1]
int main(int argc, char* argv[]) { 
  int i, n; 
	// La llista 'eq' guardarà les ordenades, i 'feq' guardarà les imatges dels nodes
  double *eq, *feq; 

	// Fitxer on guardarem els nodes
  FILE* nodes; 

	printf("Introduïu el nombre de nodes a generar: ");
	if(scanf("%d", &n) != 1) {
		fprintf(stderr, "ERROR: Introduïu un enter vàlid.\n");
	} else if(n <= 0) {
		fprintf(stderr, "ERROR: Introduïu un enter vàlid.\n");
	}

	char nom[50];
	char titol[] = "_equidistants.dat";;
	sprintf(nom, "%d", n);
	strcat(nom, titol);
  nodes = fopen(nom, "w");

	// Inicialitzem les llistes
  eq = malloc(n*sizeof(double));
  feq = malloc(n*sizeof(double));

	// Omplim les llistes
  nodosequi(n, eq); 

	// Calculem les imatges i ho volquem al fitxer
  for(i = 0; i < n; i++){
    feq[i] = ff(eq[i]);
    fprintf(nodes, "%lf\t%lf\n",eq[i], feq[i]);
  }

  return 0;
}
