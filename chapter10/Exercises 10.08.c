#include <stdio.h>

void copyarray(double *ch_another, double *ch_start, int number); //According to the requirements of the title,
                                                                  //the formal parameters are
                                                                  //the address of the array element and the number of elements
void printout_array(double *ch, double *ch_another);

int main(void)
{
    double ch[7] = {1, 2, 3, 4, 5, 6, 7};
    double ch_another[3];

    copyarray(ch_another, ch + 2, 3);
    printout_array(ch, ch_another);

    return 0;
}

void copyarray(double *ch_another, double *ch_start, int number)
{
    do
        *ch_another++ = *ch_start++;
    while (number-- > 0);
}

void printout_array(double *ch, double *ch_another)
{
    printf("Source Array:\n");
    for (int i = 0; i < 7; i++)
        printf("%g\t", *(ch + i)); //equal to print("%g",ch[i]);

    printf("\nTarget Array:\n");
    for (int i = 0; i < 3; i++)
        printf("%g\t", *(ch_another + i)); //equal to print("%g",ch_another[i]);
}
