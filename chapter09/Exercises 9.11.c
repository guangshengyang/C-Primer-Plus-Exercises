// Using circle to display Fibonacci Sequence

#include <stdio.h>

void fibonacci(void);

int main(void)
{
    fibonacci();
    return 0;
}

void fibonacci(void)
{
    int num_1 = 0;
    int num_2 = 1;
    int num_next = 0;

    int temp;
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", num_next);
        // Image that the Fibonacci Sequence is a triangle
        num_next = num_1 + num_2; // Print the Highest angle of triangle in a circle
        num_1 = num_2;            // Make sure the left angle is always the smaller number
        num_2 = num_next;         // The right angle is always the bigger number
    }
}
