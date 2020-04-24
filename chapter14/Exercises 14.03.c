
#include <stdio.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTH 40
#define MAXBKS 100

struct Book //Book template
{
    char title[MAXTITL];
    char author[MAXAUTH];
    double value;
};

char *s_gets(char *s, int n);
void get_books(struct Book *library[], int count);

int main(void)
{
    struct Book library[MAXBKS];
    int count = 0;
    int index;
    get_books(library, count);

    return 0;
}

void get_books(struct Book *library[], int count) //pass struct itself
{
    while (count < MAXBKS && library[count]->title[0] != '\0')
    {
        printf("Enter the book title.\n");
        printf("Press <Enter> at the start of a line to stop.\n");
        printf("Enter here:");
        s_gets(library[count]->title, MAXTITL);

        printf("Now, enter the author:");
        s_gets(library[count]->author, MAXAUTH);

        printf("OK, now enter the value:");
        scanf("%lf", &library[count]->value);

        while (getchar() != '\n')
            continue;

        if (count < MAXBKS)
            printf("Now for next book.\n");
        count++;
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