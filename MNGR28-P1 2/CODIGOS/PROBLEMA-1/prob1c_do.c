#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define tol 1e-16

int main(int argc, char* argv[]) {
	/* La variable 'x' guardarà el valor introduït, i 'resultat' guardarà f(x) */
  double x, resultat;

	/* Comprovem que s'ha introduït un argument */
  if((argc == 1) || (argc > 2)){
    fprintf(stderr, "ERROR: Cal introduir un argument.\n");
    return 1;
  }

	/* Comprovem que el paràmetre introduït dóna un valor vàlid */
	if(!(x = atof(argv[1]))) {
		fprintf(stderr, "ERROR: Introduïu un nombre vàlid.\n");
		return 1;
	}

	/* Si el nombre és prou proper a 0 retornem 1/2 */
  if(fabs(x) < tol){
    resultat = 0.5;
  }
  else {
    resultat = (2 * sin(x/2) * sin(x/2)) / (x*x);
  }

  printf("f(%g) = %.15lf\n", x, resultat);
  return 0;
}
