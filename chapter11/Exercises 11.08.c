#include <stdio.h>
#include <string.h>

char *string_in(char *s1, char *s2);

int main(void)
{
    char s1[] = "hats";
    char s2[] = "at";

    printf("The beggin of string s1 address:%p\n", s1);
    printf("The returned address：%p", string_in(s1, s2));

    return 0;
}

char *string_in(char *s1, char *s2)
{
    char s2_len = strlen(s2);
    while (*s1 != *s2)
    {
        s1++;
        continue;
    }

    if (strncmp(s1, s2, s2_len)) //strncmp return value is the difference between the two characters
    {                            //return 0 means they are the same
        return NULL;             //Most of times,only need to care about the return value is 0 or not
    }
    else
    {
        return s1;
    }
}
