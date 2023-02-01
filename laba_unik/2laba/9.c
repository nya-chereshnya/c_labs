#include <stdio.h>

int factorial(int n)
{
    int score;
    score = n;
    while (score > 1)
    {
        n = n * (score - 1);
        score -= 1;
    }
    return n;
}

void searchFactorial(int n)
{
    for (int i = 0; i <= 15; i++)
    {
        if (factorial(i) == n)
        {
            printf("%d is factorial %d\n", n, i);
        }
    }
}

void main(void)
{
    int n = 1;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        searchFactorial(n);
    }
}