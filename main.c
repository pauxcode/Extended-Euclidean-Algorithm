#include <stdio.h>

int mcd(int a, int b, int c);

void euclideanAlgorithmExtended(int *r, int *q, int *xn, int *x0, int *x1, int *yn, int *y0, int *y1);

int main() {
  int a, b, c, result, opcion;

  printf("/****Bienvenidos al programa****/\n\n");
  printf("Presione 1) Si tiene una ecuacion del tipo ax + by = c\n");
  printf("Presione 2) Si tiene una ecuacion del tipo ax + by\n\n");
  scanf("%d", &opcion);

  printf("\nIngrese el valor de a: ");
  scanf("%d", &a);
  printf("Ingrese el valor de b: ");
  scanf("%d", &b);


  if (opcion == 1) {
    printf("Ingrese el valor de c: ");
    scanf("%d", &c);

    result = mcd(a, b, c); 
  }

  if (opcion == 2) {
    result = mcd(a, b, 0);
  }

  printf("El MCD de %d y %d es: %d", a, b, result);
  return 0;
}

int mcd(int a, int b, int c) {
  int r, aInicial = a, bInicial = b;
  int x0 = 1, x1 = 0, xn, y0 = 0, y1 = 1, yn, q, aux;

  while (b != 0) {
    r = a % b;
    q = a / b;

    euclideanAlgorithmExtended(&r, &q, &xn, &x0, &x1, &yn, &y0, &y1); 
    
    a = b;
    b = r;
  }

  if (c != 0 && c % a == 0) {
    printf("\nLa ecuacion tiene soluciones enteras");
    x1 = (c / a) * x1;
    y1 = (c / a) * y1;

    printf("\n\nSolucion particular para x: %d\n", x1);
    printf("Solucion particular para y: %d\n\n", y1);
   
  } else {
    printf("\nSolucion particular para x: %d\n", x1);
    printf("Solucion particular para y: %d\n\n", y1);
  }
 
  printf("Soluciones para x: %d + %dn\n", x1, bInicial/a);
  printf("Soluciones para y: %d - %dn\n\n", y1, aInicial/a);

  return a;
}


void euclideanAlgorithmExtended(int *r, int *q, int *xn, int *x0, int *x1, int *yn, int *y0, int *y1) {
  if (*r != 0) {
      *xn = *x0 - (*q * *x1);
      *x0 = *x1;
      *x1 = *xn;

      *yn = *y0 - (*q * *y1);
      *y0 = *y1;
      *y1 = *yn;
    }
}

