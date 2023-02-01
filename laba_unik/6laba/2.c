#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

char arr_en[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};
char arr_EN[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};
int arr_En_size = sizeof(arr_en);

void replacement(int line_size, char *line)
{
    int check_next_arr = 0;
    for (int old_arr = 0; old_arr < line_size; old_arr++) {
        for (int new_arr_en = 0; new_arr_en < arr_En_size; new_arr_en++) {
            if (line[old_arr] == arr_en[new_arr_en]) {
                if (new_arr_en == arr_En_size - 1) {
                    line[old_arr] = arr_en[0];
                    break;
                } else {
                    line[old_arr] = arr_en[new_arr_en + 1];
                    break;
                }
            } else {
                check_next_arr = 1;
                continue;
            }
        }
        if (check_next_arr == 1) {
            for (int new_arr_EN = 0; new_arr_EN < arr_En_size; new_arr_EN++) {
                if (line[old_arr] == arr_EN[new_arr_EN]) {
                    if (new_arr_EN == arr_En_size - 1) {
                        line[old_arr] = arr_EN[0];
                        break;
                    } else {
                        line[old_arr] = arr_EN[new_arr_EN + 1];
                        break;
                    }
                } else {
                    check_next_arr = 2;
                    continue;
                }
            }
        }
        if (check_next_arr == 2) {
            continue;
        }
        check_next_arr = 0;
    }
    for (int i = 0; i < line_size; i++) {
        printf("%c", line[i]);
    }
    printf("\n");
}

void input(int *line_size, char *line) 
{
    char end_line[1] = {"\n"};
    for ( ; ; )
    {
        char value;
        scanf("%c", &value);
        if (value == end_line[0]) {
            break;
        } else {
            (*line_size)++;
            line = realloc(line, (*line_size) * sizeof(char));
            line[(*line_size) - 1] = value;
        }
    }
}

void main(void)
{
    char *line = malloc(0);
    int line_size = 0;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    input(&line_size, line);
    for (int i = 0; i < 26; i++)
    {
        replacement(line_size, line);
    }
}