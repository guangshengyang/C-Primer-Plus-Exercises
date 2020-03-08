#include <stdio.h>
#include <stdlib.h>
#define LIM 10
#define SIZE 50

char *s_gets(char *s[],int n);
void ShowMenu(void);
void GetUserCmd(char c, char *s);

void Print_inOrigOrd(char *s);
void Print_inAsciiOrd(char *s);
void Print_inLenOrd(char *s);
void Print_in1stwordOrd(char *s);

int main(void)
{
    char s[LIM][SIZE];
    char ch;

    printf("Input up to %d lines, and I will sort them.\n", LIM);
    printf("To stop press the EOF key at");

    s_gets(s[], SIZE);
   // puts(s);

    ShowMenu();
    GetUserCmd(ch, s);

    return 0;
}

char *s_gets(char *s[], int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(s, n, stdin);
    if (ret_val)
    {
        while (*s != '\n' && *s != '\0')
            s++;
        if (*s == '\n')
            *s = '\0';
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
void Print_inOrigOrd(char *s)
{
    puts(s);
}

void Print_inAsciiOrd(char *s)
{
}
void Print_inLenOrd(char *s);
void Print_in1stwordOrd(char *s);
