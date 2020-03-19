
/* pe12-3b.c
---------------------------------------------------------------------- */

#include <stdio.h>
#include "pe12-2a.h"


int main(void) 
{
     int mode =0;
     int last_mode = 0;
     double dist, fuel;
     

    printf("Enter 0 for metric mode, 1 for US mode:");
    scanf("%d", &mode);
    set_mode(&mode, &last_mode);
    while (mode >= 0)
    {
        get_info(mode,&dist,&fuel);
        show_info(mode,dist,fuel);
        set_mode(&mode, &last_mode);
    }
    printf("Done.\n");

    return 0;
}



/* pe12-3a.h
---------------------------------------------------------------------- */

void set_mode(int* mode, int* last_mode);
void get_info(int mode, double* dist, double* fuel);
void show_info(int mode, double dist, double fuel);


/* pe12-3a.c
---------------------------------------------------------------------- */

#include <stdio.h>

void set_mode(int *mode, int *last_mode)
{  
    

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

void get_info(int mode,double *dist,double *fuel)
{

    switch (mode)
    {
    case 0:
        printf("Enter distance traveled in kilometers:");
        scanf("%lf", dist);
        printf("Enter fuel consumed in liters:");
        scanf("%lf", fuel);
        break;
    case 1:
        printf("Enter distance traveled in niles:");
        scanf("%lf", dist);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf", fuel);
        break;
    case -1:
        printf("Done.");
        break;
    default:
		break;
    }
}

void show_info(int mode, double dist, double fuel)
{

    double average;

    switch (mode)
    {
    case 0:
        average = (fuel / dist)*100 ;
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
