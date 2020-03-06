#include <stdio.h>
#include <string.h>

void *ReversePrint(char *s);

int main(void)
{
    char s[] = "welcome to VS Code";
    char *s_initial = s;

    ReversePrint(s);
    puts(s_initial);
    return 0;
}
void *ReversePrint(char *s)
{
    int s_length = strlen(s);
    char temp;
    char *s_end = s + s_length - 1;

    for (int i = 0; i < s_length / 2; i++, s++, s_end--) //The method of dividing the judgment condition by two
    {                                                    // is suitable for both odd and even numbers.
        temp = *s_end;
        *s_end = *s;
        *s = temp;
    }
}
