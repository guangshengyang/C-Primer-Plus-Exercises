#include <stdio.h>

double imin(double, double);

int main(void)
{
    double num_1, num_2;

    printf("Enter two numbers of type double:");
    scanf("%lf %lf", &num_1, &num_2);
    printf("The smaller value: %lf", imin(num_1, num_2));

    return 0;
}

double imin(double num_1, double num_2)
{
    return num_1 > num_2 ? num_2 : num_1; //USing if else statemen can achieve the same function
}
