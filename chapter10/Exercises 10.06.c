// Using Bubble sort
#include <stdio.h>
#define LENGTH 10

double *arrary_sort(double *ch);

int main(void)
{
    double ch[LENGTH] = {5.1, 1.2, 6.2, 1.3, 8.2, 8.2, 3.6, 5.5, 10.0, 4.12};

    printf("Before Sort:\n");
    for (int i = 0; i < LENGTH; i++)
        printf("%g\t", ch[i]);
    printf("\n");

    double *ch_ptr = arrary_sort(ch);

    printf("After Sort:\n");
    for (int i = 0; i < LENGTH; i++)
        printf("%g\t", *ch_ptr++);

    return 0;
}

double *arrary_sort(double *ch_ptr)
{
    double temp;

    double *ch_ptr_old = ch_ptr;

    for (int i = 0; i < LENGTH - 1; i++)
    {

        for (int j = 0; j < LENGTH - 1 - i; j++)
        {
            if (*ch_ptr < *(ch_ptr + 1))
            {
                temp = *ch_ptr;
                *ch_ptr = *(ch_ptr + 1);
                *(ch_ptr + 1) = temp;
            }
            ch_ptr++;
        }
        ch_ptr = ch_ptr_old; //After the loop, ch_ptr++ makes ch_ptr point to the next position,
                             //need to restore the pointer to the original position
    }

    return ch_ptr;
}

    printf("Before Sort:\n");
    for (int i = 0; i < LENGTH; i++)
        printf("%g\t", ch[i]);
    printf("\n");

    double *ch_ptr = find_max(ch);

    printf("After Sort:\n");
    for (int i = 0; i < LENGTH; i++)
        printf("%g\t", *ch_ptr++);

    return 0;
}

double *find_max(double *ch_ptr)
{
    double temp;

    double *ch_ptr_old = ch_ptr;

    for (int i = 0; i < LENGTH - 1; i++)
    {

        for (int j = 0; j < LENGTH - 1 - i; j++)
        {
            if (*ch_ptr < *(ch_ptr + 1))
            {
                temp = *ch_ptr;
                *ch_ptr = *(ch_ptr + 1);
                *(ch_ptr + 1) = temp;
            }
            ch_ptr++;
        }
        ch_ptr = ch_ptr_old; //After the loop, ch_ptr++ makes ch_ptr point to the next position,
                             //need to restore the pointer to the original position
    }

    return ch_ptr;
}
