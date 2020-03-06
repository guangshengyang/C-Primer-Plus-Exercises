#include <stdio.h>
#include <string.h>
#define MAXSIZE 30

void GetString(char *s1, char *s2);
void ClearCR(char *s);
char *string_in(char *s1, char *s2);

int main(void)
{
    char s1[MAXSIZE];
    char s2[MAXSIZE];

    GetString(s1, s2);
    printf("The beggin of string s1 address:%p\n", s1);
    printf("The returned address：%p", string_in(s1, s2));

    return 0;
}

void GetString(char *s1, char *s2)
{
    puts("The program target is to find if string \"s2\" is in string \"s1\"\n");

    puts("Now enter string s1 next line:");

    fgets(s1, MAXSIZE, stdin); //fgets() store the CR(carriage return) in the array
    ClearCR(s1);               //CR need to replace by '\0',or program will meet bugs

    puts("Now enter s2 next line:");

    fgets(s2, MAXSIZE, stdin);
    ClearCR(s2);
}

void ClearCR(char *s)
{
    int i = 0;
    while (s[i] != '\n')
        s++;

    s[i] = '\0';
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
