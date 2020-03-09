#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LIM 10
#define SIZE 50

char *s_gets(char *s, int n);
void ShowMenu(void);
void GetUserCmd(char c, char *str, num);
int FirstWordLen(char *str);

void Print_inOrigOrd(char *str[], int num);
void Print_inAsciiOrd(char *str[], int num);
void Print_inLenOrd(char *str[], int num);
void Print_in1stwordLen(char *str[], int num);

int main(void)
{
    char s[LIM][SIZE];
    char *sptr[LIM];
    char ch;
    int ct = 0;

    printf("Input up to %d lines, and I will sort them.\n", LIM);
    printf("To stop press the EOF key at a line;s start.\n");

    while (ct < LIM && s_gets(s[ct], SIZE) != NULL && s[ct][0] != '\0')
    {
        sptr[ct] = s[ct];
        ct++;
    }

    // Print_inOrigOrd(sptr, ct);
    // Print_inAsciiOrd(sptr, ct);
    //Print_inLenOrd(sptr, ct);
    // FirstWordLen(sptr);
    // Print_in1stwordLen(sptr, ct);
    //ShowMenu();
    GetUserCmd(ch, sptr, ct);

    return 0;
}

char *s_gets(char *s, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(s, n, stdin);
    if (ret_val)
    {
        while (s[i] != '\n' && s[i] != '\0')
            s++;
        if (s[i] == '\n')
            s[i] = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}

void ShowMenu(void)
{
    puts("Enter a character from below options:\n"
         "a. Print strings in original order.\n"
         "b. Print strings in ASCII collating sequence.\n"
         "c. Print strings ordered by length.\n"
         "d. Print strings ordered by length of the first word.\n"
         "q. Quit.\n\n"
         "Enter a character: ");
}

void GetUserCmd(char ch, char *sptr, int num)
{
    puts("Enter a character from " a, b, c, d, q " here to choose an option:");
    while (getchar(!= '\n'))
        continue;

    switch (ch)
    {
    case 'a':
        Print_inOrigOrd(sptr, num);
        break;
    case 'b':
        Print_inAsciiOrd(sptr, num);
        break;
    case 'c':
        Print_inLenOrd(sptr, num);
        break;
    case 'd':
        FirstWordLen(sptr);
        Print_in1stwordLen(sptr, num);
        break;

    default:
        puts("Bye!");
        exit(0);
        break;
    }
}

void Print_inOrigOrd(char *str[], int num)
{
    for (int i = 0; i < num; i++)
        puts(str[i]);
}

void Print_inAsciiOrd(char *str[], int num)
{
    char *temp;

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    for (int i = 0; i < num; i++)
        puts(str[i]);
}
void Print_inLenOrd(char *str[], int num)
{
    char *temp;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (strlen(str[i]) > strlen(str[j]))
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    for (int i = 0; i < num; i++)
        puts(str[i]);
}
int FirstWordLen(char *str)
{
    int length = 0;
    while (isspace(*str)) // skip leading whitespace
        str++;
    while (!isspace(*str)) // get first word length
    {
        length++;
        str++;
    }
    return length;
}

void Print_in1stwordLen(char *str[], int num)
{
    char *temp;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (FirstWordLen(str[i]) > FirstWordLen(str[j]))
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    for (int i = 0; i < num; i++)
        puts(str[i]);
}
