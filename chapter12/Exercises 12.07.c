#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int sets;
    int sides, dics;
    printf("Enter the number of sets; enter q to stop:");
    while ((scanf("%d", &sets)) == 1)
    {
        printf("How many sides and how many dice?");
        scanf("%d %d", &sides, &dics);
        printf("Here are %d sets of %d %d-sided throws.\n", sets, sides, dics);

        srand((unsigned int)time(0));
        for (int i = 0; i < sets; i++)
        {
            int rand_num;
            rand_num = rand() % (sides * dics - dics) + dics; //generate random nums range from 'dics*1' to 'dics*sides'
            printf("%d  ", rand_num);
        }
        printf("\n");
        printf("How many sets? Enter q to quit:");
    }
    return 0;
}
