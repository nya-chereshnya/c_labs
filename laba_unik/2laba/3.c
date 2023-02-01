#include <stdio.h>

float main(void)
{
    float a, b;
    scanf("%g", &a);
    scanf("%g", &b);
    if (a == 0 || b == 0)
    {
        printf("%g %g", a, b);
    }
    else if (a > 0 && b > 0)
    {
        if (a > b)
        {
            a *= 2;
            b *= 3;
        }
        else
        {
            b *= 2;
            a *= 3;
        }
        printf("%g %g", a, b);
    }
    else if (a < 0 && b < 0)
    {
        a -= 1;
        b += 1;
        printf("%g %g", a, b);
    }
    else
    {
        if (a > 0 && b < 0)
        {
            b *= -1;
        }
        else
        {
            a *= -1;
        }
        printf("%g %g", a, b);
    }
}
