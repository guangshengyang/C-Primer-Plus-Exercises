#include <stdio.h>

void CopyVLA(int m, int n, double *tar_ch, double *ch_start); //Remember to pass variables like m, n first
                                                              //then pass the VLA array，
                                                              //The rules are the same as ordinary arrays
void PrintVLA(int m, int n, double (*tar_ch)[n]);

int main(void)
{
    int m = 4;
    int n = 5;

    double ch[4][5] = {{1.1, 1.2, 1.3, 1.4, 1.5},
                       {2.1, 2.2, 2.3, 2.4, 2.5},
                       {3.1, 3.2, 3.3, 3.4, 3.5},
                       {4.1, 4.2, 4.3, 4.4, 4.5}};

    double tar_ch[m][n]; //A variable-length array, VLA

    for (int i = 0; i < m; i++)
        CopyVLA(m, n, tar_ch[i], ch[i]);

    PrintVLA(m, n, tar_ch);

    return 0;
}

void CopyVLA(int m, int n, double *tar_ch, double *ch_start)
{
    for (int i = 0; i < n; i++)
    {
        *tar_ch++ = *ch_start++;
    }
}

void PrintVLA(int m, int n, double (*tar_ch)[n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%g\t", *(*(tar_ch + i)));

        printf("\n");
    }
}
