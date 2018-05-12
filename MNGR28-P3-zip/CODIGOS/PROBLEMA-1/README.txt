Per a compilar cada programa es pot executar 'make <Nom del programa>' o també 'make all' per compilar tots els programes alhora.

El programa 'nodes' genera una llista de n nodes equidistants o de Chebyshev a l'interval [-1,1]. Requereix dos arguments: el primer és 'cheb' o 'eq' segons si volem nodes de Chebyshev o equidistants i el segon és el nombre de nodes. La sortida del programa es guarda en un fitxer de nom 'n-<tipus>.dat', on <tipus> és 'cheb' o 'eq' segons sigui el cas. Si, per exemple, volem 8 nodes de Chebyshev hem de fer 
	> make nodes
	> ./nodes cheb 8

El programa 'prob1' realitza la interpolació. Necessita com a argument el nom d'un fitxer amb una llista de nodes. Genera dos fitxers: 'n-<tipus>-interpolats.dat' que conté el resultat d'avaluar el polinomi interpolador a 181 punts repartis a [-1,1], i 'n-avaluats.dat', que conté el resultat d'avaluar la funció als mateixos 181 punts. També imprimeix per pantalla el màxim error comès. Per executar-lo, per exemple, amb 8 nodes de Chebyshev prèviament calculats fem
	> make prob1
	> ./prob1 08-cheb.dat
	>> La discrepància màxima entre la funció i el polinomi de lagrange és 0.391718 i es produeix al punt x = 0.001000
