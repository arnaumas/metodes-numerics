Per compilar cada programa només cal executar 'make <Nom del programa>'. També es pot executar 'make all' per compilar tots els programes alhora.

El programa prob5.c calcula l'aproximació de la integral, integracio.c conté els algoritmes de la regla composta dels trapezis i de la regla composta de Simpson i calcula valors de la funció a integrar.

Si es vol calcular l'aproximació de la integral del problema 5 només cal executar
 > make prob5
 > ./prob5
 >> Simpson=0.385834602165434	n=2
    Simpson=0.386259562814567	n=4
    Simpson=0.386287163278802	n=6
    Simpson=0.386292043466313	n=8

Es pot executar 'make clean' per eliminar els codis objecte i 'make realclean' per eliminar també els executables.