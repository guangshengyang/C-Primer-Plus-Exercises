#include <stdio.h>

void ch_line(char ch, int column, int line); 

int main(void)
{
    int ch, column, line;
    printf("Enter the char want to print:");

    ch = getchar();
    while (getchar() != '\n')
        continue;

    printf("Enter how many column and line want to print(Separate the two numbers with a space):");
    scanf("%d %d", &column, &line);

    ch_line(ch, column, line);

    return 0;
}

void ch_line(char ch, int column, int line)
{
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%c", ch);

        printf("\n");
    }
}
