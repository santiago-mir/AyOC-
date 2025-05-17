#include <stdio.h>
#include <stdlib.h>

int x;      // segmento bbs (vars globales no inicializadas y vars estaticas)
int y = 32; // seg data (vars globales inicializadas y vars estaticas)

int main(int argc, char *argv[])
{
    int *data;                             // stack frame (direcciones de retorno, params y vars locales)
    int i;                                 // stack frame
    data = (int *)malloc(sizeof(int) * y); // vars dinamicas administradas por malloc/free

    return 0;
}
