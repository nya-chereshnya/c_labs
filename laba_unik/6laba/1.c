#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

void newString(int len, char *string, char *new_string)
{
    char *buffer = malloc(0);
    int buffer_size = 0;
    char space[] = " ";
    int start_position, end_position = len - 1, temp, index = 0;
    for (int i = 0; i < len; i++)
    {
        if (string[i] == space[0] || i == len - 1) {
            if (i == len - 1) {
                buffer_size++;
                buffer = realloc(buffer, buffer_size * sizeof(int));
                buffer[buffer_size - 1] = string[i];
            }
            start_position = end_position - buffer_size + 1;
            temp = start_position;
            int index = 0;
            if (i == len - 1) {
            } else {
                new_string[start_position - 1] = space[0];
            }
            for ( ; end_position >= start_position; start_position++)
            {
                new_string[start_position] = buffer[index];
                index++;
            }
            start_position = temp;
            end_position -= buffer_size + 1;
            buffer_size = 0;
            free(buffer);
            buffer = malloc(0);
            continue;
        } else {
            buffer_size++;
            buffer = realloc(buffer, buffer_size * sizeof(int));
            buffer[buffer_size - 1] = string[i];
            /* 
            ���� ��� ������� �� ������ ����������� � �����, �� ��� ��� ���� ���� �� ���������� � ��������
            � ���� ������ � ������ ��� �������������� �����
            ������� ��������� � ����� ������ �������, � ����� ��� �������� ������, ���� ���
            �� ��������� �����
            */
        }
    }
}

void main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char string[] = {"��� ����� ������� �������"};
    int len = strlen(string);
    char new_string[len + 1];
    printf("%s\n", string);
    newString(len, string, new_string);
    printf("%s", new_string);
}