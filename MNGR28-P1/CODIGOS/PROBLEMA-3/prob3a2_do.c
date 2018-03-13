#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"prob3.h"

int main(int argc, char* argv[]) {
	 //'n' és el tamany de la mostra, 'dades' és la llista que conté els nombres de la mostra
	int n = 0;
	double* dades;
    
    //'fitxer' és el fitxer de nom 'nom' d'on es llegiran les dades
	FILE* fitxer;
	char* nom = argv[1];
    
	//Comprovem que el fitxer es pot obrir
	if((fitxer = fopen(nom, "r")) == NULL) {
		fprintf(stderr, "ERROR: El fitxer introduït no existeix o no es pot obrir.\n");
		fclose(fitxer);
		return 1;
	}
	
  //Comptem el nombre de línies del fitxer d'entrada, i per tant de dades
	char c;
  while((c = fgetc(fitxer)) != EOF) {
    if(c == '\n') {
      n++;
    }
  }
  
  //Afegim una línia si no hi ha un salt de línia després de l'última línia
  fseek(fitxer, -1, SEEK_END);
  if((c = fgetc(fitxer)) != '\n') {
    n++;
  }
	rewind(fitxer);

	//Assignem la memòria
	dades = (double*) malloc(n*sizeof(double));		

	//Omplim 'dades' amb els valors del fitxer
	int i;
	for(i = 0; i < n; i++) {
		if(fscanf(fitxer, "%lf", &dades[i]) != 1) {
			fprintf(stderr, "ERROR: No s'han pogut llegir correctament les dades de la línia %d.\n", i + 1);	
			fclose(fitxer);
			return 1;
		}
	}

	double mitja = mitja_do(dades, n);
	double var = var2_do(dades, mitja, n);

	printf("La variança del conjunt de dades és: %.17g\n", var);
}
