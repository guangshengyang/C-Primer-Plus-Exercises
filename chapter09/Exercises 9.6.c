#include <stdio.h>

void swap(double *num_1, double *num_2, double *num_3);

int main(void)
{
    double num_1, num_2, num_3;
    printf("Enter three numbers(Separate each nums with a space):");

    while ((scanf("%lf %lf %lf", &num_1, &num_2, &num_3)) == 3) //Input validation
    {

        printf("Before callng the function\n"
               "num_1: %-2g       Address: %p\n"
               "num_2: %-2g       Address: %p\n"
               "num_3: %-2g       Address: %p\n",
               num_1, num_1, num_2, num_2, num_3, num_3);

        swap(&num_1, &num_2, &num_3);//Pointer type variable's parameter is Address,so need  to transfer addresses to the function's parameter

        printf("After calling the function\n"
               "num_1: %-2g       Address: %p\n"
               "num_2: %-2g       Address: %p\n"
               "num_3: %-2g       Address: %p\n",
               num_1, num_1, num_2, num_2, num_3, num_3);
        break;
    }
    return 0;
}

void swap(double *num_1, double *num_2, double *num_3)
{
    double temp;
    if (*num_1 > *num_2)
    {
        temp = *num_1;
        *num_1 = *num_2;
        *num_2 = temp;
    }
    if (*num_1 > *num_3)
    {
        temp = *num_1;
        *num_1 = *num_3;
        *num_3 = temp;
    }
    if (*num_2 > *num_3)
    {
        temp = *num_2;
        *num_2 = *num_3;
        *num_3 = temp;
    }
}
