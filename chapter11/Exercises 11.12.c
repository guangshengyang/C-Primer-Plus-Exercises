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
    int storeresultary[6] = {0};

    while ((c = getchar()) != EOF)
        str[i++] = c;

    if (str[--i] == '\n') // i++ make pointer point to next address
        str[i] = '\0';    // , using --i to make it move back first, then do if Statement

    Report(str, storeresultary);

    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", storeresultary[i]);
    }

    return 0;
}

void Report(char *s, int *storeresultary)
{
    bool inword = false;
    int ch_count = 0;
    int word_count = 0;
    int upper_count = 0;
    int lower_count = 0;
    int punct_count = 0;
    int digit_count = 0;

    // char c;

    while ((*s) != '\0')
    {
        ch_count++;
        if (!isspace(*s) && !inword) //c isn't blankspace and c isn't in word, so it's new word
        {
            inword = true;
            word_count++;
        }
        if (isspace(*s) && inword)
            inword = false;

        if (isupper(*s))
            upper_count++;
        if (islower(*s))
            lower_count++;
        if (ispunct(*s))
            punct_count++;
        if (isdigit(*s))
            digit_count++;

        s++;
    }
    storeresultary[0] = ch_count;
    storeresultary[1] = word_count;
    storeresultary[2] = upper_count;
    storeresultary[3] = lower_count;
    storeresultary[4] = punct_count;
    storeresultary[5] = digit_count;
}
