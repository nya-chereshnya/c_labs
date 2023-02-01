#include <stdio.h>
#include <math.h>

float main(void)
{
    double S;
    float x;
    printf("x = ");
    scanf("%g", &x);

    if (x < M_PI && x > 0)
    {
        S = ((tan(M_PI / 2 - x)) - (exp(sqrt(x)))) / (log(abs(5 * x)) + (pow((atan(x)), 2)));
        printf("%g", S);
    }
    else
    {
        printf("out of range");
    }
}