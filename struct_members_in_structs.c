/*
 * Dieses Testprogramm veranschaulicht den Zusammenhang zwischen den Sensor
 * Strukturen und der Modbus_Mapping Structur (4 Pointer zu 8 und 16 bit Arrays)
 *
 * Ziel dieses Konstrukts ist es im Code die Eigenschaften des Sensors mit
 * den Modbus Datenstrukturen zu verbinden.
 * Aendert man Eigenschaften des Sensors, sollen automatisch die Modbus Register
 * aktualisert werden.
 */
#include <stdio.h>
#include <errno.h>
#include <modbus.h>

/* Sehr vereinfachte Struktur des Sensors */
typedef struct {
  char *name;
  uint16_t *adc_value;
} sensor_t;


int main(int argc, char *argv[])
{
  /*
   * Boilerplate Code fuer die Modbus Datenstruktur
   * 2 Coils, 2 Input Bits, 2 Input Register und 2 Register.
   * */
  modbus_mapping_t *mb_mapping;
  mb_mapping = modbus_mapping_new(2, 2, 2, 2);
  if (mb_mapping == NULL) {
    fprintf(stderr, "Failed to allocate the mapping: %s\n", modbus_strerror(errno));
    return -1;
  }

  /* sensor1 wird erstellt und initalisiert.
   * Der springende Punkt ist der adc_value Struktur Member. Dieser ist die
   * (Pointer) Adresse des entsprechenden Modbus Registers.*/
  sensor_t sensor1;
  sensor1.name = "NO2 Sensor";
  sensor1.adc_value = &mb_mapping->tab_registers[0];

  /* Auch der 2. Sensor sensor2 wird erstellt und initalisiert. Hier auch wieder
   * adc_value beachten, beim 2. Sensor ist das auch das 2. Modbus Register. */
  sensor_t sensor2;
  sensor2.name = "CO Sensor";
  sensor2.adc_value = &mb_mapping->tab_registers[1];


  /* Im folgenden Code werden der Zusammenhang zwischen der Sensor Eigenschaft
   * adc_value und dem entsprechenden Modbus Register gezeigt.
   *
   * Aendert man die den ADC Wert des Sensors (* Pointerschreibweise beachten),
   * z.B. '*sensor1.adc_value = 123' dann aendert sich damit auch automatisch
   * der entsprechende Modbus Registerwert.
   */
  printf("Before changing sensors adc_value.\n");
  printf("Sensor1 Name: %s\n", sensor1.name);
  printf("mb_mapping->tab_registers[0]: %d\n", mb_mapping->tab_registers[0]);
  printf("Sensor2 Name: %s\n", sensor2.name);
  printf("mb_mapping->tab_registers[1]: %d\n", mb_mapping->tab_registers[1]);
  printf("\nMemory locations:\n");
  printf("sensor1.adc_value:             %d\n", sensor1.adc_value);
  printf("&mb_mapping->tab_registers[0]: %d\n", &mb_mapping->tab_registers[0]);

  printf("\n-------------------------------\n");

  printf("After change *sensor1.adc_value = 27\n");
  printf("and          *sensor2.adc_value = 67\n");
  *sensor1.adc_value = 27;
  *sensor2.adc_value = 67;
  printf("mb_mapping->tab_registers[0]: %d\n", mb_mapping->tab_registers[0]);
  printf("mb_mapping->tab_registers[1]: %d\n", mb_mapping->tab_registers[1]);

  printf("\n-------------------------------\n");

  printf("Another change on *sensor1.adc_value = 1021\n");
  printf("and               *sensor2.adc_value = 1023\n");
  *sensor1.adc_value = 1021;
  *sensor2.adc_value = 1023;
  printf("mb_mapping->tab_registers[0]: %d\n", mb_mapping->tab_registers[0]);
  printf("mb_mapping->tab_registers[1]: %d\n", mb_mapping->tab_registers[1]);

  return 0;
}
