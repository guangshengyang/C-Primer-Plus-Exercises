#include <stdio.h>

void DataInput(double (*dataarray)[5], int rows);
void GroupAverage(double (*dataarray)[5], int rows, double *grouptotal);
double AllAverage(double (*dataarray)[5], int rows);
double DataMAx(double (*dataarray)[5], int rows);
void PrintOut(double (*dataarray)[5], double *grouptotal, double allaverage, double max);

int main(void)
{
    double dataarray[3][5];
    double grouptotal[3]; //Don't declare this array inside “GroupAverage()” function, declare in the main() function
                          //and then use malloc to dynamically allocate memory, this is a bad habit

    DataInput(dataarray, 3);
    GroupAverage(dataarray, 3, grouptotal);
    PrintOut(dataarray, grouptotal, AllAverage(dataarray, 3), DataMAx(dataarray, 3));

    return 0;
}

void DataInput(double (*dataarray)[5], int rows)
{
    printf("Enter three sets of numbers, each of which contains 5 numbers of type double(Carriage return to a new line):\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
            scanf("%lf", &(*(*(dataarray + i) + j)));
    }
}

void GroupAverage(double (*dataarray)[5], int rows, double *grouptotal)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
            grouptotal[i] += *(*(dataarray + i) + j);
    }
}

double AllAverage(double (*dataarray)[5], int rows)
{
    double alltotal;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
            alltotal += *(*(dataarray + i) + j);
    }

    return alltotal / (3 * 5);
}

double DataMAx(double (*dataarray)[5], int rows)
{
    double max = dataarray[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (*(*(dataarray + i) + j) > max)
                max = *(*(dataarray + i) + j);
        }
    }

    return max;
}

void PrintOut(double (*dataarray)[5], double *grouptotal, double allaverage, double max)
{ //print array
    printf("The Array is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%g\t", (*(*(dataarray + i) + j)));
        printf("\n");
    }

    //print group average
    printf("The values of each line is:\n");
    for (int i = 0; i < 3; i++)
        printf("%g\t", *(grouptotal + i));

    //print max value in the array
    printf("\nThe max value is: %g", max);
}
