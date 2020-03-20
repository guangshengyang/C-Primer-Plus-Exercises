#include <stdio.h>

void return_call_times(int *calltimes);

int main(void)
{
    int calltimes = 0;

    for (int i = 0; i < 50; i++)
        return_call_times(&calltimes);

    printf("Call times:%d", calltimes);

    return 0;
}

void return_call_times(int *calltimes)
{
   (*calltimes)++;
}
