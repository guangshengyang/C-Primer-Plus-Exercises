#include <stdio.h>
#include <string.h>
#define SIZE 30
#define N 10

char *mystrncpy(char *s1, char *s2, int n);

int main(void)
{
    char s1[SIZE] = "Welcome to VS Code";
    char s2[] = " with many extentions";
    int n;

    printf("How many characters you want to copy to s1?\n");
    n = getchar();
    while (getchar() != '\n')
        continue;
        
    printf("s1 pointer:%p\n", s1);
    char ret_ptr = mystrncpy(s1, s2, n);

    printf("Return pointer:%p\n", ret_ptr);
    printf("%d\n", s1 - ret_ptr);

    return 0;
}

char *mystrncpy(char *s1, char *s2, int n)
{
    if (*s1++ = '\0')
    {
        for (int i = 0; i < SIZE - strlen(s1); i++)
        {
            *s1++ = *s2;
        }
        return s1;
    }
}
