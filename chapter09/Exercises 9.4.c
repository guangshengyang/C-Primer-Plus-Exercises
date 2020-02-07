#include <stdio.h>

double Harmonic_mean_cal(double num_1, double num_2);

int main(void)
{
    double num_1, num_2;
    printf("Enter two numbers to calculate their Harmonic mean(Separate two numbers with a space):");
    scanf("%lf %lf", &num_1, &num_2);

    printf("The Harmonic mean of %g and %g: %g", num_1, num_2, Harmonic_mean_cal(num_1, num_2));

    return 0;
}

double Harmonic_mean_cal(double num_1, double num_2)
{
    return 1 / ((1 / num_1 + 1 / num_2) / 2);
}

//Harmonic average calculation method:
//first obtain the inverse of two numbers,
//then calculate the average of the two inverses,
//and finally take the inverse of the calculation result
