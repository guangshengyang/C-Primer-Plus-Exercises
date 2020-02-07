#include <stdio.h>

void ch_line(char ch, int column, int line);

int main(void)
{
    int ch, column, line;

    printf("Enter char, column, line here(Separate each two input with a space):");
    scanf("%c %d %d", &ch, &column, &line);

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
