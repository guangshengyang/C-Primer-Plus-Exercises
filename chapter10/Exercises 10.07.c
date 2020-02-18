#include <stdio.h>
#define LENGTH 3
#define SONLENGTH 4

void Copy_two_dimensional_array(double *ch_target, double *ch_start);
void printout_array(double (*ch_target)[SONLENGTH]);

int main(void)
{
    double ch[LENGTH][SONLENGTH] = {{1.1, 2.2, 3.3, 4.4}, {5.5, 6.6, 7.7, 8.8}, {9.9, 10.0, 11.1, 12.2}};
    double ch_target[LENGTH][SONLENGTH];

    for (int i = 0; i < LENGTH; i++)
        Copy_two_dimensional_array(ch_target[i], ch[i]);

    printout_array(ch_target);

    return 0;
}

void Copy_two_dimensional_array(double *ch_target, double *ch_start)
{
    for (int i = 0; i < SONLENGTH; i++) //Processing two-dimensional arrays in the same way as one-dimensional arrays
        *ch_target++ = *ch_start++;     //The disadvantage is that this method cannot record the row and column information,
                                        //and the row and column are not important.
}

void printout_array(double (*ch_target)[SONLENGTH])
{
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < SONLENGTH; j++)
            printf("%g\t", ch_target[i][j]);

        printf("\n");
    }
}
