#include <stdio.h>
#include <ctype.h>

int is_alphapet(char ch);

int main(void)
{
    char ch;
    while ((ch = getchar()) != EOF) //Using shell to test the program
    {
        is_alphapet(ch);

        if (is_alphapet(ch) == -1)
            printf("%c > return  : -1\n", ch);
        else if (isupper(ch))
            printf("%c > Location: %d\n", ch, ch - 'A' + 1);
        else
            printf("%c > Location: %d\n", ch, ch - 'a' + 1);
    }
    return 0;
}

int is_alphapet(char ch)
{
    int location;
    if (isupper(ch))
    {
        location = ch - 'A' + 1;
        return location;
    }
    else if (islower(ch))
    {
        location = ch - 'a' + 1;
        return location;
    }
    else
        return -1;
}
