#include <stdio.h>
#define LENGTH 10

double difference_num(double ch[]);

int main(void)
{
    double ch[LENGTH] = {1.1, 3.2, 5.5, 31.6, 1.4, 8.5, 0.7, 3.9, 1.0, 0.0};

    printf("The arrary is below:\n");
    for (int i = 0; i < LENGTH; i++)
        printf("%g\t", ch[i]);

    printf("\nThe difference between largest and smallest:%g", difference_num(ch));

    return 0;
}

double difference_num(double ch[])
{
    double max = ch[0];
    double min = ch[0];

    for (int i = 0; i < LENGTH; i++)
    {
        if (ch[i] > max)
            max = ch[i];
        if (ch[i] < min)
            min = ch[i];
    }

    return max - min;
}
