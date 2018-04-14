#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define beta 7.413302725857898 //valor de beta amb 15 decimals correctes

int main() {
    double betado, erdo; //betado serà el resultat de beta calculat amb cardano, erdo serà l'error absolut entre betado i beta
    
    betado=cbrt(200+sqrt(3239997)*(1./9)) + cbrt(200-sqrt(3239997)*(1./9)); //calculem betado
    printf("beta_do=%.15lf\n", betado);
    erdo=fabs(beta-betado); //calculem l'error absolut
    printf("Error absolut double=%.15lf\n",erdo);
    return 0;
}
