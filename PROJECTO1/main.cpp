#include <iostream>
#include "clock.h"

int main(int argc, char *argv[])
{
    //Varibles booleanas:
    // - alarma determinado en si alarma esta predido o no
    // - flag para terminar el while loop
    // - current detemina si la alarma se debe quedar desactiva e.i no activarse
    bool alarm = false, flag = true, current = false;

    //Varibles int:
    // - array con {hh, mm, ss} para determinar que hora es en el momento
    // - input, la variable para el do while. Esta con su valor predeterminado 0
    int alarm_time[] = {8, 0, 0}, input;

    //Estructura de control pricipal basado en flow chart
    do
    {
        std::cout
            << "1) Time" << '\n'
            << "2) Alarm Details" << '\n'
            << "3) Set Alarm" << '\n'
            << "4) Turn off alarm" << '\n'
            << "5) Exit" << '\n'
            << ">> ";
        std::cin >> input;
        // solo chequea si alarm esta desactivado y si no se
        // desactivo esta alarma
        if (current)
            ;
        else if (!alarm)
            alarmOn(alarm, alarm_time);
        else if (input != 4)
            std::cout << "Alarma esta sonando!" << std::endl;
        switch (input)
        {
        case 1:
            printTime();
            break;
        case 2:
            printAlarm(alarm, alarm_time);
            break;
        case 3:
            setAlarm(alarm_time, current);
            break;
        case 4:
            if (!current)
            {
                alarmOff(alarm, current);
                std::cout << "Alarma Apagado" << std::endl;
            }
            break;
        case 5:
            flag = false;
            break;
        default:
            break;
        }
    } while (flag);
    // usando el flag deteremino si el while
    // continua o no
}