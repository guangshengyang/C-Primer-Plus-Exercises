#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 50

void RemoveSpace_inString(char *s);
int main(void)
{
    char s[] = "I'm YangguangSheng from Hainan University.";
    char *s_begin = s;
    // while (fgets(s, SIZE, stdin) != NULL && s[0] != '\n')
    //    fputs(s, stdout);

    RemoveSpace_inString(s);
    puts(s_begin);

    return 0;
}

void RemoveSpace_inString(char *s)
{
    char *s_old = s;
    const char *d = s;
    do
    {
        while (isspace(*d))
        {
            ++d;
        }

    } while (*s++ = *d++);
}
/*https://stackoverflow.com/questions/1726302/removing-spaces-from-a-string-in-c*
https://codescracker.com/c/program/c-program-remove-spaces-from-string.htm/
