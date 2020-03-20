#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int *array, int array_length);

int main(void)
{
    const int looptimes = 50;
    int StoreRandNums[looptimes];

    srand((unsigned int)time(0)); //auto reset seed

    for (int i = 0; i < looptimes; i++)
        StoreRandNums[i] = rand() % 10 + 1;

    int contained_nums = sizeof(StoreRandNums) / sizeof(int); //Get actually nums in the array
    BubbleSort(StoreRandNums, contained_nums);

    for (int i = 0; i < contained_nums; i++)
        printf("%d  ", StoreRandNums[i]);

    return 0;
}

void BubbleSort(int *array, int array_length)
{
    int temp;
    for (int i = 0; i < array_length - 1; i++)
    {
        for (int j = i + 1; j < array_length; j++)
        {
            if (array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
