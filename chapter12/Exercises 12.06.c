#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TIMES 100

int main(void)
{

    for (int i = 0; i < 10; i++)
    {
        srand((unsigned int)time(0));
        int CountNumsTimes[10] = {0};

        for (int j = 0; j < TIMES; j++)
        {

            int digit = rand() % 10 + 1;

            switch (digit)
            {
            case 1:
                CountNumsTimes[0]++;
                break;
            case 2:
                CountNumsTimes[1]++;
                break;
            case 3:
                CountNumsTimes[2]++;
                break;
            case 4:
                CountNumsTimes[3]++;
                break;
            case 5:
                CountNumsTimes[4]++;
                break;
            case 6:
                CountNumsTimes[5]++;
                break;
            case 7:
                CountNumsTimes[6]++;
                break;
            case 8:
                CountNumsTimes[7]++;
                break;
            case 9:
                CountNumsTimes[8]++;
                break;
            case 10:
                CountNumsTimes[9]++;
                break;
            default:
                break;
            }
        }
        printf("Round %d\n", i + 1);

        for (int i = 0; i < 10; i++)
        {

            printf("Num_%-d: %-2d  ", i + 1, CountNumsTimes[i]);
        }
        printf("\n\n");
    }

    return 0;
}
