#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Càlcul de la mitjana en precisió simple
float mitja_fl(float* dades, int n) {
	float mitja = 0;

	int i;
	for(i = 0; i < n; i++) {
		mitja += dades[i];
	}
	mitja = mitja/n;

	return mitja;
}

//Càlcul de la mitjana en precisió doble
double mitja_do(double* dades, int n) {
	double mitja = 0;

	int i;
	for(i = 0; i < n; i++) {
		mitja += dades[i];
	}
	mitja = mitja/n;

	return mitja;
}

//Càlcul de la variància amb dos bucles en precisió simple
float var2_fl(float* dades, float mitja, int n) {
	float var = 0;

	int i;
	for(i = 0; i < n; i++) {
		var += (dades[i] - mitja)*(dades[i] - mitja);
	}
	
	if(n > 1) {
		var = var/(n - 1);
	}
	return var;
}

//Càlcul de la variància en dos bucles en precisió simple 
double var2_do(double* dades, double mitja, int n) {
	double var = 0;

	int i;
	for(i = 0; i < n; i++) {
		var += (dades[i] - mitja)*(dades[i] - mitja);
	}
	
	if(n > 1) {
		var = var/(n - 1);
	}
	return var;
}

//Càlcul de la variància en un bucle en precisió simple
float var1_fl(float* dades, int n) {
	float var;

	int i;
	float suma1 = 0;
	float suma2 = 0;
	for(i = 0; i < n; i++) {
		suma1 += (dades[i])*(dades[i]);
		suma2 += dades[i];
	}
	
	var = suma1 - ((suma2)*(suma2))/n;

	if(n > 1) {
		var = var/(n - 1);
	}
	return var;
}

//Càlcul de la variància en un bucle en precisió doble
double var1_do(double* dades, int n) {
	double var;

	int i;
	double suma1 = 0;
	double suma2 = 0;
	for(i = 0; i < n; i++) {
		suma1 += (dades[i])*(dades[i]);
		suma2 += dades[i];
	}
	
	var = suma1 - ((suma2)*(suma2))/n;

	if(n > 1) {
		var = var/(n - 1);
	}
	return var;
}
