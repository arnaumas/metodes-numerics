Per compilar cada programa només cal executar 'make <Nom del programa>'. També es pot executar 'make all' per compilar tots els programes alhora.

El programa prob2.c calcula una aproximació de x* utilitzant nodes diferents. Els fitxers anomenats positivos1.txt, ..., negativos1.txt, ... simetricos1.txt, indiquen quins nodes hi ha guardats (positius més propers al zero, negatius o simètrics respectivament, i el número final 1, 3 o 5 indica el grau del polinomi que generaran).

Si es vol calcular per exemple l'aproximació de x* utilitzant els nodes positius més propers a 0 i el polinomi de Lagrange de grau 3, només cal executar:
 > make prob2
 > ./prob2 positivos3.txt
 >> x*=2.404822718113948

Es pot executar 'make clean' per eliminar els codis objecte i 'make realclean' per eliminar també els executables.