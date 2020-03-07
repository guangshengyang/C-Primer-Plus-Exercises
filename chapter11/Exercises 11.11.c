#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 20
void CheckStreamRead(void);
int main(void)
{

    CheckStreamRead();

    return 0;
}

void CheckStreamRead(void)
{
    char c;
    int i = 0;
    char buffer[SIZE];
    while ((c = getchar()) != '\n')
    {
        buffer[i++] = c;
    }
    //buffer[i] = '\0';
   // puts(buffer);
    for (int j = 0; j < 10; j++)
    {
        printf("%c", buffer[j]);
    }
}
