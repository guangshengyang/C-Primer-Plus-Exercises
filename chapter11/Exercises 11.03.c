#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define N 20

void GetWord(char *array);

int main(void)
{
    char array[N];

    printf("Enter your favorite movie's name:");
    GetWord(array);
    puts(array);

    return 0;
}

void GetWord(char *array)
{
    char ch;
    bool inword = false; //inword to judge if the word is over

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
        }
    }
}
