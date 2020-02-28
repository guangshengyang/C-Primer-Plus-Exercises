#include <stdio.h>
#define N 10 

void PassAdress(char *ch);

int main(void)
{
    char ch[N];

    PassAdress(ch);

    for (int i = 0; i < N; i++)
        putchar(*(ch + i));

    return 0;
}

void PassAdress(char *ch)
{
    int chch;
    printf("Enter any chars is OK:\n");
    while ((chch = getchar()) != EOF)
        *ch++ = chch;
}
