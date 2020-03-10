#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 50

void Report(char *s, int *storeresultary);

int main(void)
{
    int i = 0;
    char c;
    char str[SIZE];
    int storeresultary[6];

    while ((c = getchar()) != EOF)
        str[i++] = c;

    if (str[--i] == '\n') // i++ make pointer point to next address
        str[i] = '\0';    // , using --i to make it move back first, then do if Statement

    Report(str,storeresultary);

    return 0;
}

void Report(char *s, int *storeresultary)
{
    bool inword =false;

    

    
}
