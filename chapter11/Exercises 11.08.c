#include <stdio.h>
#include <string.h>

char string_in(char *s1, char *s2);

int main(void)
{
    char s1[] = "hats";
    char s2[] = "ats";
    printf("%p\n%p\n", s1, s2);
    string_in(s1, s2);
    printf("%p", string_in(s1, s2));
    return 0;
}

char string_in(char *s1, char *s2)
{
    char *ret_s1;
   
    
    while (*s1++ == *s2)
    {
        ret_s1 = s1--;
        printf("6666%p\n", ret_s1);
        
        for (int i = 0; i < strlen(s2); i++)
        {
            if (*s1++ == *s2++)
            {
                continue;
            }
            else
            {
                return NULL;
            }
        }
        return ret_s1;
    }
    return NULL;
}
