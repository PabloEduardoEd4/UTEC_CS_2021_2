#ifndef CLOCK
#define CLOCK

// Usa el puntero now para determinar el tiempo en el instante
// Para imprimirlo de forma hh:mm:ss
void printTime();

//Imprime la infomacion de la alarma
void printAlarm(bool &alarm, int *alarmtime);

// Usando referencias por objeto y un puntero al comienzo de un array
// La funcion actualiza variable alarm_time basado en el input del
// usuario
void setAlarm(int *alarm_time, bool &current);

// Process la expresion booleana para ver si
// la alarma se activa o no
bool alarmOn(bool &alarm, int *alarm_time);

void alarmOff(bool &alarm, bool &current);

#endif