#include <stdio.h>

int mcd(int a, int b);
void intercambiar(int *a, int *b);

int main() {
  int a, b, c, result;

  printf("Ingrese una ecuacion del tipo ax + by = c\n\n");

  printf("Ingrese el valor de a: ");
  scanf("%d", &a);
  printf("Ingrese el valor de b: ");
  scanf("%d", &b);
  printf("Ingrese el valor de c: ");
  scanf("%d", &c);

  result = mcd(a, b);

  printf("\nEl MCD de %d y %d es: %d", a, b, result);

  if(c % result == 0) {
    printf("\n\nLa ecuacion si tiene soluciones enteras!!");
  }

  return 0;
}

int mcd(int a, int b) {
  int r;

  if(a < b) {
    intercambiar(&a, &b);
  }

  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }

  return a;
}

void intercambiar(int *a, int *b) {
  int aux;
  
  aux = *a;
  *a = *b;
  *b = aux;
}
