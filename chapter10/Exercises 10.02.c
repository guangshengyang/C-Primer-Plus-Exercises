#include <stdio.h>
#define LENGTH 5

void copy_arr(double *target1, double *source, int length);
void copy_ptr(double *target2, double *source, int length);
void copy_ptrs(double *target3, double *source_start, double *source_end);

int main(void)
{
    double source[LENGTH] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[LENGTH];
    double target2[LENGTH];
    double target3[LENGTH];

    copy_arr(target1, source, LENGTH);
    copy_ptr(target2, source, LENGTH);
    copy_ptrs(target3, source, source + LENGTH);

    printf("%10s  %10s  %10s\n", "target1", "target2", "target3"); //Good sample of print three functions togerther
    for (int i = 0; i < LENGTH; i++)                               //Thanks to @sgreenlee in Github
        printf("%10.3lf  %10.3lf  %10.3lf\n", target1[i], target2[i], target3[i]);

    return 0;
}

void copy_arr(double *target1, double *source, int length)
{
    for (int i = 0; i < length; i++)
        target1[i] = source[i];
}

void copy_ptr(double *target2, double *source, int length)
{
    for (int i = 0; i < length; i++)
        *target2++ = *source++; // *source++ is more commonly used, but *(source++) is more clear
}
void copy_ptrs(double *target3, double *source_start, double *source_end)
{
    while (source_start < source_end)
        *target3++ = *source_start++;
}
