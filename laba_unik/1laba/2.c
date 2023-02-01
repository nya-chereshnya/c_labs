#include <stdio.h>

void values(float a, float b, int c, int d)
{
    printf("\na = %g, b = %g, c = %d, d = %d", a, b, c, d);
}

void main(void)
{
    int c = 5, d;
    float a = 5.0, b;
    printf("\nd - ");
    scanf("%d", &d);
    printf("\nb - ");
    scanf("%f", &b);

    a = a + b - 2;
    values(a, b, c, d);

    c++;
    d = c - a + d;
    values(a, b, c, d);

    a *= c;
    c--;
    values(a, b, c, d);

    a /= 10;
    c /= 2;
    b--;
    d *= c + b + a;
    values(a, b, c, d);
}