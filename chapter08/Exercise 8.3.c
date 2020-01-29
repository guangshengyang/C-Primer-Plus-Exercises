#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    int countupper = 0, countlower = 0;

    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            countupper++;

        if (islower(ch))
            countlower++;
    }
    printf("Counted_upper: %d\n"
           "counted_lower: %d",
           countupper, countlower);

    return 0;
}
