#include <stdio.h>
#include <stdlib.h>

#define YEARLENGTH 4
#define MONTHLENGTH 10
#define DAYLENGTH 2

#define LENGTH 3

struct Months
{
    char month_name[MONTHLENGTH];
    char month_name_abbreviation[LENGTH];
    int month_days;
    int month_Serial_num;
};

struct Months month_array[12] = {
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
char format_input(char *year, char *month, char *day, struct Months *month_array);
int count_days(char *year, char *month, char *day);

int main(void)
{
    char year[YEARLENGTH + 1];
    char month[MONTHLENGTH + 1];
    char day[DAYLENGTH + 1];

    printf("Enter the year(sample:2020):");
    s_gets(year, YEARLENGTH);
    printf("Enter the month(sample:January, Jan, 1, 01):");
    s_gets(month, MONTHLENGTH);
    printf("Enter the day(sample:05):");
    s_gets(day, DAYLENGTH);

    printf("OK, now I'll count the  days till this date(include this date)\n");

     format_input(year, month, day, month_array); //format user input

    printf("%d %d %d", year, month, day);

    /*  count_days(year, month, day);

    int days_sum = count_days(monthname, month_array);

    printf("Until this month the days_sum:%d", days_sum); */

    return 0;
}

char format_input(char *year, char *month, char *day, struct Months *month_array)
{
    year = atoi(year);
    day = atoi(day);

    if (atoi(month) != 0)
        month = atoi(month); //atoi() can hand with string like "01" "010"
    else
        for (int i = 0; i < 12; i++)
        {
            if (!(strcmp(month, month_array[i].month_name) && strcmp(month, month_array[i].month_name_abbreviation)))
                month = i + 1;
        }
}

int count_days(char *year, char *month, char *day)
{
    strcmp();
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
