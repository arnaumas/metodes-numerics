#include<stdio.h>
#include<math.h>

double iterarP(double, double);
double iterarA(double, double);
double iterarB(double, double);
double iterarC(double, double);

int main() {
	double p, a, b, c, s;
	int n;

	printf("introduïu el nombre d'iteracions a realitzar: ");
	if(scanf("%d", &n) != 1) {
		fprintf(stderr, "Introduïu un enter positiu vàlid.");
		return 1;
	}
	// Inicialitzem la iteració
	double e;
	a = 1;
	b = 1/sqrt(2);
	s = 0.5;
	c = iterarC(a,b);
	p = iterarP(a,s);
	e = fabs(p - M_PI);

	double aVell, bVell, sVell, eVell, cVell;
	double pot = 1;
	int i;
	for(i = 1; i < n; i++) {
		// Guardem els valors de la iteració anterior
		aVell = a;	
		bVell = b;	
		sVell = s;
        cVell = c;
		eVell = e;


		// Iterem cada variable
		a = iterarA(aVell, bVell);
		b = iterarB(aVell, bVell);
		c = iterarC(a, b);
		pot = 2*pot;
		s = sVell - pot*c;
		p = iterarP(a, s);
		e = fabs(p - M_PI);

		// Analitzem l'error
		printf("p[%2d] - pi = %.16lf\n", i, fabs(p - M_PI));
		printf("e[%d]/e[%d]^2 = %.16lf\n", i+1, i, e/(eVell * eVell));
        printf("c[%2d] = %.16lf\n", i - 1, cVell);
        printf("s[%2d] = %.16lf\n", i - 1, sVell);
        printf("a[%2d] = %.16lf\n", i - 1, aVell);
        printf("b[%2d] = %.16lf\n", i - 1, bVell);
        printf("\n");
    }

}

double iterarP(double a, double s) {
	return 2*a*a/s;
}

double iterarA(double a, double b) {
	return (a + b)/2;
}

double iterarB(double a, double b) {
	return sqrt(a*b);
}

double iterarC(double a, double b) {
	return a*a - b*b;
}

