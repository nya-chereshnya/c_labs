#include <stdio.h>

void main(void)
{
    int a;
    printf("a = ");
    scanf("%d", &a);

    while (a > 0)
    {
        a = a / 10;
        // printf("%d", a);
        if (a < 10)
        {
            printf("%d", a);
            a = 0;
        }
    }
}