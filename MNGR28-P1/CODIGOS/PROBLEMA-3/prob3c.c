#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	double x = 0; //'x' és el nombre central
	int n = 0; //'n' és el nombre de dades a generar
	double  delta = 0; //Les dades no diferiran més de 'delta' de x

	//Legim x, n, delta
	printf("Introduïu el nombre central: ");
	if(scanf("%lf", &x) != 1) {
		fprintf(stderr, "ERROR: Introduïu un nombre vàlid. \n");
		return 1;
	}

	printf("Introduïu la diferència entre les dades: ");
	if(scanf("%lf", &delta) != 1) {
		fprintf(stderr, "ERROR: Introduïu un nombre vàlid. \n");
		return 1;
	}

	printf("Introduïu el nombre de dades a generar: ");
	if(scanf("%d", &n) != 1) {
		fprintf(stderr, "ERROR: Introduïu un enter vàlid. \n");
		return 1;
	}

	//Obrim el fitxer on escriurem les dades
	FILE* sortida = fopen("dades_3c.dat", "w");

	//Generem n números aleatoris
	int i, j;
	double delta_i;

	for(i = 0; i < n; i++) {
		j = rand() % 201 - 100;
		delta_i = (double) j * (delta/100); 
		fprintf(sortida, "%lf\n", x + delta_i);
	}

	rewind(sortida);
	fclose(sortida);

	return 0;
}
