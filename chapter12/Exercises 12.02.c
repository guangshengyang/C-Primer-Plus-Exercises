/** pe12-2b.c */
#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
    int mode;

    printf("Enter 0 for metric mode, 1 for US mode:");
    scanf("%d", &mode);

    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode"
               "(-1 to quit):");

        scanf("%d", &mode);
    }
    printf("Done.\n");

    return 0;
}

/** pe12-2a.h */

void set_mode(int mode);
void get_info();
void show_info();


/** pe12-2a.h */

#include <stdio.h>

int mode;
double dist, fuel;

void set_mode(int mode)
{
    int last_mode = mode;
    if (mode != 0 || mode != 1)
    {
        if (last_mode == 0)
            printf("Invaliad mode specified. Mode 0(metric) used");
        if (last_mode == 1)
            printf("Invaliad mode specified. Mode 1(US) used");
    }
}

void get_info(void)
{
    extern int mode;
    extern double dist;
    extern double fuel;

    switch (mode)
    {
    case 0:
        printf("Enter distance traveled in kilometers:");
        scanf("%lf", &dist);
        printf("Enter fuel consumed in liters:");
        scanf("%lf", &fuel);
        break;
    case 1:
        printf("Enter distance traveled in niles:");
        scanf("%lf", &dist);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf", &fuel);
        break;
    case -1:
        printf("Done.");
        break;
    default:
        if (mode == 0)
            printf("Invaliad mode specified. Mode 0(metric) used");
        if (mode == 1)
            printf("Invaliad mode specified. Mode 1(US) used");
        break;
    }
}

void show_info(void)
{
    extern int mode;
    extern double dist;
    extern double fuel;

    double average;

    switch (mode)
    {
    case 0:
        average = fuel / dist / 100;
        printf("Fuel consumption is %lf per 100 km.", average);
        break;
    case 1:
        average = dist / fuel;
        printf("Fuel consumption is %lf miles per gallon.", average);
        break;
    default:
        break;
    }
}


