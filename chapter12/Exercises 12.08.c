#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
    int *pa;
    int size;
    int value;
    printf("Enter the number of elements: ");

    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);

        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("\nEnter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");

    return 0;
}

int *make_array(int elem, int val)
{
    int *ptr = (int *)malloc(elem * sizeof(int));

    if (ptr == NULL) //check it the memory is allocated successful
    {
        puts("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < elem; i++) //initialize allocated memory
        ptr[i] = val;

    return ptr;
}
void show_array(const int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", ar[i]);

        if (i % 8 == 7) //every line only print 8 numbers
            printf("\n");
    }
}
