Per compilar cada programa només cal executar 'make <Nom del programa>'. També es pot executar 'make all' per compilar tots els programes alhora.

El programa prob3.c calcula l'aproximació de la integral, integracio.c conté els algoritmes de la regla composta dels trapezis i de la regla composta de Simpson i calcula valors de la funció a integrar.

Si es vol calcular l'aproximació de la integral del problema 3 només cal executar
 > make prob3
 > ./prob3
 >> Simpson=0.785392156862745
    Error Simpson=0.000006006534703
    Trapezis=0.782794117647059
    Error trapezis=0.002604045750389


Es pot executar 'make clean' per eliminar els codis objecte i 'make realclean' per eliminar també els executables.