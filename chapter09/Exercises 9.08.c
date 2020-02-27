#include <stdio.h>
#include <math.h>

double power(double x, double exp);

int main(void)
{
    double x, x_pow;
    int exp;
    printf("Enter the number and interger power"
           "to which\nthe number will be raised.Enter q "
           "to quit: ");
    while (scanf("%lf %d", &x, &exp) == 2)
    {
        x_pow = power(x, exp);
        if (x == 0 && exp == 0)
        {
            printf("Powers of 0 to 0 are undefined, so the value is treated as 1\n");
        }
        else
            printf("%g^%d = %g", x, exp, x_pow);
        return 0;
    }
    return -1;
}

double power(double x, double exp)
{
    double pow = 1;
    if (exp < 0)
    {
        exp = abs(exp); // change negative number to absolute value
        for (int i = 0; i < exp; i++)
            pow *= x;
        return 1 / pow;
    }
    else if (exp > 0)
    {
        for (int i = 0; i < exp; i++)
            pow *= x;
        return pow;
    }
    else if (exp == 0)
        return 1; //Powers of 0 to 0 are undefined, so the value is treated as 1
}
