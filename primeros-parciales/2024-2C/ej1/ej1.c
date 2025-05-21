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
 *   - indice_a_inventario
 */
bool EJERCICIO_1B_HECHO = true;

/**
 * OPCIONAL: implementar en C
 */
bool es_indice_ordenado(item_t **inventario, uint16_t *indice, uint16_t tamanio, comparador_t comparador)
{
	for (uint16_t i = 1; i < tamanio; i++)
	{
		item_t *anterior = inventario[indice[i - 1]];
		item_t *actual = inventario[indice[i]];
		if (!comparador(anterior, actual))
		{
			return false;
		}
	}
	return true;
}

/**
 * OPCIONAL: implementar en C
 */
item_t **indice_a_inventario(item_t **inventario, uint16_t *indice, uint16_t tamanio)
{

	item_t **resultado = malloc(tamanio * 8); // cant de elementos * 8
	for (uint16_t j = 0; j < tamanio; j++)
	{
		item_t *elem = inventario[indice[j]];
		resultado[j] = elem;
	}
	return resultado;
}
