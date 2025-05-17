#include <stdio.h>
#define NAME_LEN 50

typedef struct
{
    char *nombre;
    int vida;
    double ataque;
    double defensa;
} mounstro_t;

mounstro_t evolution(mounstro_t mounstro)
{
    mounstro_t nuevo_mounstro = {
        mounstro.nombre,
        mounstro.vida,
        mounstro.ataque += 10,
        mounstro.defensa += 10};

    return nuevo_mounstro;
}

int main()
{
    mounstro_t mounstros[3] = {
        {"Dragon Rojo", 100, 5.5, 6.0},
        {"Golem de Piedra", 150, 3.3, 8.2},
        {"Leviatan", 90, 7.4, 4.3},
    };
    printf("Info del mounstro 1 %f %f\n", mounstros[0].ataque, mounstros[0].defensa);
    mounstro_t modificado = evolution(mounstros[0]);
    printf("Info nueva del mounstro 1 %f %f\n", modificado.ataque, modificado.defensa);

    return 0;
}