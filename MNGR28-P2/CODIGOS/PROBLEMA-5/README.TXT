Per compilar cada programa només cal executar 'make <Nom del programa>'. També es pot executar 'make all' per compilar tots els programes alhora.

El programa probextrag calcula iteracions de a_n amb x_0=1 com a punt inicial. El programa probextrah calcula l'arrel del nombre desitjat utilitzant f(x) com a aproximació de sqrt(1+x) com a quocient de polinomis de grau 3, i de grau 1.

Per executar probextrag només cal fer
	> make probextrag
	> ./probextrag
            >> 
            g[a0]=1.890824e-05
            g[a1]=2.109448e-37
            g[a2]=4.537551e-261

Per executar probextrah si volem calcular per exemple l'arrel de 2 només cal fer
	> make probextrah
	> ./probextrah 2
            >> 
            a=1.890824e-05
            a=2.109448e-37
            polinomis 3 arrel de 2.000000=1.414214553395256
            s'ha trobat amb 2 iteracions
            a=2.040816e-02
            a=5.153446e-07
            a=8.554074e-21
            polinomis 1 arrel de 2.000000=1.414213562373095
            s'ha trobat amb 3 iteracions
