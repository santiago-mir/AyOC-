#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
void to_upper_case(char *str)
{
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str = *str - ('a' - 'A');
        }
        str++;
    }
}

size_t length(const char *s)
{
    size_t res = strlen(s);
    return res;
}

void allocateArray(int **arr, int size, int value)
{
    *arr = (int *)malloc(size * sizeof(int));
    if (*arr != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            (*arr)[i] = value;
        }
    }
}

// uso

int *vector = NULL;

void print_int(int x)
{
    printf("%d\n", x);
}
void pretty_print_int(int x)
{
    printf("Entero[%lu bits]: %d\n", sizeof(x) * 8, x);
}

int main()
{

    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    int *p = &matrix[0][0];

    int (*reshape)[2] = (int (*)[2])p;

    char str1[] = "Hola";
    char str2[] = "Mundo";
    char *p1 = str1;
    char *p2 = str2;
    char **pp = &p1;

    pp = &p2;
    **pp = 'X';
    printf("%s %s\n", p1, p2);

    // char literal[] = "Hola que Tal";
    // char hola[] = "Hola";
    // printf("Valor del string %s\n", literal);
    // to_upper_case(literal);
    // printf("Valor en mayusc: %s\n", literal);
    // char nuevo[length(hola) + 1];
    // printf("Valor del string %s\n", nuevo);
    // strcpy(nuevo, hola);
    // printf("Valor del string %s\n", nuevo);
    // int are_equal = strcmp(nuevo, hola);
    // printf("Nuevo y hola son iguales?: %d", are_equal);

    return 0;
}