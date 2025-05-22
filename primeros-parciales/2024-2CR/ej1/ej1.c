#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ej1.h"

/**
 * Marca el ejercicio 1A como hecho (`true`) o pendiente (`false`).
 *
 * Funciones a implementar:
 *   - es_indice_ordenado
 */
bool EJERCICIO_1A_HECHO = true;

/**
 * Marca el ejercicio 1B como hecho (`true`) o pendiente (`false`).
 *
 * Funciones a implementar:
 *   - contarCombustibleAsignado
 */
bool EJERCICIO_1B_HECHO = true;

/**
 * Marca el ejercicio 1B como hecho (`true`) o pendiente (`false`).
 *
 * Funciones a implementar:
 *   - modificarUnidad
 */
bool EJERCICIO_1C_HECHO = true;

/**
 * OPCIONAL: implementar en C
 */
void optimizar(mapa_t mapa, attackunit_t *compartida, uint32_t (*fun_hash)(attackunit_t *))
{
    uint32_t res_compartida = fun_hash(compartida);
    for (uint16_t i = 0; i < 255; i++)
    {
        for (uint16_t j = 0; j < 255; j++)
        {
            attackunit_t *temp = mapa[i][j];
            if (temp)
            {
                uint32_t hash_temp = fun_hash(temp);
                if (hash_temp == res_compartida)
                {
                    temp->references--;
                    mapa[i][j] = compartida;
                    compartida->references++;
                    if (temp->references == 0)
                    {
                        free(temp);
                    }
                }
            }
        }
    }
}

/**
 * OPCIONAL: implementar en C
 */
uint32_t contarCombustibleAsignado(mapa_t mapa, uint16_t (*fun_combustible)(char *))
{
    uint32_t res = 0;
    for (uint16_t i = 0; i < 255; i++)
    {
        for (uint16_t j = 0; j < 255; j++)
        {
            if (mapa[i][j])
            {
                attackunit_t *temp = mapa[i][j];
                uint16_t combustible_base = fun_combustible(temp->clase);
                uint16_t combustible_extra = temp->combustible - combustible_base;
                res += combustible_extra;
            }
        }
    }
    return res;
}

/**
 * OPCIONAL: implementar en C
 */
void modificarUnidad(mapa_t mapa, uint8_t x, uint8_t y, void (*fun_modificar)(attackunit_t *))
{

    if (mapa[x][y])
    {
        attackunit_t *unidad = mapa[x][y];
        if (unidad->references > 1)
        {
            attackunit_t *nueva = malloc(sizeof(attackunit_t));

            *nueva = *unidad;
            nueva->references = 1;
            unidad->references--;
            mapa[x][y] = nueva;
            unidad = nueva;
        }
        fun_modificar(unidad);
    }
}
