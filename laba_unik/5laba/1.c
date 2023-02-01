#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int matrix_size, int matrix[matrix_size][matrix_size])
{
    printf("\n\n");
    for (int row = 0; row < matrix_size; row++)
    {
        for (int column = 0; column < matrix_size; column++)
        {
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
        }
        printf("\n");
    }
    printf("\n");
}

void changeMatrix(int arithmetic_average, int matrix_size, int matrix[matrix_size][matrix_size])
{
    int skip_position1 = 0;
    int skip_position2 = matrix_size-1;
    for (int row = 0; row < matrix_size; row++)
    {
        for (int column = 0; column < matrix_size; column++)
        {
            if (column == skip_position1 || column == skip_position2)
            {   
                continue;
            }
            else 
            {
                matrix[row][column] = arithmetic_average;
            }
        }
        skip_position1++;
        skip_position2--;
    }
}

void scanMatrix(int *arithmetic_average, int matrix_size, int matrix[matrix_size][matrix_size])
{
    int sum = 0;
    int start_position = 0;
    for (int row = 0; row < matrix_size; row++)
    {
        sum += matrix[row][start_position];
        start_position++;
    }
    for (int row = 0; row < matrix_size; row++)
    {
        if (matrix_size % 2 == 1 && row == matrix_size / 2)
        {
            start_position--;
            continue;
        }
        else
        {
            sum += matrix[row][start_position - 1];
            start_position--;
        }
    }
    if (matrix_size % 2 == 1)
    {
        (*arithmetic_average) = sum / ((matrix_size * 2) - 1);
    }
    else
    {
        (*arithmetic_average) = sum / (matrix_size * 2);
    }
}

void generateMatrix(int matrix_size, int matrix[matrix_size][matrix_size])
{
    srand(time(NULL));
    for (int row = 0; row < matrix_size; row++)
    {
        for (int column = 0; column < matrix_size; column++)
        {
            matrix[row][column] = rand() % 100;
        }
    }
}

void main()
{
    int bool = 1;
    while (bool > 0)
    {
        int matrix_size;
        int arithmetic_average;

        printf("enter size - ");
        scanf("%d", &matrix_size);

        int matrix[matrix_size][matrix_size];
        bool = matrix_size;

        generateMatrix(matrix_size, matrix);
        printMatrix(matrix_size, matrix);
        scanMatrix(&arithmetic_average, matrix_size, matrix);
        changeMatrix(arithmetic_average, matrix_size, matrix);
        printMatrix(matrix_size, matrix);
    }
}