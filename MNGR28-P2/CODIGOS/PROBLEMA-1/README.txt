Per compilar cada programa només cal executar 'make <Nom del programa>'. També es pot executar 'make all' per compilar tots els programes alhora.

Els programes que calculen les arrels alfa i beta utilitzant les fórmules de Cardano són prob1a i prob1c respectivament.

Per executar, si es vol calcular alfa amb les fórmules de Cardano només cal fer:
	> make prob1a
	> ./prob1a
            >> 
            alfa_do=3.517393514052852
            Error absolut double=0.000000000000035
            alfa_fl=3.51738477
            Error absolut double=0.00000875

            
i si es vol calcular beta amb les fórmules de Cardano:
	> make prob1c
	> ./prob1c
            >> 
            beta_do=7.413302725859884
            Error absolut double=0.000000000001986
            

Els programes que calculen l'arrel d'un polinomi qualsevol utilitzant el mètode de Newton prenent com a punt inicial x_0=2 en precisió doble i simple són prob1b_do i prob1b_fl respectivament. 

Per executar, si es vol calcular l'arrel de x^3-x-40 en precisió doble per exemple, només cal fer:
	> make prob1b_do
	> ./prob1b_do 1 0 -1 -40
            >> 
            Newton
            x[1]=5.090909090909091
            x[2]=3.959317521070509
            x[3]=3.565915971734928
            x[4]=3.518068471972249
            x[5]=3.517393647122214
            x[6]=3.517393514052823
            x[7]=3.517393514052818
            x[8]=3.517393514052818
            x[9]=3.517393514052818
            Arrel trobada.

El programa que calcula l'arrel d'un polinomi qualsevol utilitzant els mètodes de la bisecció i de la secant a l'interval [2,8], de Newton amb punt inicial x_0=2 és prob1c123.

Per executar, si es vol calcular l'arrel de x^3-x-400 només cal fer:
	> make prob1c123
	> ./prob1c123 1 0 -1 -400
            >>
            Bisecció
            p[1]=5.000000000000000
            p[2]=6.500000000000000
            p[3]=7.250000000000000
            p[4]=7.625000000000000
            p[5]=7.437500000000000
            p[6]=7.343750000000000
            p[7]=7.390625000000000
            p[8]=7.414062500000000
            p[9]=7.402343750000000
            p[10]=7.408203125000000
            p[11]=7.411132812500000
            p[12]=7.412597656250000
            p[13]=7.413330078125000
            p[14]=7.412963867187500
            p[15]=7.413146972656250
            p[16]=7.413238525390625
            p[17]=7.413284301757812
            p[18]=7.413307189941406
            p[19]=7.413295745849609
            p[20]=7.413301467895508
            p[21]=7.413304328918457
            p[22]=7.413302898406982
            p[23]=7.413302183151245
            p[24]=7.413302540779114
            p[25]=7.413302719593048
            p[26]=7.413302809000015
            p[27]=7.413302764296532
            p[28]=7.413302741944790
            p[29]=7.413302730768919
            p[30]=7.413302725180984
            p[31]=7.413302727974951
            p[32]=7.413302726577967
            p[33]=7.413302725879475
            p[34]=7.413302725530230
            p[35]=7.413302725704852
            p[36]=7.413302725792164
            p[37]=7.413302725835820
            p[38]=7.413302725857648
            p[39]=7.413302725868562
            p[40]=7.413302725863105
            p[41]=7.413302725860376
            p[42]=7.413302725859012
            p[43]=7.413302725858330
            p[44]=7.413302725857989
            p[45]=7.413302725857818
            p[46]=7.413302725857903
            p[47]=7.413302725857861
            p[48]=7.413302725857882
            p[49]=7.413302725857893
            p[50]=7.413302725857898
            Arrel trobada p[50]=7.413302725857898
            Secant
            x[1]=6.746987951807229
            x[2]=7.359991138481768
            x[3]=7.418455773193065
            x[4]=7.413265278979376
            x[5]=7.413302699681577
            x[6]=7.413302725858031
            x[7]=7.413302725857899
            x[8]=7.413302725857898
            x[9]=7.413302725857898
            f(x_n)=f(x_(n-1))
            Newton
            x[1]=37.818181818181820
            x[2]=25.311246467958675
            x[3]=17.091175778305605
            x[4]=11.864107393757426
            x[5]=8.877687285156050
            x[6]=7.642542744562808
            x[7]=7.420149160593550
            x[8]=7.413309079459719
            x[9]=7.413302725863377
            x[10]=7.413302725857898
            x[11]=7.413302725857898
            Arrel trobada.

