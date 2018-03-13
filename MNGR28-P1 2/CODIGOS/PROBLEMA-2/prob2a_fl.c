#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  float a, b, c, x1, x2; //ax^2+bx+c=0, x1 i x2 seran les arrels.
  //comprovem que el programa ha rebut correctament els arguments:
  if(!(argc == 4)){
    printf("Cal introduir entre 1 i 3 arguments.\n");
    return 1;
  }

  /*  Assignem els valors i comprovem que el paràmetre introduït dóna un valor vàlid */
  if(!(a = (float)atof(argv[1])) || !(b = (float)atof(argv[2])) || !(c = (float)atof(argv[3]))) {
    fprintf(stderr, "ERROR: Introduïu un nombre vàlid.\n");
    return 1;
  }

  //Examinem el discriminant.
  if(4*a*c>b*b) { //les arrels són complexes.
    printf("No hi ha solucions reals.\n");
    return 0;
  }

  if(4*a*c==b*b) { //hi ha una arrel doble.
    x1=-b/(2*a);
    printf("x1=x2=%.7f\n", x1);
    return 0;
  }

  //hi ha 2 arrels reals.
  x1=(-b+sqrt(b*b-4*a*c))/(2*a);
  x2=(-b-sqrt(b*b-4*a*c))/(2*a);
  printf("x1 = %.7f\nx2 = %.7f\n", x1, x2);
  return 0;
}
