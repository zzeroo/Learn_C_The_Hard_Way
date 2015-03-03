/*
 * http://www.programiz.com/c-programming/c-structures-pointers
 */
#include <stdio.h>

struct name {
  int a;
  float b;
};

int main() {
  struct name *ptr, p;
  ptr = &p;
  printf("Enter integer: ");
  scanf("%d", &(*ptr).a);
  printf("Enter number: ");
  scanf("%f", &(*ptr).b);
  printf("Displaying: ");
  printf("%d%f", (*ptr).a, (*ptr).b);

  return 0;
}
