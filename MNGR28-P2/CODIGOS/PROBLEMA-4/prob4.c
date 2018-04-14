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

	double aVell, bVell, sVell, eVell, cVell, pVell;
	double pot = 1;
	int i;
	for(i = 1; i <= n + 1; i++) {
		// Guardem els valors de la iteració anterior
		aVell = a;	
		bVell = b;	
		sVell = s;
    cVell = c;
		eVell = e;
		pVell = p;


		// Iterem cada variable
		a = iterarA(aVell, bVell);
		b = iterarB(aVell, bVell);
		c = iterarC(a, b);
		pot = 2*pot;
		s = sVell - pot*c;
		p = iterarP(a, s);
		e = fabs(p - M_PI);

		// Analitzem l'error
    printf("p[%2d] = %.16lf\n", i - 1, pVell);
    printf("a[%2d] = %.16lf\n", i - 1, aVell);
    printf("b[%2d] = %.16lf\n", i - 1, bVell);
    printf("c[%2d] = %g\n", i - 1, cVell);
    printf("s[%2d] = %.16lf\n", i - 1, sVell);
    printf("e[%2d] = %.16lf\n", i - 1, eVell);
		printf("e[%2d]/e[%2d] = %.16lf\n", i, i - 1, e/(eVell));
		printf("e[%2d]/e[%2d]^2 = %.16lf\n", i, i - 1, e/(eVell * eVell));
		printf("e[%2d]/e[%2d]^3 = %.16lf\n", i, i - 1, e/(eVell * eVell * eVell));
    printf("--------\n");
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

