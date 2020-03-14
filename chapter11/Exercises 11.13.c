#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = argc - 1; i > 0; i--)
        printf("%s ", argv[i]);

    return 0;
}

/* 
The c compiler allows the main () function to have no or two arguments.

When main () has two arguments,
the first argument is the number of strings in the command line (often called agrc, argument count), 
the second argument is the argument value (argv, argument value)

The program stores command-line strings in memory and stores each string address in an array of pointers. 
And store the address of the array in the second parameter of main (). 
This parameter is a pointer to a pointer, called argv.

argv[0] point to executable file's identifier(file name)
argv[1] point to first string
argv[2] point to second string
argv[3] point to third string

Many environment(Like Unix, Dos) often use spaces to indicate the end of one string and the beginning of another string. 
You can use double quotes to solve this limitation. 
*/
