#include <iostream>
#include "clock.h"

// La libreria en el centro del codigo
// ctime puedo conseguir el timpo actual
#include <ctime>

// iomanip manipula input y output para hacer que el tiempo
// imprimido se vea bonito, haciedo que las horas
// tiene el estandard 00:00 formato
#include <iomanip>

// Retorna un puntero con objeto std::localtime para determinar
// el tiempo en este instante en forma de 24 horas
std::tm *time()
{
    std::time_t result = std::time(nullptr);
    return std::localtime(&result);
}

// Usa el puntero now para determinar el tiempo en el instante
// Para imprimirlo de forma hh:mm:ss
void printTime()
{
    std::tm *now = time();
    std::cout
        << std::setw(2) << std::setfill('0') << (now->tm_hour) << ':'
        << std::setw(2) << std::setfill('0') << (now->tm_min) << ':'
        << std::setw(2) << std::setfill('0') << (now->tm_sec) << std::endl;
    return;
}

//Imprime la infomacion de la alarma
void printAlarm(bool &alarm, int *alarmtime)
{
    // impirme todo los numeros en alarmtime para
    // imprimir la hora que esta en el instante
    for (int i = 0; i < 3; i++)
    {
        std::cout << std::setw(2) << std::setfill('0') << alarmtime[i] << ':';
    }
    //formateo usando backspace para limpiar el ultimo ':'
    std::cout << '\b';
    std::cout << ' ' << '\t'
              << "Activated?: " << (alarm ? "Yes" : "No")
              << std::endl;
    return;
}

// Usando referencias por objeto y un puntero al comienzo de un array
// La funcion actualiza variable alarm_time basado en el input del
// usuario
void setAlarm(int *alarm_time, bool &current)
{
    current = false;
    std::cout << "Set Alarm (Invalid times will be repiared/ moded to fit)" << std::endl;
    std::cout << "Hour/Hora: ";
    std::cin >> alarm_time[0];
    std::cout << "Minute/Minuto: ";
    std::cin >> alarm_time[1];
    std::cout << "Second/Segundo: ";
    std::cin >> alarm_time[2];
    alarm_time[0] %= 24;
    alarm_time[1] %= 60;
    alarm_time[2] %= 60;
    return;
}

// Process la expresion booleana para ver si
// la alarma se activa o no
bool alarmOn(bool &alarm, int *alarm_time)
{
    std::tm *now = time();
    // Esta expresion determina si alarma es mayor o igual a la alarma
    // set. Basado en eso determina el valor de alarm
    alarm = ((now->tm_hour > alarm_time[0]) ||
             ((now->tm_hour == alarm_time[0]) && ((now->tm_min > alarm_time[1]) ||
                                                  (now->tm_min == alarm_time[1]) && (now->tm_sec >= alarm_time[2]))));
    std::cout << "Alarma esta sonando!" << std::endl;
    return true;
}

void alarmOff(bool &alarm, bool &current)
{
    //simplemente desactiva la alarma
    alarm = false;
    current = true;
}