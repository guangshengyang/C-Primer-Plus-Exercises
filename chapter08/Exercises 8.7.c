#include <stdio.h>

#define BASIC_SALARY 10

#define STDARD_WORKHOUR 40
#define OVERWORK_MULTIPLIER 1.5

#define LEVEL_1 300
#define LEVEL_2 450

#define RATE_1 0.15
#define RATE_2 0.2
#define RATE_3 0.25

int map_choice_hour(char choice);                        //Mapping of options to hourly pay
double total_wages_count(double p_hour, double hours);   //calculate total wage not include tax
double tax_count(double total_wages);                    //calculate tax
double net_income_count(double total_wages, double tax); //calculate wages after deduction

int main(void)
{
    char choice;
    double hours;
    double p_hour;

    double total_wages;
    double tax;
    double net_income;

    printf(" ********************************************************************\n"
           "Enter the number corresponding to the desired pay rate or action:\n"
           "a $8.75/hr                     b $9.33/hr\n"
           "c $10.00/hr                    d $11.20/hr\n"
           "q quit\n"
           "********************************************************************\n");
    printf("Enter  \"a  b  c  d or q\"  Here:");

    while ((choice = getchar()) != EOF)
    {
        while (getchar() != '\n')
            continue; //Skip remaining line breaks or line break will be see as a input too

        if (choice >= 'a' && choice <= 'd')
        {
            printf("Your working hours per week:");
            scanf("%lf", &hours);

            p_hour = map_choice_hour(choice);
            total_wages = total_wages_count(p_hour, hours);
            tax = tax_count(total_wages);
            net_income = net_income_count(total_wages, tax);

            printf("Total wages: %lf\n", total_wages);
            printf("Tax: %lf\n", tax);
            printf("Net income: %lf\n", net_income);
        }

        else if (choice == 'q')
        {
            printf("Good Bye.");
            return 0;
        }
        else
        {
            printf("Please check your input.Input again:");
            continue;
        }
    }

    return 0;
}

int map_choice_hour(char choice)
{
    double p_hour;

    switch (choice)
    {
    case 'a':
        p_hour = 8.75;
        break;
    case 'b':
        p_hour = 9.33;
        break;
    case 'c':
        p_hour = 10.00;
        break;
    case 'd':
        p_hour = 11.20;
    default:
        printf("default none here .");
        break;
    }

    return p_hour;
}

double total_wages_count(double p_hour, double hours)
{
    double total_wages;

    if (hours > 40)
        hours = (hours - STDARD_WORKHOUR) * OVERWORK_MULTIPLIER + hours;

    total_wages = hours * p_hour;

    return total_wages;
}

double tax_count(double total_wages)
{
    double tax;
    while (total_wages <= LEVEL_1)
    {
        tax = total_wages * RATE_1;
        continue;
    }
    while (total_wages < LEVEL_2)
    {
        tax = LEVEL_1 * RATE_1 + (total_wages - LEVEL_1) * RATE_2;
        continue;
    }

    tax = LEVEL_1 * RATE_1 + (total_wages - LEVEL_1) * RATE_2 + (total_wages - LEVEL_2) * RATE_3;

    return tax;
}

double net_income_count(double total_wages, double tax)
{
    double net_income = total_wages - tax;

    return net_income;
}
