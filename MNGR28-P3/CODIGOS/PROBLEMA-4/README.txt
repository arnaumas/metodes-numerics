Per compilar cada programa només cal executar 'make <Nom del programa>'. També es pot executar 'make all' per compilar tots els programes alhora.

El programa prob4.c calcula l'aproximació de la integral per a el nombre de divisions del interval n desitjat, integracio.c conté els algoritmes de la regla composta dels trapezis i de la regla composta de Simpson i calcula valors de la funció a integrar.

Si es vol calcular l'aproximació de la integral del problema 4 amb n=8 divisions per exemple, només cal executar
 > make prob4
 > ./prob4 8
 >> Trapezis=38.782928156314796
    Estimació error=2.500000000000000

Es pot executar 'make clean' per eliminar els codis objecte i 'make realclean' per eliminar també els executables.