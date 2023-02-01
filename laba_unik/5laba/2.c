#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void printList(int list[30])
{
    for (int i = 0; i < 30; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n\n");
}

int SquaredListRow(int list[30])
{
    int row_sum = 0;
    for (int i = 0; i < 30; i++)
    {
        row_sum += pow(list[i], 2);
    }
}

int TwoListRowSum(int list1[30], int list2[30])
{
    int row_sum = 0;
    for (int i = 0; i < 30; i++) 
    {
        row_sum += list1[i] * list2[i];
    }
    return row_sum;
}

int OneListRowSum(int list[30]) 
{
    int row_sum = 0;
    for (int i = 0; i < 30; i++) 
    {
        row_sum += list[i];
    }
    return row_sum;
}

int ListCheck(int max_value_index, int list[30])
{
    int count = 0;
    for (int i = 0; i < 30; i++)
    {
        if (list[i] == list[max_value_index])
        {
            count++;
        }
    }
    if (count > 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int ListMaxValueIndex(int list[30])
{
    int max_value_index = -100;
    int max_value = -100;
    for (int i = 0; i < 30; i++)
    {
        if (list[i] > max_value)
        {
            max_value = list[i];
            max_value_index = i;
        }
    }
    return max_value_index;
}

void generateList(int generator, int list[30])
{
    srand(generator);
    int mark[2] = {1, -1};
    for (int i = 0; i < 30; i++)
    {
        list[i] = rand() % 100 * mark[rand() % 2];
    }
}

void main()
{
    int X[30];
    int Y[30];
    int k, p;
    int bool1 = 0;
    int bool2 = 0;
    while (bool1 == 0)
    {
        generateList(time(NULL), X);
        k = ListMaxValueIndex(X);
        bool1 = ListCheck(k, X);
    }
    while (bool2 == 0)
    {
        generateList(time(NULL) + 1, Y);
        p = ListMaxValueIndex(Y);
        bool2 = ListCheck(p, Y);
    }

    printList(X);
    printList(Y);

    // printf("%d %d", k, p);
    // printf("\n\n%d", TwoListRowSum(X, Y));
    
    double result = 0;
    result = ((30 * TwoListRowSum(X, Y)) - (OneListRowSum(X) * OneListRowSum(Y)))/sqrt((k * SquaredListRow(X) - pow(OneListRowSum(X), 2)) * (p * SquaredListRow(Y) - pow(OneListRowSum(Y), 2)));
    printf("\n\n%2.10f", result);
}