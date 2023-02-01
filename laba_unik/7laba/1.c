#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void max_size_strings_return_to_file(FILE *file, FILE *new_file, int lenght_values_array_size, int *lenght_values, int max_size, char *text)
{
    int temp_size = 1;
    char space[1] = " ";
    char temp[256];
    while (fgets(temp, 1000, file) != NULL) 
    {   
        for (int i = 1; i < strlen(temp); i++)
        {   
            if (temp[i] == space[0]) {
                temp_size++;
            }
        }
        if (temp_size == max_size) {
            fprintf(new_file, "%s", temp);
        }
        temp_size = 1;
    }
}

int max_strings_size_search(int lenght_values_array_size, int *lenght_values) 
{   
    int max_size = 1;
    for (int i = 1; i < lenght_values_array_size; i++)
    {
        char space[1] = " ";
        if (lenght_values[i] > max_size) {
            max_size = lenght_values[i];
        }
    }
    return max_size;
}

void every_string_lenght(FILE *file, int *lenght_values_array_size, int *lenght_values)
{   
    int max_size = 1;
    char temp[256];
    char space[1] = " ";
    while (fgets(temp, 1000, file) != NULL) 
    {
        // printf("\n%s", temp);
        (*lenght_values_array_size)++;
        for (int i = 1; i < strlen(temp); i++)
        {   
            if (temp[i] == space[0]) {
                max_size++;
            }
        }
        lenght_values[(*lenght_values_array_size)] = max_size;
        max_size = 1;
    }
    rewind(file);
}

void main(void) 
{
    char *text = malloc(0);
    FILE *file = fopen("old.txt", "r");
    int *lenght_values = malloc(0);
    int lenght_values_array_size = 0;
    if (file == 0) {
        perror("error");
        exit(0);
    } else {
        FILE *new_file = fopen("new.txt", "w");
        if (new_file == 0) {
            perror("error");
            exit(0);
        } else {
            every_string_lenght(file, &lenght_values_array_size, lenght_values);
            int max_size = max_strings_size_search(lenght_values_array_size, lenght_values);
            // printf("MAX_LEN - %d", max_size);
            max_size_strings_return_to_file(file, new_file, lenght_values_array_size, lenght_values, max_size, text);
            fclose(new_file);
        }
    }
    fclose(file);
}