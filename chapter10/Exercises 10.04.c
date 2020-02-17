#include <stdio.h>
#define LENGTH 10

int find_max(double *ch);

int main(void)
{
    double ch[LENGTH] = {1.1, 3.2, 5.5, 31.6, 1.4, 8.5, 0.7, 3.9, 1.0, 0.0};

    printf("The arrary is below:\n");
    for (int i = 0; i < LENGTH; i++)
        printf("%g\t", ch[i]);

    printf("\nThe maximum number arrary index:%d", find_max(ch));

    return 0;
}

int find_max(double ch[])
{
    int temp;
    int array_index;
    double max = ch[0];
    for (int i = 0; i < LENGTH; i++)
    {
        if (ch[i] > max)
        {
            max = ch[i];
            array_index = i;
        }
    }

    return array_index;
}
