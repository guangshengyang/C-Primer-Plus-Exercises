#include <stdio.h>
#include <string.h>
#define SIZE 50
#define N 10

void GetString(char *s);
void ClearCR(char *s);
void *ReversePrint(char *s);

int main(void)
{
    char s[SIZE];

    for (int i = 0; i < N; i++)
    {
        GetString(s);
        char *s_initial = s; //Do not declare s_initial in other functions,
                             //because the pointer variable declared will be revoked
                             // from memory when the function ends
        ReversePrint(s);
        puts(s_initial);
    }
    return 0;
}

void GetString(char *s)
{
    puts("Now enter string s the next line:");
    fgets(s, SIZE, stdin); //fgets() store the CR(carriage return) in the array
    ClearCR(s);            //CR need to replace by '\0',or program will meet bugs
}

void ClearCR(char *s)
{
    int i = 0;
    while (s[i] != '\n')
        s++;

    s[i] = '\0';
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
