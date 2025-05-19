#include "ej2.h"

#include <string.h>

// OPCIONAL: implementar en C
void invocar_habilidad(void *carta_generica, char *habilidad)
{
	card_t *carta = carta_generica;
	directory_t carta_dir = carta->__dir;
	for (int i = 0; i < carta->__dir_entries; i++)
	{
		directory_entry_t *entry = carta_dir[i];
		if (strcmp(habilidad, entry->ability_name) == 0)
		{
			void (*ability)(card_t *carta) = entry->ability_ptr;
			ability(carta);
			return;
		}
	}

	if (carta->__archetype != NULL)
	{
		invocar_habilidad(carta->__archetype, habilidad);
	}
}
