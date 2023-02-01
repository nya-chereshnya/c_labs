#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int **matrix, int rows)
{
    printf("\n\n");
    if (rows < 1)
    {
        printf("empty");
    }
    else
    {
        for (int row = 0; row < rows; row++)
        {
            for (int column = 0; column < 10; column++)
            {
                // проход по ячейкам строка -> столбец
                if (matrix[row][column] < 0)
                {
                    if (matrix[row][column] < -9)
                    {
                        printf("   %d", matrix[row][column]);
                    }
                    else
                    {
                        printf("    %d", matrix[row][column]);
                    }
                }
                else
                {
                    if (matrix[row][column] > 9)
                    {
                        printf("    %d", matrix[row][column]);
                    }
                    else
                    {
                        printf("     %d", matrix[row][column]);
                    }
                }
                // оформление ровной таблицы за счет добавлния пробелов перед выводом значения ячейки
                // формула расчета пробелов ->  6 - количество_занимаемых_значением_символов
                // -6 -> 2 символа, соответственно 6-2=4 пробела ставится перед выводом
            }
            printf("\n");
            // переход на новую строку
        }
        printf("\n");
    }
}

void sortMatrix(int **matrix, int *safed, int *safed_size, int *size)
{
    for (int row = 0; row < (*safed_size); row++)
    {
        for (int column = 0; column < 10; column++)
        {
            matrix[row][column] = matrix[safed[row]][column];
        }
    }
    for (int row = (*safed_size); row < 9; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            matrix[row][column] = 0;
        }
    }
    (*size) = (*safed_size);
}

void scanMatrix(int **matrix, int *safed, int *safed_size)
{
    for (int row = 0; row < 9; row++)
    {
        int bool = 1;
        for (int column = 0; column < 10; column++)
        {
            if (matrix[row][column] == 1)
            {
                bool = 0;
                break;
            }
        }
        if (bool == 1)
        {
            (*safed_size)++;
            safed = realloc(safed, sizeof(int));
            safed[(*safed_size) - 1] = row;
        }
    }
}

void generateMatrix(int **matrix)
{
    int random_sing[2] = {-1, 1};
    srand(time(NULL));
    for (int row = 0; row < 9; row++)
    {
        matrix[row] = malloc(10 * sizeof(int));
        for (int column = 0; column < 10; column++)
        {
            matrix[row][column] = (rand() % 10 * random_sing[rand() % 2]);
        }
    }
}

void main()
{
    int **matrix = malloc(9 * sizeof(int *));
    int size = 9;
    int *safed = malloc(0);
    int safed_size = 0;
    generateMatrix(matrix);
    // генерация случайной матрицы
    printMatrix(matrix, 9);
    // вызов функции вывода матрицы
    scanMatrix(matrix, safed, &safed_size);
    // printf("\n\n\n");
    printf("\n%d - s\n", safed_size);

    for (int j = 0; j < safed_size; j++)
    {
        printf("%d ", safed[j]);
    }

    sortMatrix(matrix, safed, &safed_size, &size);
    printMatrix(matrix, size);
}