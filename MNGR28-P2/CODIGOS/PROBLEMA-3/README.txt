Per compilar cada programa només cal executar 'make <Nom del programa>'. També es pot executar 'make all' per compilar tots els programes alhora.

El programa prob3 realitza el métode de Halley amb un polinomi qualsevol, prenent com a punt inicial x_0=2.

Per executar, si es vol trobar l'arrel del polinomi x^3-x-400 amb el métode de Halley
	> make prob3
	> ./prob3 1 0 -1 -400
            >> 
            Halley
            x[1]=3.744064386317907
            x[2]=6.305068367267490
            e[2]/(e[1])^3=0.482750477268219
            x[3]=7.392360605150256
            e[3]/(e[2])^3=0.064731478548905
            x[4]=7.413302612248415
            e[4]/(e[3])^3=0.016292188999870
            x[5]=7.413302725857898
            e[5]/(e[4])^3=0.012369714472980
            Arrel trobada
