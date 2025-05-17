#include <stdio.h>
#include <stdint.h>

int main()
{
    char c = 100;
    short s = -8712;
    int i = 123456;
    long l = 1234567890;
    long long ll = 123456789123456789;
    float f = 10.0F;
    double d = 1.21;
    long double ld = 1235.21395;

    printf("char(%lu): %d\n", sizeof(c), c);
    printf("short(%lu): %d\n", sizeof(s), s);
    printf("int(%lu): %d\n", sizeof(i), i);
    printf("long(%lu): %ld\n", sizeof(l), l);
    printf("long long(%lu): %lld\n", sizeof(ll), ll);
    printf("float(%lu): %f\n", sizeof(f), f);
    printf("double(%lu): %f\n", sizeof(d), d);
    printf("long double(%lu): %Lf\n", sizeof(ld), ld);

    int8_t i8 = 10;
    int16_t i16 = 120;
    int32_t i32 = 1239593;
    int64_t i64 = 88888888888;
    uint8_t ui8 = 24;
    uint16_t ui16 = 210;
    uint32_t ui32 = 555555;
    uint64_t ui64 = 767676767676;

    printf("int 8(%lu): %d\n", sizeof(i8), i8);
    printf("int 16(%lu): %d\n", sizeof(i16), i16);
    printf("int 32(%lu): %d\n", sizeof(i32), i32);
    printf("int 64(%lu): %ld\n", sizeof(i64), i64);
    printf("unsigned int 8(%lu): %d\n", sizeof(ui8), ui8);
    printf("unsigned int 16(%lu): %d\n", sizeof(ui16), ui16);
    printf("unsigned int 32(%lu): %d\n", sizeof(ui32), ui32);
    printf("unsigned int 64(%lu): %ld\n", sizeof(ui64), ui64);

    return 0;
}
