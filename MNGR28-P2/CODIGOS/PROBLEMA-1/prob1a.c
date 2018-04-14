#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define alfa 3.517393514052818 //valor amb 15 decimals correctes de l'arrel

int main() {
    float alfafl, erfl; //alfafl arrel calculada utilitzant cardano en precisió simple, erfl error absolut alfafl respecte alfa
    double alfado, erdo; //alfado arrel calculada utilitzant cardano en precisió doble, erdo error absolut alfado respecte alfa
    
    alfado=cbrt(20+sqrt(32397)*(1./9)) + cbrt(20-sqrt(32397)*(1./9)); //calculem alfafl 
    printf("alfa_do=%.15lf\n", alfado);
    erdo=fabs(alfa-alfado); //calculem error absolut
    printf("Error absolut double=%.15lf\n",erdo);
    
    alfafl=cbrtf(20+sqrtf(32397)*(1./9)) + cbrtf(20-sqrtf(32397)*(1./9)); //calculem alfado
    printf("alfa_fl=%.8f\n", alfafl);
    erfl=fabs(alfa-alfafl); //calculem error absolut
    printf("Error absolut double=%.8f\n",erfl);
    
    return 0;
}