#include <stdio.h>
#define N 5

int PassAdress(char *ch);

int main(void)
{
    char ch[N];

    int count = PassAdress(ch);

    for (int i = 0; i < count; i++)
        putchar(*(ch + i));

    return 0;
}

int PassAdress(char *ch)
{
    int i;
    int chch;

    printf("Enter %d chars the next line\nNote: the extra parts will not be printed:\n", N);
    for (i = 0; i < N; i++)
    {
        chch = getchar();
        if (chch == '\n' || chch == '\t' || chch == ' ') // if (isblank(chch) == 0) dont consider \n as blank.(Cpp Reference)
            break;                                       //the C Primer Plus 6th(Chinese Translation Version) in page 183 is wrong

        *ch++ = chch;
    }

    return i;
}
