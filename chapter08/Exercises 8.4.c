// Run the program in Shell, such as Windows CMD, UNix Terminal or directly on Linux
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int ch;
    int countword = 0, countletter = 0;
    bool inword = false; //inword means ch in the word

    while ((ch = getchar()) != EOF)
    {
        //ch is not black & ch is in the word, define it as the beginning of a word
        if (!isspace(ch) && !inword)
        {
            countword++;   //count the words
            inword = true; //Begin a new word
        }

        if (isalpha(ch))
            countletter++;
        //At end of word, redefine inword as false
        if (isspace(ch) && inword)
            inword = false;
    }
    printf("words: %d\n"
           "letters:%d\n"
           "Average letters per word: %.2lf",
           countword, countletter, (double)countletter / countword);

    return 0;
}
