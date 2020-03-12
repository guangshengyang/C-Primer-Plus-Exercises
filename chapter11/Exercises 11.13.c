#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 50

int main(void)
{
    int i = 0;
    char c;
    char str[SIZE];
    char store_start_end_ptr[SIZE] = {0};

    while ((c = getchar()) != EOF) //store the characters as string-array type
        str[i++] = c;

    if (str[--i] == '\n') // i++ make pointer point to next address
        str[i] = '\0';    // , using --i to make it move back first, then do if Statement
    SwapCmdOrder(str, store_start_end_ptr);

    return 0;
}
void SwapCmdOrder(char *s, char *store_start_end_ptr)
{
    bool inword = false;

    int i = 0, j = 0;
    int n_word = 0;
    int count = 0;
    int wordlen[SIZE] = {0};

    while ((*s) != '\0')
    {

        if (!isspace(*s) && !inword) //c isn't blankspace and c isn't in word, so it's new word
        {
            inword = true;
            store_start_end_ptr[j++] = s;
            n_word++;
        }

        if (inword = true)
        {
            count++;
        }
        wordlen[i] = count;
        if (isspace(*s) && inword)
        {
            count = 0;
            inword = false;
            i++;
        }
        s++;
    }
    for (int j = 0; j < n_word; j++)
    {
        if (n_word == j + 1)
            wordlen[j] += 1;

        wordlen[j] -= 1;
        printf("%d\t", wordlen[j]);
        printf("%p\n", store_start_end_ptr[j]);
    }
    printf("\n\n");

  
}
