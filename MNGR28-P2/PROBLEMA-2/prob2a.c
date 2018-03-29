#include<stdio.h>
#include<math.h>

double pol(double);
double der(double);
double iterarX(double, double);
double iterarB(double, double);

int main() {
	double x, b;
	int n;

	printf("Introduïu el nombre d'iteracions a realitzar: ");
	if(scanf("%d", &n) != 1) {
		fprintf(stderr, "Entreu un enter positiu vàlid.\n");
		return 1;
	}	

	printf("Introduïu el pivot inicial: ");
	if(scanf("%lf", &x) != 1) {
		fprintf(stderr, "Entreu un real vàlid.\n");
		return 1;
	}

	// Inicialitzem la iteració
	double xVella, e, eVell;
	b = 1/der(x);	
	xVella = x;	
	x = iterarX(x,b);
	e = fabs(x - xVella);

	int i;
	for(i = 0; i < n; i++) {
		printf("x[%d] = %.16lf\n", i, x);

		xVella = x;
		x = iterarX(x,b);	
		b = iterarB(x,b);

		eVell = e;	
		e = fabs(xVella - x);		
		printf("e[%d]/e[%d]^2 = %.16lf\n", i+1, i, e/(eVell*eVell));
	}
}

double pol(double x) {
	return x*x*x - x - 400;
}

double der(double x) {
	return 3*x*x - 1;
}

double iterarX(double x, double b) {
	return x - b * pol(x);	
}

double iterarB(double x, double b) {
	return b * (2 - der(x) * b);
}
