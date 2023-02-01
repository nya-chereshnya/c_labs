#include <stdio.h>
#include <math.h>

float calculation(float x, float y)
{
    float res;
    if (x > 0)
    {
        res = x - abs(y);
    }
    else if ((x <= 0) && (y < 0))
    {
        res = pow(y, 2) - x;
    }
    else
    {
        res = ++y;
    }
    return res;
}

void main(void)
{
    float x, y;

    printf("x = ");
    scanf("%g", &x);

    printf("y = ");
    scanf("%g", &y);

    printf("%g", calculation(x, y));
}
