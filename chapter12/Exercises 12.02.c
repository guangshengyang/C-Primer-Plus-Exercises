
/* pe12-2b.c
---------------------------------------------------------------------- */

#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
    extern int mode;
    extern int last_mode;

    printf("Enter 0 for metric mode, 1 for US mode:");
    scanf("%d", &mode);

    while (mode >= 0)
    {
        set_mode(); // If using set_mode(mode) rather set_mode()
                    // This usage will redeclaration a block scope variable in set_mode() function
                    // A new variable with the same name mode will be declared in the function definition section
                    // with the same name with file scope(global scope) mode.
                    // So when the function change value of mode, actually be changed variable is block scope mode, not file scope mode
                    // Cause file scope mode is hidden by block scope mode(It's determined by the C standard)
                    // When leave the set_mode function the block scope mode will disappear and the file scope mode value won't be hidden
                    // So if you change the value in set_mode(mode) function, in fact it doesn't work
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode"
               "(-1 to quit):");
        scanf("%d", &mode);
    }
    printf("Done.\n");

    return 0;
}

/* pe12-2a.h
---------------------------------------------------------------------- */

void set_mode(void);
void get_info(void);
void show_info(void);



/* pe12-2a.c
---------------------------------------------------------------------- */

#include <stdio.h>

int mode;
double dist, fuel;
int last_mode;

void set_mode(void)
{
    extern int last_mode;

    if (mode > 1)
    {
        if (last_mode == 0)
        {
            printf("Invaliad mode specified. Mode 0(metric) used\n");
            mode = 0;
        }
        if (last_mode == 1)
        {
            printf("Invaliad mode specified. Mode 1(US) used\n");
            mode = 1;
        }
    }
    last_mode = mode;
}

void get_info(void)
{
    extern int mode;
    extern double dist;
    extern double fuel;
    extern int last_mode;

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
        average = (fuel / dist) * 100;
        printf("Fuel consumption is %lf per 100 km.\n", average);
        break;
    case 1:
        average = dist / fuel;
        printf("Fuel consumption is %lf miles per gallon.\n", average);
        break;
    default:
        break;
    }
}
