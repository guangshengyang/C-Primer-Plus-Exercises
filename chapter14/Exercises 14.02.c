#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define YEARLENGTH 4
#define MONTHLENGTH 10
#define DAYLENGTH 2
#define MONTHABBREVIATIONLENGTH 3

struct Months //strcut template
{
    char month_name[MONTHLENGTH];
    char month_name_abbreviation[MONTHABBREVIATIONLENGTH];
    int month_days;
};

//array with strcut MOnths type
struct Months month_array[12] = {
    {"January", "Jan", 31},
    {"February", "Feb", 28}, //nonleap year,Feb has 28 days(default consider year as nonleap year)
    {"March", "Mar", 31},
    {"April", "Apr", 30},
    {"May", "May", 31},
    {"June", "Jun", 30},
    {"July", "Jul", 31},
    {"August", "Aug", 31},
    {"September", "Sep", 30},
    {"October", "Oct", 31},
    {"November", "Nov", 30},
    {"December", "Dec", 31}};

char *s_gets(char *s, int n);
char format_input(char *year, char *month, char *day, struct Months *month_array,
                  int *year_inttype, int *month_inttype, int *day_inttype);                       //format user input
int count_days(int year_inttype, int month_inttype, int day_inttype, struct Months *month_array); //don't need to pass variables address

int main(void)
{
    char year[YEARLENGTH + 1];
    char month[MONTHLENGTH + 1];
    char day[DAYLENGTH + 1]; //+1 to store \0

    int year_inttype, month_inttype, day_inttype; //store converted result

    printf("Enter the year(sample:2020):");
    s_gets(year, YEARLENGTH + 1);
    printf("Enter the month(sample:January, Jan, 1, 01):");
    s_gets(month, MONTHLENGTH + 1);
    printf("Enter the day(sample:05):");
    s_gets(day, DAYLENGTH + 1);

    printf("OK, now I'll count the  days till this date(include this date)\n");

    format_input(year, month, day, month_array, &year_inttype, &month_inttype, &day_inttype); //format user input

    int day_counted = count_days(year_inttype, month_inttype, day_inttype, month_array);

    printf("Days till the date is:%d", day_counted);

    return 0;
}

char format_input(char *year, char *month, char *day, struct Months *month_array,
                  int *year_inttype, int *month_inttype, int *day_inttype)
{
    *year_inttype = atoi(year);
    *day_inttype = atoi(day);

    if (atoi(month) != 0)
        *month_inttype = atoi(month); //atoi() can hand with string like "01" "010"
    else
        for (int i = 0; i < 12; i++) //if user input string to express which month
        {
            if (!(strcmp(month, month_array[i].month_name) && strcmp(month, month_array[i].month_name_abbreviation)))
                *month_inttype = i + 1;
        }
}

int count_days(int year_inttype, int month_inttype, int day_inttype, struct Months *month_array)
{
    bool ret_val;
    if (((year_inttype % 4 == 0) && (year_inttype % 100 != 0)) || year_inttype % 400 == 0) //check if it's leap year
        ret_val = true;

    int day_count = 0;

    for (int i = 0; i < month_inttype - 1; i++)
        day_count = day_count + month_array[i].month_days;

    day_count = day_count + day_inttype;

    if (ret_val && month_inttype > 2)
        day_count = day_count + 1; //Leap year has 29 days in February.

    return day_count;
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