#include <stdio.h>
#include <string.h>
#define SIZE 30

void RemoveSpace_inString(char *s);
int main(void)
{
    char s[SIZE];

    while (fgets(s, SIZE, stdin) != NULL && s[0] != '\n')
    {
        fputs(s, stdout);
    }

    return 0;
}

void RemoveSpace_inString(char *s)
{
    while (s < s_end)
    {
        if (*s == ' ')
        {
            
        }
    }
}

