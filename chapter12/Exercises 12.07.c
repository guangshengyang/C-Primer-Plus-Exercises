#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int sets;
    int sides, dics;

    while (((sets = getchar()) != 'q'))
    {
        printf("Enter the number of sets; enter q to stop:");
        printf("How many sides and how many dice?");
        scanf("%d %d", &sides, &dics);
        printf("Here are %d sets of %d %d-sided throws.", sets, sides, dics);

        srand((unsigned int)time(0));
        for (int i = 0; i < sets; i++)
        {
            int rand_ch;
            rand_ch = rand() % (sides * dics - dics) + dics; //generate rand nums range from dics*1 to dics*sides
            printf("%c  ", rand_ch);
        }
    }
    return 0;
}