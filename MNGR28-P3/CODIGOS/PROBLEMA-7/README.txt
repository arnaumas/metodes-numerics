Per a compilar cada programa es pot executar 'make <Nom del programa>' o també 'make all' per compilar tots els programes alhora.

El programa 'prob7' interpola la funció del problema amb 3 splines cúbics a partir dels nodes i moments donats. El fitxer 'coefs.dat' conté 4 nodes de Chebyshev així com els moments associats, calculats prèviament amb SageMath. Per executar el programa podem fer
	> make prob7
	> ./prob7 coefs.dat
	>> La discrepància màxima entre la funció i el polinomi de lagrange és 0.744643 i es produeix al punt x = 0.001000
El programa genera un fitxer anomenat '04-splines.dat' que conté el resultat d'avaluar els splines a 181 punts repartits a [-1,1].
