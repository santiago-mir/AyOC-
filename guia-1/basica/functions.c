#include <stdio.h>

int g = 10; // g global file scope

void functionA()
{
    int a = 20;        // block scope
    static int b = 30; // static duration block scope

    printf("Dentro de la functionA:\n");
    printf("  g = %d\n", g); // print 10
    printf("  a = %d\n", a); // print 20
    printf("  b = %d\n", b); // print 30

    // modif
    g += 5;  // g = 15
    a += 10; // a = 20 automatic duration
    b += 5;  // b = 35
}

void functionB()
{
    int a = 40;        // block scope automatic duration
    static int c = 50; // block scope static duration
    printf("\nDentro de la functionB:\n");
    printf("  g = %d\n", g); // 15
    printf("  a = %d\n", a); // 40
    printf("  c = %d\n", c); // 50

    // modif

    g += 5;  // g = 20
    a += 10; // a = 50 (automatic duration)
    c += 5;  // c = 55
}

int main()
{
    printf("Dentro de main: \n");
    printf("   g = %d\n", g); // print 10

    functionA(); // g = 15 b = 30 -> 35
    functionB(); // g = 20 c = 50 -> 55
    functionA(); // g = 25 b = 35 -> 40
    functionB(); // g = 30 c = 55 -> 60

    printf("\nFinal en main:\n");
    printf("   g = %d\n", g); // g = 30

    return 0;
}

int b, c; // file scope, static duration

void f(void)
{
    int b, d; // block scope, automatic duration
}

void k(int a)
{
    int c; // block scope, automatic duration
    {
        int a, d; // block scope, automatic duration
    }
}