#include <stdio.h>

double larger_of(double num_1, double num_2);

int main(void)
{
    double num_1, num_2;
    printf("Enter two numbers(Separate two nums with a space):");
    scanf("%lf %lf", &num_1, &num_2);

    printf("num_1:%g\n"
           "num_2: %g\n",
           larger_of(num_1, num_2), larger_of(num_1, num_2));
    return 0;
}

double larger_of(double num_1, double num_2)
{
    int larger;
    larger = (num_1 > num_2) ? (num_2 = num_1) : (num_1 = num_2); //find the larger one
    return larger;
}
