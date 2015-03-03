#include <stdio.h>

struct distance {
  int feet;
  float inch;
};

void Add(struct distance d1, struct distance d2, struct distance *d3);

int main()
{
  struct distance dist1, dist2, dist3;
  printf("First distance\n");
  printf("Enter feet: ");
  scanf("%d", &dist1.feet);
  printf("Enter inch: ");
  scanf("%f", &dist1.inch);

  printf("Second distance\n");
  printf("Enter feet: ");
  scanf("%d", &dist2.feet);
  printf("Enter inch: ");
  scanf("%f", &dist2.inch);

  /* Passing structure variables dist1 and dist2 by value.
   * Structure var dist3 is passed by reference */
  Add(dist1, dist2, &dist3);

  printf("\nSum of distances = %d'-%f.1\"\n", dist3.feet, dist3.inch);

  return 0;
}

/** Adding distances d1 and d2 and store it in d3 */
void Add(struct distance d1, struct distance d2, struct distance *d3)
{
  d3->feet = d1.feet + d2.feet;
  d3->inch = d1.inch + d2.inch;
  if(d3->inch>=12) {
    d3->inch -= 12;
    ++d3->feet;
  }
}
