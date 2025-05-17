#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *nombre;
    int edad;
} persona_t;

persona_t *crearPersona(char *name, int edad)
{
    persona_t *nuevaPersona = malloc(sizeof(persona_t));
    if (nuevaPersona == NULL)
    {

        return NULL;
    }
    nuevaPersona->nombre = malloc(strlen(name) + 1);

    if (nuevaPersona->nombre == NULL)
    {
        free(nuevaPersona);
        return NULL;
    }
    strcpy(nuevaPersona->nombre, name);

    nuevaPersona->edad = edad;
    return nuevaPersona;
}

void eliminarPersona(persona_t *persona)
{
    if (persona == NULL)
        return;

    free(persona->nombre);
    free(persona);
}

int main()
{
    persona_t *nuevaPersona = crearPersona("Santiago", 27);
    if (nuevaPersona == NULL)
    {
        return 1;
    }
    printf("Nombre: %s\n", nuevaPersona->nombre);
    printf("Edad: %d\n", nuevaPersona->edad);
    eliminarPersona(nuevaPersona);
    return 0;
}