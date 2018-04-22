#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"diferencies_dividides.h"

int main(int argc, char* argv[]) {
	// 'nodes' és el fitxer de nom 'nom' que conté els nodes a partir dels quals es farà la interpolació
	FILE* nodes; 
	char* nom = argv[1];
        
        
        FILE* fitxer; //guardarem els punts i el resultat d'avaluarlos amb el polinomi
        FILE* fitxer1; //guardarem els 180 punts i el resultat d'avaluarlos amb la funcio
        fitxer=fopen("kavaluats.txt", "w"); 
        fitxer1=fopen("k.txt", "w");

	double* x;
	double* f;
	double** difs;
        double *coef; //vector on guardarem els coeficients del polinomi de lagrange. 
        double *k, *pk, *fk; //k punts on avaluarem, pk resultat d'avaluar els punts amb el p. de lagrange, fk resultat d'avaluar els punts a la funció
        double max, kmax; //max serà la discrepància màxima entre el resultat d'avaluar els punts amb el polinomi de lagrange i amb la funció, kmax serà el punt on es produeix.
        
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
	x = (double*) malloc(n*sizeof(double));
	f = (double*) malloc(n*sizeof(double));
	difs = (double**) malloc(n*sizeof(double*));
	int i;
	for(i = 0; i < n; i++) {
		difs[i] = (double*) malloc(n * sizeof(double));
	}

	// Llegim els nodes
	for(i = 0; i < n; i++) {
		if((fscanf(nodes,"%lf\t%lf", &x[i], &f[i])) != 2) {
			fprintf(stderr, "ERROR: No s'han pogut llegir correctament les dades.\n");
		}
	}

	diferencies_dividides(x, f, difs, n);
        coef= malloc(n*sizeof(double));
        
	for(i = 0; i < n; i++) {
		//printf("difs[%d][%d] = %lf \n", i, i, difs[i][i]);
                //printf("x[%d]=%lf\n", i, x[i]);
                coef[i]=difs[i][i];
	}
	
        k=malloc(181*sizeof(double)); //punts on avaluarem
        pk=malloc(181*sizeof(double)); //valors del polinomi al punt avaluat
        puntosk(k); //plenem k
        fk=malloc(181*sizeof(double)); //valors de la funció al punt avaluat
        
        for(i=0;i<=180;i++){ //polinomi de lagrange
            pk[i]=horner(n, coef, x, k[i]);
            fprintf(fitxer, "%lf\t%lf\n",k[i], pk[i]);
        }
            
        for(i=0;i<=180;i++){ //funció
            fk[i]=ff(k[i]);
            fprintf(fitxer1, "%lf\t%lf\n",k[i], fk[i]);
        }
        max=0;
        for(i=0;i<=180;i++){
            if(fabs(pk[i]-fk[i])>max){
                max=fabs(pk[i]-fk[i]);
                kmax=k[i];
            }
        }
        printf("La discrepància màxima entre la funció i el polinomi de lagrange és %lf i es produeix al punt $x_k=%lf\n$", max, kmax);
        
	return 0;
}

