#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ej1.h"

/**
 * Marca el ejercicio 1A como hecho (`true`) o pendiente (`false`).
 *
 * Funciones a implementar:
 *   - init_fantastruco_dir
 */
bool EJERCICIO_1A_HECHO = true;

// OPCIONAL: implementar en C
void init_fantastruco_dir(fantastruco_t *card)
{
    // reservo memoria para el directorio (sizeof directory = 8 y *2 por que quiero 2 posiciones en el arr)
    directory_t new_dir = malloc(sizeof(directory_t) * 2);
    // ahora creamos las entradas
    directory_entry_t *sleep_entry = create_dir_entry("sleep", sleep);
    directory_entry_t *wake_entry = create_dir_entry("wakeup", wakeup);
    // las metemos al directorio
    new_dir[0] = sleep_entry;
    new_dir[1] = wake_entry;
    // y ahora asignamos todo a mi card
    card->__dir = new_dir;
    card->__dir_entries = 2;
}

/**
 * Marca el ejercicio 1A como hecho (`true`) o pendiente (`false`).
 *
 * Funciones a implementar:
 *   - summon_fantastruco
 */
bool EJERCICIO_1B_HECHO = true;

// OPCIONAL: implementar en C
fantastruco_t *summon_fantastruco()
{
    // creamos nuestra nueva carta
    fantastruco_t *new_card = malloc(sizeof(fantastruco_t));
    // inicializamos el directorio
    init_fantastruco_dir(new_card);
    new_card->face_up = 1;
    new_card->__archetype = 0; // null
    return new_card;
}
