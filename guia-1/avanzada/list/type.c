#include "stdio.h"
#include "stdlib.h"
#include "type.h"

// fat32

fat32_t *new_fat32()
{
    fat32_t *newFat32 = malloc(sizeof(fat32_t));
    // memory check
    if (newFat32 == NULL)
    {
        return NULL;
    }
    *newFat32 = 10;
    return newFat32;
}

fat32_t *copy_fat32(fat32_t *file)
{
    fat32_t *newCopy = malloc(sizeof(fat32_t));
    // memory check
    if (newCopy == NULL)
    {
        return NULL;
    }
    *newCopy = *file;
    return newCopy;
}

void rm_fat32(fat32_t *file)
{
    free(file);
}

// ext4

ext4_t *new_ext4()
{
    ext4_t *newExt4 = malloc(sizeof(ext4_t));
    // memory check
    if (newExt4 == NULL)
    {
        return NULL;
    }
    *newExt4 = 20;
    return newExt4;
}

ext4_t *copy_ext4(ext4_t *file)
{
    ext4_t *newCopy = malloc(sizeof(ext4_t));
    // memory check
    if (newCopy == NULL)
    {
        return NULL;
    }
    *newCopy = *file;
    return newCopy;
}

void rm_ext4(ext4_t *file)
{
    free(file);
}

// ntfs

ntfs_t *new_ntfs()
{
    ntfs_t *newNtfs = malloc(sizeof(ntfs_t));
    // memory check
    if (newNtfs == NULL)
    {
        return NULL;
    }
    *newNtfs = 30;
    return newNtfs;
}

ntfs_t *copy_ntfs(ntfs_t *file)
{
    ntfs_t *newCopy = malloc(sizeof(ntfs_t));
    // memory check
    if (newCopy == NULL)
    {
        return NULL;
    }
    *newCopy = *file;
    return newCopy;
}

void rm_ntfs(ntfs_t *file)
{
    free(file);
}