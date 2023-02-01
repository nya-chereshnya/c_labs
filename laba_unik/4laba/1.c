#include <stdio.h>
#include <stdlib.h>

void iteration(int *list)
{
    for (int i = 0; i < 18; i++)
    {
        printf("\nB[%d] - %d", i, list[i]);
    }
    printf("\n");
}

int main(void)
{
    int a = -1, b = -1;
    int *max_negative = calloc(2, sizeof(int));
    int *first_positive = calloc(2, sizeof(int));
    int *B = calloc(18, 8);
    int score = 0, i = 0;
    printf("type 18 massive elements (its must be at least one negative and one positive number, also negative numbers cant be repeated): \n");

    for (i = 0; i < 18; i++)
    {
        scanf("%d", &B[i]);
        if (B[i] < 0)
        {
            if (score == 0)
            { //внесение первого отрицательного числа в список отриц чисел
                max_negative[0] = B[i];
                max_negative[1] = i;
                b = 1;
                score++;
            }
            else
            {
                if (B[i] > max_negative[0])
                {                           //отбор наибольшего отрицательного
                    max_negative[0] = B[i]; //внесение наибольшего отрицательного и его индекса в спецаильный список
                    max_negative[1] = i;
                }
            }
        }
        else if (a <= 0)
        { //проверка на существование 1 положительного
            a = 1;
            first_positive[0] = B[i]; //внесение первого положительно и его индекса в специальный список
            first_positive[1] = i;
        }
    }
    if ((a == 1) && (b == 1))
    {
        iteration(&(*B));

        B[first_positive[1]] = max_negative[0];
        B[max_negative[1]] = first_positive[0];

        iteration(&(*B));
    }
    else
    {
        printf("\ninnvalid array: no one negative or positive element");
    }
}