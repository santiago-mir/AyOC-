#include <stdio.h>

int main()
{
    int a = 5;
    int b = 3;
    int c = 2;
    int d = 1;
    printf("a + b + * c / d: %d\n", a + b * c / d); // (a + (b * c) ) / d
    printf("a div b: %d\n", a % b);
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a & b: %d\n", a & b);
    printf("a | b: %x\n", a | b);
    printf("a~: %x\n", ~a);
    printf("a && b: %d\n", a && b);
    printf("a || b: %d\n", a || b);
    printf("a << 1: %X\n", a << 1);
    printf("a >> 1: %x\n", a >> 1);
    printf("a+=b: %d\n", a += b);
    printf("a-=b: %d\n", a -= b);
    printf("a*=b: %d\n", a *= b);
    printf("a/=b: %d\n", a /= b);
    printf("a div=b: %d\n", a %= b);
    int i = 6;
    int y = 6;
    printf("i++: %d\n", i++);
    printf("++y: %d\n", ++y);
}