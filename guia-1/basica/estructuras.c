#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
void rotacion(int cantidad)
{
    int arr[] = {1, 2, 3, 4};
    size_t len = sizeof(arr) / sizeof(int);

    for (int i = 0; i < cantidad; i++)
    {
        int first = arr[0];
        for (size_t j = 0; j < len - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[len - 1] = first;
    }
}

void tiradas()
{

    int res[] = {0, 0, 0, 0, 0, 0, 0};
    for (size_t i = 0; i < 60000000; i++)
    {
        int random = 1 + rand() % 6;
        res[random] += 1;
    }
    printf("Resultados de las tiradas: ");
    for (size_t i = 1; i <= 6; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    tiradas();
    return 0;
}
