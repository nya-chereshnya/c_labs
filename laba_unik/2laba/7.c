#include <stdio.h>
#include <math.h>

double factorial(int i)
{
    int score;
    score = i;

    while (score > 1)
    {
        i = i * (score - 1);
        score -= 1;
    }
    return i;
}

void main(void)
{
    long double element = 1;
    long double E = pow(10, -6);
    long double S = 1;
    int n1 = 2;
    float x;
    scanf("%f", &x);
    if (x >= 0.1 && x <= 1.0)
    {

        while (element > E)
        {
            element = pow(x, n1) / factorial(n1);
            S += element;
            printf("\n%2.20Lf - el\n ", element);
            printf("\n%2.20Lf - S\n ", S);
            printf("\n%2.20Lf - E\n\n ", E);
            n1 *= 2;
        }

        long double chx = (exp(x) + exp(-x)) / 2;
        printf("\n%2.20Lg", S);
        printf("\n%2.20Lg", chx);
    }
    else
    {
        printf("out of range");
    }
}
