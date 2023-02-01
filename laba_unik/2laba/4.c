#include <stdio.h>
#include <math.h>

void main(void)
{
    int n, num1 = -1, num2 = 0;
    float Y = 0, x, el;
    printf("\nx = ");
    scanf("%g", &x);
    printf("\nn = ");
    scanf("%d", &n);
    if (n > 10)
    {
        for (int i = 0; i < n; i++)
        {
            num1++;
            num2++;
            el = (n - num1) * cos(num2 * x);
            printf("%g\n", el);
            printf("%d\n", num1);
            printf("%d\n", num2);
            Y += el;
        }
        printf("\n\n%g\n", Y);
    }
    else
    {
        printf("gokrtpokterk");
    }
}