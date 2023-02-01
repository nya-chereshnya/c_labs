#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortMatrix(int matrix[9][10])
{
    for (int iteration = 0; iteration < 10; iteration++)
    {
        // 10 итераций для полной сортировки от меньшего к большему, т.к. столбцов 10
        for (int column = 0; column < 9; column++)
        {
            // проход по столбцам первой строки
            if (matrix[0][column] > matrix[0][column + 1])
            {
                for (int row = 0; row < 9; row++)
                {
                    int tmp = matrix[row][column];
                    matrix[row][column] = matrix[row][column + 1];
                    matrix[row][column + 1] = tmp;
                }
                // в 1 строке наибеольший элемент сдвигается в конец
                // столбнец привязанный к этому элементу сдвигается вместе с ним
                // со следующей итерацией менее большой элемент сдвигается на предпоследнее место, вместе с ним его столбец
            }
        }
    }
}

void generateMatrix(int matrix[9][10])
{
    srand(time(NULL));
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            // проход по ячейкам (строка -> столбец) и их заполнение
            int random_sing[2] = {-1, 1};
            matrix[row][column] = (rand() % 100 * random_sing[rand() % 2]);
            // генерация случайного символа вместе со случайным знаком
        }
    }
}

void printMatrix(int matrix[9][10])
{
    printf("\n\n");
    for (int row = 0; row < 9; row++)
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

void main()
{
    int matrix[9][10];
    generateMatrix(matrix);
    // генерация случайной матрицы
    printMatrix(matrix);
    // вызов функции вывода матрицы
    sortMatrix(matrix);
    printMatrix(matrix);
    // сортировка матрицы и ее вывод
}