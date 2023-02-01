#include <stdio.h>
#include <math.h>

int main()
{
    int i = 1;
    int n, count = 0;
    // ввод числа для перевода в двоичную
    scanf("%d", &n);
    // создание списка нужного размера, под один разряд уходит максимум 4 нуля
    int m = n;
    do
    {
        m = m / 10;
        count++;
    } while (m > 1);
    count *= 4;
    int bin[count];
    for (int j = 0; j < count; j++)
    {
        bin[j] = 0;
    }
    // заполнение списка с обратной стороны, так как для перевода в двоичное число остатки от деление надо пересортировать в обратном порядке
    while (n > 0)
    {
        bin[count - i] = n % 2;
        i++;
        n = n / 2;
    }
    // проверека 1: массив
    for (int j = 0; j < count; j++)
    {
        printf("%d", bin[j]);
    }
    printf("\n\n\n");
    // проверка 2: создание числа
    double NUM = 0;
    for (int j = 0; j < count; j++)
    {
        NUM += bin[j] * pow(10, count - j - 1);
    }
    printf("%lf", NUM);
}