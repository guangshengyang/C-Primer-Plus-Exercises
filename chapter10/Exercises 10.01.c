#include <stdio.h>
#define MONTHS 12
#define YEARS 5

int main(void)
{
     float rain[YEARS][MONTHS] =
        {{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
         {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
         {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
         {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
         {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6}};

    int year, month;
    float subtotal, total;

    
    printf(" YEAR    RAINFALL   (inches)\n");
    for (int year = 0; year < YEARS; year++)
    {
        subtotal = *rain++;
    }
    printf("\nThe yearly average is %.1f inches.\n", subtotal / YEARS);

    printf("MONTH    RAINFALL   (inches)\n");

    for (int month = 0; month < MONTHS; month++)
    {
        for (int year = 0; year < YEARS; year++)
        {
            total = *rain++;
        }
    }

    return 0;
}
