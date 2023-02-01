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
    long double E = pow(10, -4);
    long double S = 1;
    int n1 = 1;
    float x;
    scanf("%f", &x);
    if (x >= 0.1 && x <= 1.0)
    {
        while (element > E)
        {
            element = (pow(cos(M_PI / 4), n1) / factorial(n1)) * x;
            S += element;
            printf("\n%2.20Lf - el\n ", element);
            printf("\n%2.20Lf - S\n ", S);
            printf("\n%2.20Lf - E\n\n ", E);
            n1++;
        }

        long double F = exp(x * cos(M_PI / 4));
        printf("\n%2.20Lg - S", S);
        printf("\n%2.20Lg - F", F);
    }
    else
    {
        printf("out of range");
    }
}