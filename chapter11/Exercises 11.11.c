#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

void GetString(char *s);
void ClearCR(char *s);
void ShowMenu(void);
void GetUserCmd(char c, char *s);

void Print_inOrigOrd(char *s);
void Print_inAsciiOrd(char *s);
void Print_inLenOrd(char *s);
void Print_in1stwordOrd(char *s);

int main(void)
{
    char s[MAXSIZE];
    char ch;
    GetString(s);
    puts(s);

    ShowMenu();
    GetUserCmd(ch, s);

    return 0;
}

void GetString(char *s)
{
    char c;
    int i = 0;
    c = getchar();
    while ((c = getchar()) != EOF)
        s[i++] = c;

    s[i] = '\0';
    ClearCR(s);
}

void ClearCR(char *s)
{
    int i = 0;
    while (s[i] != '\n')
        s++;

    s[i] = '\0';
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

void GetUserCmd(char ch, char *s)
{
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
void Print_inOrigOrd(char *s)
{
    puts(s);
}

void Print_inAsciiOrd(char *s)
{
    
}
void Print_inLenOrd(char *s);
void Print_in1stwordOrd(char *s);
