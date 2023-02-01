#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void writeLine(FILE *file)
{
    int mark = rand() % 2;
    char randNum[1];
    randNum[0] = rand() % 10 + '0';
    if (mark == 0)
    {
        fwrite(randNum, sizeof(char), 1, file);
        fwrite("\n", sizeof(char), 1, file);
    }
    else if (mark == 1)
    {
        if (randNum[0] == *"0")
        {
            fwrite(randNum, sizeof(char), 1, file);
        }
        else
        {
            fwrite("-", sizeof(char), 1, file);
            fwrite(randNum, sizeof(char), 1, file);
        }
        fwrite("\n", sizeof(char), 1, file);
    }
}

void makeFile()
{
    FILE *file = fopen("binary-3", "wb");
    srand(time(NULL));
    for (int i = 0; i < 50; i++)
    {
        writeLine(file);
    }
}

void main(void)
{
    makeFile();
}