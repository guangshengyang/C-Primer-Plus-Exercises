#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 50

void RemoveSpace_inString(char *s);
int main(void)
{
    char s[];
    char *s_begin = s;

    fgets(s, SIZE, stdin);

    RemoveSpace_inString(s);
    puts(s_begin);

    return 0;
}

void RemoveSpace_inString(char *s)
{
    const char *d = s;
    do
    {
        while (isspace(*d))
        {
            ++d;
        }

    } while (*s++ = *d++);
}
