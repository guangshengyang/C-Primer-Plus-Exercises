#include <stdio.h>
#include <string.h>
#define SIZE 40

char Getn(char n);
char *mystrncpy(char *s1, char *s2, int n);

int main(void)
{
    char n;
    char s1[SIZE] = "Welcome to VS Codecode";
    char s2[] = "with extentions";

    n = Getn(n);
    mystrncpy(s1, s2, n);

    puts(s1);

    return 0;
}

char Getn(char n)
{
    printf("How many characters you want to copy to s1?\n");
    n = getchar();
    while (getchar() != '\n')
        continue;
    return n;
}
char *mystrncpy(char *s1, char *s2, int n)
{
    char substitute_n = n;
    char *substitute_s1 = s1;
    if (strlen(s2) < n)
    {
        char len = strlen(s2);
        while (len--)
        {
            *s1++ = *s2++;
        }
        *(s1) = '\0';
        puts("Warning：copying may end early because n is greater than the length of array s1");
        return substitute_s1;
    }
    else
    {
        while (n--)
        {
            *s1++ = *s2++;
        }

        if (n > SIZE)
        {
            printf("Warring: The target array s1 is not long enough to hold %d length strings\n", substitute_n);
        }
    }

    return substitute_s1;
}
