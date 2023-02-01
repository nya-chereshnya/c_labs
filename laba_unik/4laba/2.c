#include <stdio.h>
#include <stdlib.h>

void enumeration(int i, int *a, int *index)
{
    int bool = 1;
    for (int j = 2; j < i; j++)
    {
        if (i % j == 0)
        {
            bool = 0;
            break;
        }
    }
    if (bool == 1)
    {
        *index += 1;
        a = realloc(a, *index * sizeof(int));
        a[*index - 1] = i;
    }
}

void main(void)
{
    int index = 0;
    int *a = malloc(0);

    for (int i = 10; i < 100; i++)
    {
        enumeration(i, a, &index);
    }
    for (int k = 0; k < index; k++)
    {
        printf("%d ", a[k]);
    }
}
