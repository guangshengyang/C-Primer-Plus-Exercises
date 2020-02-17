#include <stdio.h>
#define LENGTH 10

int find_max(int *ch);

int main(void)
{
    int ch[LENGTH] = {1, 2, 5, 6, 4, 5, 7, 9, 10, 0};

    printf("The arrary is below:\n");
    for (int i = 0; i < LENGTH; i++)
        printf("%d ", ch[i]);

    printf("\nThe maximum number:%d", find_max(ch));

    return 0;
}

int find_max(int *ch)
{
    int temp;
    int max = -1;
    for (int i = 0; i < LENGTH; i++)
    {
        if (*ch > max)
            max = *ch;
        ch++;
    }

    return max;
}
