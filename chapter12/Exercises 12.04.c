#include <stdio.h>

int g_calltimes = 0;

void return_call_times(void);

int main(void)
{
    for (int i = 0; i < 50; i++)
        return_call_times();

    printf("Call times:%d", g_calltimes);

    return 0;
}

void return_call_times()
{
    extern int g_calltimes;
    g_calltimes++;
}
