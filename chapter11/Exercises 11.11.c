#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LIM 10
#define SIZE 50

char *s_gets(char *s, int n);
void ShowMenu(void);
void GetUserCmd(char c, char *str[]);
void ssort(char *str[], int num);

void Print_inOrigOrd(char *str[], int num);
void Print_inAsciiOrd(char *str[], int num);
void Print_inLenOrd(char *str[], int num);
void Print_in1stwordOrd(char *str[], int num);

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
    Print_inAsciiOrd(sptr, ct);
    //ShowMenu();
    //GetUserCmd(ch, s);

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
/*
void GetUserCmd(char ch, char *s)
{
    int a, b, c, d, q;
    switch (ch)
    {
    case a:
        Print_inOrigOrd(s);
        break;
    case b:
        Print_inAsciiOrd(s);
        break;
    case c:
        Print_inLenOrd(s);
        break;
    case d:
        Print_in1stwordOrd(s);
        break;

    default:
        exit(0);
        break;
    }
}
*/

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
        puts(str_old[i]);
}
void Print_inLenOrd(char *str[], int num)
{
    
}
void Print_in1stwordOrd(char *str[], int num)
{
}
