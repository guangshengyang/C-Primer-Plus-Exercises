#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 50

void Report(char *s, int *storeresultary);

int main(void)
{
    int i = 0;
    char c;
    char str[SIZE];
    int storeresultary[6];

    while ((c = getchar()) != EOF)
        str[i++] = c;

    if (str[--i] == '\n') // i++ make pointer point to next address
        str[i] = '\0';    // , using --i to make it move back first, then do if Statement

    Report(str, storeresultary);

    return 0;
}

void Report(char *s, int *storeresultary)
{
    bool inword = false;
    int word_count = 0;
    int ch_upper = 0;
    int ch_lower = 0;

    // char c;

    while ((*s) != '\0')
    {
        if (!isspace(*s) && !inword) //c isn't blankspace and c isn't in word, so it's new word
        {
            inword = true;
            word_count++;
        }
        if (isspace(*s) && inword)
            inword = false;

        if (isupper(*s))
            ch_upper++;
        if (islower(*s))
            ch_lower++;
        if (ispunct(*s))
            ch_upper++;
        if (isupper(*s))
            ch_upper++;

        s++;
    }
}
