// The code have some problems, need to update
//Do not fully use the binary search algorithm
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int initial_guess = 50;
    int guess = initial_guess;
    int max = 100;
    int min = guess;
    char ch;

    printf("Pick up a integer from 1 to 100. I will try to guess it.\n"
           "Respond with a y if my guess is right and with. An n if it is wrong\n");
    do
    {
        printf("Uh...,is %d right?\n", guess);

        ch = getchar();

        while (getchar() != '\n')
            continue;

        while (ch == 'y')
        {
            printf("Yep, I guess it out!\n");
            return 0;
        }

        while (ch == 'n')
        {
            printf("Emm, is it greater than %d ? Please tell with with y or n\n",
                   guess);

            ch = getchar();
            while (getchar() != '\n')
                continue;

            if (ch == 'y')
            {
                min = guess;                       //only min is changed
                guess = guess + ((max - min) / 2); //update guess
            }

            else
            {
                max = guess; //only max is changed
                min = 0;
                guess = max - (((max - min)) / 2); //update guess
            }
        }
    } while (1);

    return 0;
}
