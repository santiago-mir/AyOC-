#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t a = 0xFAAAAAA0;
    uint32_t b = 0xABBBBBBF;
    uint32_t shifted_a = a >> 29; // shift 29 posiciones para quedarme con los 3 bits mas altos
    uint32_t b_last_3bits = b & 0x00000007;
    printf("3 bits altos de a == 3 bits bajos de b: %d\n", b_last_3bits == shifted_a);
    return 0;
}