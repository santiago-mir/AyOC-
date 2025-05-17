#include <stdio.h>
#include "list.h"

int main()
{
    list_t *l = listNew(TypeFAT32);
    fat32_t *f1 = new_fat32(); // 111
    listAddFirst(l, f1);
    listRemove(l, 0);
    return 0;
}