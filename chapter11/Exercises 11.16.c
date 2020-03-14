/* 
Sample:
PS C:\Users\trave\Documents\Visual Studio Code\Visual C> ./programname -p -u -l
Welcome to VS Code!     <--- input
Welcome to VS Code!     <--- -p    printout
WELCOME TO VS CODE!     <--- -u    printout
welcome to vs code!     <--- -l    printout

 */
#include <stdio.h>
#include <string.h>
#define SIZE 50
#define CMDNUMBER 3

char *s_gets(char *s, int n);

int main(int argc, char *argv[])
{
    char str[SIZE];

    s_gets(str, SIZE);
    for (int i = 1; i <= CMDNUMBER; i++)
    {

        if (strcmp(argv[i], "-p") == 0)
        {
            puts(str);
        }
        else if (strcmp(argv[i], "-u") == 0)
        {
            strupr(str);
            puts(str);
        }
        else if (strcmp(argv[i], "-l") == 0)
        {
            strlwr(str);
            puts(str);
        }
    }

    return 0;
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

