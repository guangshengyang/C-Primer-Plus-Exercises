#include <stdio.h>

int main(void)
{
    int initial_guess = 50;
    int guess = initial_guess;
    int max = 100; //Upper bounds of the binary search algorithm
    int min = 0;   //lower bounds of the binary search algorithm
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
            printf("Emm, is it greater than %d ? Tell with with y or n\n", guess);

            ch = getchar();
            while (getchar() != '\n')
                continue;

            //*When reply with yes, means answer is upper than your guess, only need to change the bigger number "max",
            //"min" is initialized before
            if (ch == 'y')
            {
                min = guess;                       //only min is changed
                guess = guess + ((max - min) / 2); //update guess
            }

            else
            {
                max = guess;                       //only max is changed
                guess = max - (((max - min)) / 2); //update guess
            }
        }
    } while (1);

    return 0;
}
