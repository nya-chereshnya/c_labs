#include <stdio.h>
#include <stdlib.h>

void rewriteFile(int positiveCount, int negativeCount)
{
    FILE *oldFile = fopen("binary-3", "rb");
    FILE *newFile = fopen("binary-3_TEMP", "wb");
    fseek(oldFile, 0L, SEEK_END);
    long oldFileSize = ftell(oldFile);
    rewind(oldFile);
    fwrite(&positiveCount, sizeof(positiveCount), 1, newFile);
    fwrite("\n", 1, 1, newFile);
    for (int i = 0; i < oldFileSize; i++)
    {
        char buf[2];
        fread(buf, 1, 1, oldFile);
        if (buf[0] == *"0")
        {
            fseek(oldFile, sizeof(char), SEEK_CUR);
            oldFileSize -= 1;
            continue;
        }
        fwrite(buf, 1, 1, newFile);
    }
    fwrite(&negativeCount, sizeof(negativeCount), 1, newFile);
    fwrite("\n", 1, 1, newFile);
    // char buf[2];
    // fread(buf, 1, 1, newFile);
    fclose(oldFile);
    fclose(newFile);
}

void scanFile(int *positiveCount, int *negativeCount)
{
    FILE *file = fopen("binary-3", "rb");
    char c;
    int zerosCount = 0;
    while ((c = fgetc(file)) != EOF)
    {
        if (c == *"0")
        {
            zerosCount++;
        }
        else if (c == *"-")
        {
            (*negativeCount)++;
        }
    }
    (*positiveCount) = 50 - zerosCount - (*negativeCount);
    fclose(file);
}

void main(void)
{
    int positiveCount = 0;
    int negativeCount = 0;
    scanFile(&positiveCount, &negativeCount);
    rewriteFile(positiveCount, negativeCount);
    remove("binary-3");
    rename("binary-3_TEMP", "binary-3");
}