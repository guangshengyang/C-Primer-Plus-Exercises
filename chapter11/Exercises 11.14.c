#include <stdio.h>

double calculate(double base, int index);

int main(void)
{
    double base;
    int index;
    scanf("%lf %d", &base, &index);

    printf("%lf", calculate(base, index));

    return 0;
}

double calculate(double base, int index)
{
    double result = 1;
    for (int i = 0; i < index; i++)
        result *= base; //cumprod

    return result;
}
