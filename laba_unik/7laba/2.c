#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double *convertStringToFloatArray(char charArr[100])
{
    double *floatArr = malloc(sizeof(float));
    floatArr[0] = 0;
    int arrSize = 0;
    double digit = 100000;
    char newline[1] = "\n";
    char space[1] = " ";
    char point[1] = ".";
    for (int symbol = 0; ; symbol++)
    {
        if (charArr[symbol] == newline[0]) {
            if (digit > 1) {
                floatArr[arrSize] /= digit * 10;
            }
            break;
        } else {
            if (charArr[symbol] == space[0]) {
                if (digit > 1) {
                    floatArr[arrSize] /= digit * 10;
                }
                arrSize++;
                floatArr = realloc(floatArr, arrSize * sizeof(int));
                floatArr[arrSize] = 0;
                digit = 100000;
                continue;
            } else if (charArr[symbol] == point[0]){
                floatArr[arrSize] /= digit * 10;
                digit = 0.1;
                continue;
            } else {
                floatArr[arrSize] = ((((float)charArr[symbol]) - 48) * digit) + floatArr[arrSize];
                digit /= 10;
            }
        }
    }
    return floatArr;
}

double redactMatrix(int x, int y, double matrix[y][x])
{
    // FILE *file = fopen("matrix.txt", "w")
    for (int row = 0; row < y; row += 2)
    {
        for (int column = 1; column < x; column += 2) 
        {
            matrix[row][column] *= 2;
        }
    }
    printf("\n");
    // for (int row1 = 0; row1 < y; row1 += 1)
    // {
    //     for (int column1 = 0; column1 < x; column1 += 1) 
    //     {
    //         printf("%g ", matrix[row1][column1]);
    //     }
    //     printf("\n");
    // }

    // return *matrix;
}

void generateNewMatrixInTxt(int x, int y, double matrix[y][x]) 
{
    FILE *file = fopen("matrix.txt", "w");
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            fprintf(file, "%g ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
}

void main()
{
    FILE *file = fopen("matrix.txt", "r");
    char matrixSizeInCharArrFormat[100];
    fgets(matrixSizeInCharArrFormat, 100, file);
    double *matrixSize = convertStringToFloatArray(matrixSizeInCharArrFormat);
    char row[100];
    int x = (int)matrixSize[0];
    int y = (int)matrixSize[1];
    double matrix[y][x];
    int yIndex = 0;
    while (fgets(row, 100, file) != NULL)
    {   
        double *line = convertStringToFloatArray(row);
        for (int xIndex = 0; xIndex < x; xIndex++)
        {
            matrix[yIndex][xIndex] = line[xIndex];
            printf("%g ", matrix[yIndex][xIndex]);
        }
        yIndex++;
        printf("\n");
    }
    // rewind(file);   
    fclose(file);
    redactMatrix(x, y, matrix);
    generateNewMatrixInTxt(x, y, matrix);
}