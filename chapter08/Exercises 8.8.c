#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int check(char ch, float first_num, float second_num);
char choice_symbol_map(char ch);
float result_calculate(char ch, float first_num, float second_num);

int main(void)
{
    float first_num, second_num;
    char ch, symbol;
    float result;

    printf("Enter the operation of your choice:\n"
           "a add               b subtract\n"
           "c multiply          d divide\n"
           "q quit\n");
    printf("Enter  \"a  b  c  d or q\"  Here:");
    ch = getchar();

    while (getchar() != '\n')
        continue;

    if (ch == 'q')
    {
        printf("Bye.");
        exit(0);
    }
    if (ch < 'a' || ch > 'd')
    {
        printf("Invalid input,please input again.");
        exit(0);
    }

    printf("Enter first number:");
    scanf("%f", &first_num);
    while (getchar() != '\n')
        continue;

    check(ch, first_num, second_num);

    printf("Enter second number:");
    scanf("%f", &second_num);

    while (getchar() != '\n')
        continue;
    check(ch, first_num, second_num);

    symbol = choice_symbol_map(ch);
    result = result_calculate(ch, first_num, second_num);

    printf("%f %c %f = %f", first_num, symbol, second_num, result);

    return 0;
}

int check(char ch, float first_num, float second_num)
{

    if (ch == 'd' && second_num == 0)
    {
        printf("Enter a numer other than 0:");
        scanf("%f", &second_num);
        while (getchar() != '\n')
            continue;
    }

    if (isdigit(first_num))
    {
        printf("Please enter a number, such as 2.5, -1.78E8, 3 and etc:");
        scanf("%f", &first_num);
        while (getchar() != '\n')
            continue;
    }

    if (isdigit(second_num))
    {
        printf("Please enter a number, such as 2.5, -1.78E8, 3 and etc:");
        scanf("%f", &second_num);
        while (getchar() != '\n')
            continue;
    }

    return 0;
}

char choice_symbol_map(char ch)
{
    char symbol;
    switch (ch)
    {
    case 'a':
        symbol = '+';
        break;
    case 'b':
        symbol = '-';
        break;
    case 'c':
        symbol = '*';
        break;
    case 'd':
        symbol = '/';
        break;

    default:
        break;
    }

    return symbol;
}

float result_calculate(char ch, float first_num, float second_num)
{
    float result;
    switch (ch)
    {
    case 'a':
        result = first_num + second_num;
        break;
    case 'b':
        result = first_num - second_num;
        break;
    case 'c':
        result = first_num * second_num;
        break;
    case 'd':
        result = first_num / second_num;
        break;

    default:
        break;
    }

    return result;
}
