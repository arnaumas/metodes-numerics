#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define A M_PI*M_PI/6 //A=pi^2/6 valor exacte

int main(int argc, char* argv[]){
  int n, i; //n és el nombre de termes a sumar, i ens serveix per a contar al for
  double S, k, d, j; //S anirà guardant la suma, k és cadascún dels termes que es suma, d és la discrepància entre el valor exacte i la suma, j és una variable paral·lela a i que s'utilitza per a trobar cada sumand. 

  //Comprovem que s'ha llegit el nombre fins al qual volem sumar correctament
  if((argc==1) || (argc>2)){
    printf("Cal introduir un argument\n");
    return 0;
  }
  if(!(n = atoi(argv[1]))) {
    fprintf(stderr, "ERROR: Introduïu un nombre vàlid.\n");
    return 1;
  }

  //Fixem la suma inicialment a 0
  S=0;

  //Sumem en ordre invers (des del més petit al més gran)
  for(i=n;i>=1;i=i-1){
    j=(double)i;
    k=1/(j*j);
    S=S+k;
  }

  //Retornem el resultat i la discrepància respecte al valor esperat.
  printf("S_%u = %.15lf\n",n, S);
  d=fabs(S-A);
  printf("Discrepància = %.15lf\n",d);
  return 0;
}
