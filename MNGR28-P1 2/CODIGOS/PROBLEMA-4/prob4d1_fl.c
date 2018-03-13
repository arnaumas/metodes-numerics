#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define A M_PI*M_PI/6 //A=pi^2/6 valor exacte

int main(int argc, char* argv[]){
  int n, i, l, z; //n és el nombre de termes a sumar, i és el nombre de grupets que es poden fer, l i z són contadors que s'utilitzen en els for.
  float S, j1, j2, d, *SS, j, jj; //S és la suma, j1 i j2 són potències de 2 que servexen per a classificar els sumands en cada grupet, d és la discrepància entre el valor exacte i la suma, *SS és un vector on s'emmagatzemen les sumes parcials (suma dels valors de cada grupet), j és una variable paral·lela al contador z que s'utilitza per a trobar cada sumand, i jj és j*j (ja que d'aquesta manera evitem calcular j*j tantes vegades).

  //Comprovem que s'ha llegit el nombre fins al qual volem sumar correctament
  if((argc==1) || (argc>2)){
    printf("Cal introduir un argument\n");
    return 1;
  }

  if(!(n = atoi(argv[1]))) {
    fprintf(stderr, "ERROR: Introduïu un nombre vàlid.\n");
    return 1;
  }

  //Trobem el nombre de grupets que caldrà fer segons el valor mínim fins al qual anem a sumar. Els grupets es fan segons els ordres de magnitud amb potències de 2.
  i=ceil(2*log(n)/log(2));

  //Assignem inicialment el valor 0 a la suma.
  S=0;

  //Reservem l'espai per al vector que guardarà les sumes dels grupets.
  SS=malloc(i*sizeof(float));

  //Emplenem SS inicialment amb zeros, ja que algún grupet queda buit.
  for(l=0;l<=i-1;l=l+1){
    SS[l]=0;
  }

  //comencem per les potències de dos més altes
  j1=pow(2,i);
  j2=pow(2,i-1);

  for(l=1;l<=i;l=l+1){ //conta l'ordre de magnitud (en potències de 2)
    for(z=1;z<=n;z=z+1){ //conta els sumands
      j=(float)z;
      jj=j*j;
      if((j2<=(jj)) && ((jj)<j1)){ //si el denominador jj (de 1/jj) està entre aquestes potències de 2, afegim l'invers a la suma del grupet
        SS[l-1]=SS[l-1]+1/(jj); //dins de cada grupet es suma de major a menor
      }
    }
    //reduïm una potència de 2
    j1=j2; 
    j2=j2/2;
  }

  //Sumem totes les sumes parcials
  for(l=i;l>=1;l=l-1){
    S=S+SS[l-1]; //de major a menor
  }

  //Retornem la suma i la discrepància
  printf("S_%u = %.7lf\n",n, S);
  d=fabs(S-A);
  printf("Discrepància = %.7lf\n",d);
  return 0;
}
