#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define N 20

int GetWord(char ch, char *array);

int main(void)
{
    char ch;
    int count;
    char array[N];

    printf("Enter your favorite movie's name:");
    count = GetWord(ch, array);
    for (int i = 0; i < count; i++)
        printf("%c", *(array + i));

    return 0;
}

int GetWord(char ch, char *array)
{
    bool inword = false; //inword to judge if the word is over
    int count = 0;

    while ((ch = getchar()) != EOF)
    {

        if (isspace(ch))
        {
            if (inword == true) //If the word is over, clear the rest in buffer
            {
                while (getchar() != '\n')
                    continue;
            }
            continue; //Skip leading blanks
        }
        else
        {
            inword = true; //Means the word is over
            *array++ = ch;
            count++; //Record how many characters were read
        }
    }

    return count;
}

