#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define N 10

char is_within(char c, const char *s);

int main(void)
{
    char ch;
    char *return_val;
    char source_string[] = "Welcome to VS Code!";

    for (int i = 0; i < N; i++) //Use a loop to test the function
    {
        printf("What character you are look up?\n");
        ch = getchar();
        while (getchar() != '\n')
            continue;

        return_val = is_within(ch, source_string);
        printf("Return Value:%d\n", return_val);
    }

    return 0;
}

char is_within(char c, const char *s)
{
    int tempch;
    const char *initial_pointer = s;
    for (int i = 0; i < strlen(s) + 1; i++) // "\0" is part of the string
    {
        tempch = *s++;
        if (tempch == c)
        {
            return (char)abs(s - initial_pointer); //Take the absolute value in case some systems are stored backwards
        }
        continue;
    }
    return false;
}
