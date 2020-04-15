#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 10
#define LENGTH 3
#define MONTHS 12

struct Days
{
    char months_name[SIZE];
    char months_name_abbreviation[LENGTH];
    int months_days;
    int months_Serial_num;
};

struct Days months_array[MONTHS] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2}, //nonleap year,Feb has days
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}};

char *s_gets(char *s, int n);
int count_days(char *s, struct Days *array);

int main(void)
{
    char monthsname[SIZE];
    // extern struct Days months_array[MONTHS];

    printf("Enter the number of the months name(abbreviation is OK, too)\n"
           "I'll count the how many days till this month(include this month):");
    s_gets(monthsname, SIZE); //get user input

    int days_sum = count_days(monthsname, months_array);

    printf("Until this month the days_sum:%d", days_sum);

    return 0;
}

int count_days(char *s, struct Days *array)
{
    int days_sum = 0;
    bool flag = true;
    bool legality = false; //input legality

    for (int i = 0; i < MONTHS; i++)
    {
        if (!(strcmp(s, array[i].months_name) && strcmp(s, array[i].months_name_abbreviation)))
            legality = true;
    }
    if (!legality)
    {
        printf("Invalid Input.\n"); //Verify that the input's legality
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MONTHS; i++)
    {
        flag = (bool)(strcmp(s, array[i].months_name) && strcmp(s, array[i].months_name_abbreviation));
        days_sum = days_sum + array[i].months_days;
        if (flag == false)
            return days_sum;
    }
}

char *s_gets(char *s, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(s, n, stdin);
    if (ret_val)
    {
        while (s[i] != '\n' && s[i] != '\0')
            s++;
        if (s[i] == '\n')
            s[i] = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}