#include <stdio.h>

void DataInput(int rows, int cols, double dataarray[rows][cols]);
void GroupAverage(int rows, int cols, double dataarray[rows][cols], double grouptotal[rows]);
double AllAverage(int rows, int cols, double dataarray[rows][cols]);
double DataMAx(int rows, int cols, double dataarray[rows][cols]);
void PrintOut(int rows, int cols, double dataarray[rows][cols], double grouptotal[rows], double allaverage, double max);

int main(void)
{
    int rows = 3;
    int cols = 5;

    double dataarray[rows][cols]; //variable-Length Array  VLA
    double grouptotal[rows];      //Don't declare this array inside “GroupAverage()” function
                                  //and then use malloc to dynamically allocate memory, this is a bad habit
                                  //declare in the main() function is OK

    DataInput(rows, cols, dataarray);
    GroupAverage(rows, cols, dataarray, grouptotal);
    PrintOut(rows, cols, dataarray, grouptotal, AllAverage(rows, cols, dataarray), DataMAx(rows, cols, dataarray));

    return 0;
}

void DataInput(int rows, int cols, double dataarray[rows][cols])
{
    printf("Enter three sets of numbers, each of which contains cols numbers of type double(Carriage return to a new line):\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            scanf("%lf", &dataarray[i][j]);
    }
}

void GroupAverage(int rows, int cols, double dataarray[rows][cols], double grouptotal[rows])
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            grouptotal[i] += dataarray[i][j];
    }
}

double AllAverage(int rows, int cols, double dataarray[rows][cols])
{
    double alltotal;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            alltotal +=dataarray[i][j];
    }

    return alltotal / (rows * cols);
}

double DataMAx(int rows, int cols, double dataarray[rows][cols])
{
    double max = dataarray[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (*(*(dataarray + i) + j) > max)
                max = dataarray[i][j];
        }
    }

    return max;
}

void PrintOut(int rows, int cols, double dataarray[rows][cols], double grouptotal[rows], double allaverage, double max)
{ //print array
    printf("The Array is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%g\t", dataarray[i][j]);
        printf("\n");
    }

    //print group average
    printf("The values of each line is:\n");
    for (int i = 0; i < rows; i++)
        printf("%g\t", grouptotal[i]);

    //print max value in the array
    printf("\nThe max value is: %g", max);
}
