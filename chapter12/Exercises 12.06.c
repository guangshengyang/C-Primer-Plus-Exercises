#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TIMES 100

int main(void)
{

    for (int i = 0; i < 10; i++)
    {
        srand((unsigned int)time(0) + rand()); //remember to give different seeds, +i will give different seeds to each loop
                                               // Cause program run fast, value of time which time() got is the same,
                                               //if only use time to reset seed it's not working, it's the same.Try to add another rand()
        int CountNumsTimes[10] = {0};

        for (int j = 0; j < TIMES; j++)
        {
            int digit = rand() % 10 + 1;
            CountNumsTimes[digit - 1]++;
        }
        
        printf("Round %d\n", i + 1);
        for (int k = 0; k < 10; k++)
            printf("Num_%-d: %-2d  ", k + 1, CountNumsTimes[k]);

        printf("\n\n");
    }
    return 0;
}
