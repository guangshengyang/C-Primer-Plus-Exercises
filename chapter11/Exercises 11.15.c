#include <stdio.h>
#include <ctype.h>
#define SIZE 50

char *s_gets(char *s, int n);
int my_atoi(char *s); // Take care of SIZE of int(this program use int, if not enough, use long or long long)

int main(void)
{
    char digitstr[SIZE];

    s_gets(digitstr, SIZE);
    int val = my_atoi(digitstr);
    printf("%d", val);

    return 0;
}

int my_atoi(char *s2)
{
    char *s2_begin = s2;
    int res = 0; //Initialize result

    while (*s2 != '\0')
    {
        if (!isdigit(*s2)) //if find that not all characters are nums, quit
        {
            puts("Sorry, wrong input.");
            return 0;
        }

        s2++;
    }
    s2 = s2_begin;

    for (int i = 0; s2[i] != '\0'; i++)
        res = res * 10 + (s2[i] - '0'); // The main implementation code

    return res;
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

