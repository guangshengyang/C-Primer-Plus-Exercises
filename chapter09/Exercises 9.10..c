#include <stdio.h>

void to_base_n(int, int);

int main(void)
{
    int number, base;
    printf("Enter an integer and the different base number(2-10) want to transfer ( q to quit ): \n");
    while (scanf("%d %d", &number, &base) == 2)
    {
        if (base < 2 || base > 10)
        {
            printf("Enter the right base. Input base again: ");
            scanf("%d", &base);
        }

        to_base_n(number, base);
        putchar('\n');
        printf("Enter an integer and the different base number(2-10) want to transfer ( q to quit ): \n");
    }

    return 0;
}

void to_base_n(int number, int base)
{
    int r;
    r = number % base;
    if (number >= base)
        to_base_n(number / base, base);
        else
        printf("Converted:");
        
    printf("%d", r);

    return;
}
