
#include <stdio.h>
#include <stdbool.h>
#define SIZE 50

int main(void)
{
    int i = 0;
    char c;
    char str[SIZE];
    int store_start_end_ptr[SIZE];

    while ((c = getchar()) != EOF) //store the characters as string-array type
        str[i++] = c;

    if (str[--i] == '\n') // i++ make pointer point to next address
        str[i] = '\0';    // , using --i to make it move back first, then do if Statement

    return 0;
}
void SwapCmdOrder(char *s, int *store_start_end_ptr)
{
    bool isfirst = true;
    while ((*s) != '\0')
    {
        if (!isspace(*s) && !inword && isfirst) //c isn't blankspace and c isn't in word, so it's new word
        {
            inword = true;
            isfirst = false;
            store_start_end_ptr++ = s;
        }
        if (isspace(*s) && inword)
        {
            inword = false;
            isfirst = true;
        }
    }
