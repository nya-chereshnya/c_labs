#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int scanLog(int criterion, int L, int N, int M, int log[12][28][34])
{
    int amount = 0;
    for (int student = 0; student < N; student++)
    {
        int bool = 1;
        for (int page = 0; page < L; page++)
        {
            for (int subject = 0; subject < M; subject++)
            {
                if (log[page][student][subject] == !criterion)
                {
                    bool = 0;
                }
            }
        }
        if (bool == 1)
        {
            amount++;
        }
    }
    // return amount;
    printf("%d", amount);
}

void generateLog(int L, int N, int M, int log[12][28][34])
{
    srand(time(NULL));
    for (int page = 0; page < L; page++)
    {
        for (int student = 0; student < N; student++)
        {
            for (int subject = 0; subject < M; subject++)
            {
                log[page][student][subject] = rand() % 2;
                // printf("%d", log[page][student][subject]);
            }
        }
    }
}

void main(void)
{
    int N = 28;
    int M = 34;
    int L = 12;
    int log[L][N][M];
    int never_missed = 0;
    int never_came = 0;
    generateLog(L, N, M, log);
    scanLog(0, L, N, M, log);
    printf("\n");
    scanLog(1, L, N, M, log);
}