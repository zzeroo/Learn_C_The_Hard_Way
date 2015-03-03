#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct sensor {
  char name[50];
  int value;
};

void Display(struct sensor sen);
int read_adc_channel(int channel);

int main(){
  struct sensor s1;
  printf("Name Sensor1: ");
  scanf("%s", (char *)&s1.name);
  s1.value = read_adc_channel(1);

  Display(s1);

  return 0;
}

void Display(struct sensor sen) {
  printf("Sensor Name: %s\n", sen.name);
  printf("Sensor Wert: %d\n", sen.value);
}

int read_adc_channel(int channel)
{
  /* seed rand function with current time stamp */
  srand(time(NULL));
  return rand();
}

