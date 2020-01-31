#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void)
{
    printf("Enter the test string:");
    printf("The first non-whitespace character encountered is %c\n", get_first());

    return 0;
}

char get_first(void)
{
    int ch;

    //Read a character first, when it is a blank character,
    //continue reading the next character to overwrite the previous blank character
    //until the first non-blank character is read, and then exit the while loop
    do
    {
        ch = getchar();
    } while (isspace(ch));

    return ch;
}
