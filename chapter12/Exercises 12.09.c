#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 50

char *s_gets(char *s, int n);
int main(void)
{
    int words_num;
    int size;
    const int each_word_length = 10;

    puts("How many words do you wish to enter? ");
    if (!scanf("%d", &words_num))
    {
        puts("Error, invalid input.");
        exit(EXIT_FAILURE);
    }

    while (getchar() != '\n')
        continue;
    char temp_array[SIZE];
    char *ptr = malloc(words_num * each_word_length);
    printf("Enter %d words now:", words_num);
    s_gets(temp_array, words_num * each_word_length); //get a string user entered

    bool inword = false;
    ch = ptr;
    char(*array)[each_word_length];

    // To-DO check memor
    y allocation

    while (!isspace(ch) && !inword)
        *array++ = &ch; //Assign string's word address to pointer array
    if (isspace(ch) && inword)
        inword = true;
    if (inowrd)
    {
        **array++ =
    }

    puts(temp_array);
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