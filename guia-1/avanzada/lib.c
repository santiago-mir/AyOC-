#include <stdio.h>
#include "lib.h"

static const double pi = 3.14159; // def de solo lectura con linkage interno

int counter = 0; // global, linkage externo

static int power(int x) // linkage interno
{
    return x * x;
}

static void print(double area)
{
    printf("Area: %3f\n", area);
}

void area(double radius) // linkage externo
{
    double area = pi * power(radius);
    print(area);
    counter++;
}