#include <stdio.h>

void copyarray(double *ch_another, double *ch_start, double *ch_end);
void printout_array(double *ch, double *ch_another);

int main(void)
{
    double ch[7] = {1, 2, 3, 4, 5, 6, 7};
    double ch_another[3];

    copyarray(ch_another, ch + 2, ch + 5);
    printout_array(ch, ch_another);

    return 0;
}

void copyarray(double *ch_another, double *ch_start, double *ch_end)
{
    while (ch_start < ch_end)
        *ch_another++ = *ch_start++;
}

void printout_array(double *ch, double *ch_another)
{
    printf("Source Array:\n");
    for (int i = 0; i < 7; i++)
        printf("%g\t", *(ch + i)); //equal to print("%g",ch[i]);

    printf("\nTarget Array:\n");
    for (int i = 0; i < 3; i++)
        printf("%g\t", *(ch_another + i));//equal to print("%g",ch_another[i]);
}
