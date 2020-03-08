#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
#define N 10

int GetString(char *s, int size);
void ClearCR(char *s);
void *ReversePrint(char *s);

int main(void)
{
    char s[SIZE];
    int limitsize;
    printf("Limited Size for user:");
    scanf("%d", &limitsize);
    fflush(stdin);
    for (int i = 0; i < N; i++)
    {
        GetString(s, limitsize);
        char *s_initial = s; //Do not declare s_initial in other functions,
                             //because the pointer variable declared will be revoked
                             // from memory when the function ends
        ReversePrint(s);
        puts(s_initial);
    }
    return 0;
}

int GetString(char *s, int size)
{
    char c;
    int i = 0, count = 0;

    while ((c = getchar()) != '\n')
    {
        s[i++] = c;
        count++;
    }
    s[i++] = '\n';
    count++;
    s[i] = '\0';

    if (count > size)
    {
        puts("note : The stream in buffer is not completed read by fgets() function.");
        exit(1);
    }
    else
        ClearCR(s);
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

/*At first, I use fgets() to build GetString() function and remove CR(\n)
But,then I found a bug "When user enter characters more than fgets() limited.
So the \n won't be stored in array,but ClearCR based on \n to know where the string end,so program stop.
Now,I rewrote the GetString() to fix the bug"

---------------------------------------
Previous function implementation code
----------------------------
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

---------------------------------------
Improved function implementation code
---------------------------

int GetString(char *s, int size)
{
    char c;
    int i = 0, count = 0;

    while ((c = getchar()) != '\n')
    {
        s[i++] = c;
        count++;
    }
    s[i++] = '\n';
    count++;
    s[i] = '\0';

    if (count > size)
    {
        puts("note : The stream in buffer is not completed read by fgets() function.");
        exit(1);
    }
    else
        ClearCR(s);
}

void ClearCR(char *s)
{
    int i = 0;
    while (s[i] != '\n')
        s++;

    s[i] = '\0';
}

*/
