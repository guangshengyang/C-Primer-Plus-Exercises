#include <stdio.h>
#include<ctype.h>

int main(void)
{
    int ch;

    while ((ch = getchar()) != EOF)
    {
        //if are \n or \t, print to \n \t
        if (ch == '\n')
        {
            printf("\\n -> ASCII: %d\n", ch);
            continue;
        }
        if (ch == '\t')
        {
            printf("\\t -> ASCII: %d\n", ch);
            continue;
        }

        //isprint(ch) if ch is printable character, return true
        if (isprint(ch))
        {
            printf(" %c -> ASCII: %d\n", ch, ch);
            continue;
        }

        //iscntrl(ch)  if ch is Control character, retrun true
        if (iscntrl(ch))   
        {
            printf("^%c -> ASCII: %d\n", ch + 64, ch);
            continue;
        }
    }

    return 0;
}
