#include <stdio.h>

void PrintRawArray(int (*array)[5], int rows); //The number of columns is built into the function body,
                                               //but the number of rows need to pass in by the function parameters
                                               //So it's the same as pass the rows & cols
void DoubleArray(int (*array)[5], int rows);

int main(void)
{
    int array[3][5] = {{1, 2, 3, 4, 5},
                       {6, 7, 8, 9, 10},
                       {11, 12, 13, 14, 15}};

    PrintRawArray(array, 3);
    DoubleArray(array, 3);

    return 0;
}

void PrintRawArray(int (*array)[5], int rows)
{
    printf("RePrint the Array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%d\t", *(*(array + i) + j)); //the same as array[i][j]

        printf("\n");
    }
}

void DoubleArray(int (*array)[5], int rows)
{
    printf("\nAfter Double the Array:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            *(*(array + i) + j) = (*(*(array + i) + j)) * 2;
            printf("%d\t", *(*(array + i) + j)); //the same as array[i][j]
        }

        printf("\n");
    }
}
