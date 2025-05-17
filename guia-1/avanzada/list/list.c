#include "list.h"
#include <stdlib.h>
//

funcCopy_t getCopyFunction(type_t t)
{
    switch (t)
    {
    case TypeFAT32:
        return (funcCopy_t)copy_fat32;
        break;
    case TypeEXT4:
        return (funcCopy_t)copy_ext4;
        break;
    case TypeNTFS:
        return (funcCopy_t)copy_ntfs;
        break;
    default:
        return NULL;
        break;
    }
}
funcRm_t getRmFunction(type_t t)
{
    switch (t)
    {
    case TypeFAT32:
        return (funcRm_t)rm_fat32;
        break;
    case TypeEXT4:
        return (funcRm_t)rm_ext4;
        break;
    case TypeNTFS:
        return (funcRm_t)rm_ntfs;
        break;
    default:
        return NULL;
        break;
    }
}
// new list
list_t *listNew(type_t t)
{
    list_t *l = malloc(sizeof(list_t));
    l->type = t;
    l->size = 0;
    l->first = NULL;
    return l;
}

// add first node

void listAddFirst(list_t *l, void *data)
{
    node_t *n = malloc(sizeof(node_t));
    if (n == NULL)
    {
        return;
    }
    n->data = getCopyFunction(l->type)(data);
    n->next = l->first;
    l->first = n;
    l->size++;
}

// get node

void *listGet(list_t *l, uint8_t i)
{
    node_t *n = l->first;
    for (uint8_t j = 0; j < i; j++)
        n = n->next;
    return n->data;
}

// remove nove

void *listRemove(list_t *l, uint8_t i)
{
    node_t *tmp = NULL;
    void *data = NULL;
    if (i == 0)
    {
        data = l->first->data;
        tmp = l->first;
        l->first = l->first->next;
    }
    else
    {
        node_t *n = l->first;
        for (uint8_t j = 0; j < i - 1; j++)
            n = n->next;
        data = n->next->data;
        tmp = n->next;
        n->next = n->next->next;
    }
    free(tmp);
    l->size--;
    return data;
}

// delete list

void listDelete(list_t *l)
{
    node_t *n = l->first;
    while (n)
    {
        node_t *tmp = n;
        n = n->next;
        getRmFunction(l->type)(tmp->data);
        free(tmp);
    }
    free(l);
}

// switch node's order
// asumo i <= j
void listSwitchNodes(list_t *l, uint8_t i, uint8_t j)
{
    // lista vacia o con un solo elem o i = j o index fuera de rango;
    if (l->first == NULL || l->first->next == NULL || i == j || j >= l->size)
    {
        return;
    }
    if (i > j)
    {
        uint8_t tmp = i;
        i = j;
        j = tmp;
    }

    // punteros a nodos y sus anteriores

    node_t *prevI = NULL, *prevJ = NULL;
    node_t *nodeI = l->first, *nodeJ = l->first;

    for (uint8_t k = 0; k < i; k++)
    {
        prevI = nodeI;
        nodeI = nodeI->next;
    }
    for (uint8_t k = 0; k < i; k++)
    {
        prevJ = nodeJ;
        nodeJ = nodeJ->next;
    }
    if (nodeI == NULL || nodeJ == NULL)
    {
        return;
    }
    if (nodeI->next == nodeJ)
    {
        if (prevI)
        {
            prevI->next = nodeJ;
        }
        else
        {
            l->first = nodeJ;
        }
        nodeI->next = nodeJ->next;
        nodeJ->next = nodeI;
    }
    else
    {
        if (prevI)
        {
            prevI->next = nodeJ;
        }
        else
        {
            l->first = nodeJ;
        }
        if (prevJ)
        {
            prevJ->next = nodeI;
        }
        node_t *temp = nodeI->next;
        nodeI->next = nodeJ->next;
        nodeJ->next = temp;
    }
}