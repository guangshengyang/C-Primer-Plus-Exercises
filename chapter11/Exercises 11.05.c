#include <stdio.h>
#include <string.h>

char *MyStrchr(const char *s, char c);

int main(void)
{
    char ch;
    char *return_ptr;
    char source_string[] = "Welcome to VS Code!";
    printf("What character you are look up?\n");
    ch = getchar();

    return_ptr = MyStrchr(source_string, ch);

    printf("Pointer to the first position of the source string:%p\n"
           "The Return pointer:%p",
           source_string, return_ptr);

    return 0;
}

char *MyStrchr(const char *s, char c)
{
    int tempch;
    const char *initial_pointer = s;
    for (int i = 0; i < strlen(s) + 1; i++) // "\0" is part of the string
    {
        tempch = *s++;
        if (tempch == c)
        {
            return initial_pointer;
        }
        continue;
    }
    return NULL;
}
