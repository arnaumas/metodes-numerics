#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define A M_PI*M_PI/6 //A=pi^2/6 valor exacte

float kahan(int vmax, float *v); //*v és el vector on s'emmagatzemen els termes que es sumaran, vmax és la longitud menys 1 de *v

int main(int argc, char* argv[]){
  int n, i; //n és el nombre de termes a sumar, i ens serveix per a contar al for
  float *v, j, k, dis; //*v és el vector on s'emmagatzemen els termes que es sumaran, j és una variable paral·lela a i que s'utilitza per a trobar cada sumand, k és la variable a la que se li assigna el resultat de la suma fent kahan, dis és la discrepància entre el valor exacte i la suma.

  //Comprovem que s'ha llegit el nombre fins al qual volem sumar correctament
  if((argc==1) || (argc>2)){
    printf("Cal introduir un argument\n");
    return 1;
  }

  if(!(n = atoi(argv[1]))) {
    fprintf(stderr, "ERROR: Introduïu un nombre vàlid.\n");
    return 1;
  }

  //Generem i emplenem el vector amb els sumands (en ordre creixent)
  v=malloc(n*sizeof(float));
  for(i=1;i<=n;i=i+1){
    j=(float)i;
    v[i-1]=1/(j*j);
  }

  //Executem la suma i calculem la discrepància.
  k=kahan(n-1,v);
  dis=fabs(A-k);

  //Retornem la suma i la discrepància respecte al valor esperat
  printf("S_%u = %.7f\n Discrepància = %.7f\n", n, k, dis);
  return 0;
}

float kahan(int vmax, float *v){ //retorna la suma dels valors guardats en *v amb l'algoritme de suma de kahan.
  int i; //i ens serveix per a contar al for
  float sum, t, c, y; //t i sum aniran guardant la suma, c guardarà les xifres perdudes al sumar valors petits a grans, y serà el terme que s'afegirà cada cop a la suma, que tindrà en compte el valor a sumar (v[i]) i els dígits perduts en les iteracions anteriors. 

  //Iniciem la suma amb el primer valor de *v
  sum=v[0];

  //Inicialitzem c amb 0
  c=0;

  //Algoritme de suma de kahan
  for(i=1;i<=vmax;i=i+1){//sumem de major a menor
    y=v[i]-c; //y pren el valor a sumar: v[i], i li afegeix les xifres perdudes acumulades a c
    t=sum+y; //sum és la suma del pas anterior i se li afegeix y, t és la suma d'aquest pas.
    c=(t-sum)-y; //se li assignen a c les xifres perdudes de y al sumar-lo.
    sum=t; //després d'haver recuperat les xifres a c, assignem t a la suma per al pas següent.
  }//quan l'error acumulat guardat a c sigui prou gran, al afegir-lo a la suma serà capaç de modificar les seues xifres significatives.

  //Retornem la suma
  return sum;
}
