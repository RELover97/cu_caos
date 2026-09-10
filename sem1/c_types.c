#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


int main()
{
    // boolean 
    bool a = true;
    bool b = false;
    printf("Size of bool is %zu bytes\n", sizeof(a));

    char c;
    signed char sc;
    unsigned char uc;
    printf("Size of char is %z bytes\n", sizeof(c));
    printf("Size of signed char is %zu bytes\n", sizeof(sc));
    printf("Size of unsigned char is %zu bytes\n", sizeof(uc));

    short s;
    signed short ss;
    unsigned short us;
    printf("Size of short is %zu bytes\n", sizeof(s));
    printf("Size of signed short is %zu bytes\n", sizeof(ss));
    printf("Size of unsigned short is %zu bytes\n", sizeof(us));

    int i;
    signed int si;
    unsigned int ui;
    printf("Size of int is %zu bytes\n", sizeof(i));
    printf("Size of signed int is %zu bytes\n", sizeof(si));
    printf("Size of unsigned int is %zu bytes\n", sizeof(ui));

    long l;
    long int li;
    int long il;
    unsigned long ul;
    printf("Size of long is %zu bytes\n", sizeof(l));
    printf("Size of long int is %zu bytes\n", sizeof(li));
    printf("Size of long int is %zu bytes\n", sizeof(il));
    printf("Size of unsigned long is %zu bytes\n", sizeof(ul));

    long long ll;
    long long int lli;
    unsigned long long ull;
    printf("Size of long long is %zu bytes\n", sizeof(ll));
    printf("Size of long long int is %zu bytes\n", sizeof(lli));
    printf("Size of unsigned long long is %zu bytes\n", sizeof(ull));

    float f;
    double d;
    printf("Size of float is %zu bytes\n", sizeof(f));
    printf("Size of double is %zu bytes\n", sizeof(d));

    int8_t i8;
    uint8_t ui8;
    printf("Size of int8_t is %zu bytes\n", sizeof(i8));
    printf("Size of uint8_t is %zu bytes\n", sizeof(ui8));

    int16_t i16;
    uint16_t ui16;
    printf("Size of int16_t is %zu bytes\n", sizeof(i16));
    printf("Size of uint16_t is %zu bytes\n", sizeof(ui16));

    int32_t i32;
    uint32_t ui32;
    printf("Size of int32_t is %zu bytes\n", sizeof(i32));
    printf("Size of uint32_t is %zu bytes\n", sizeof(ui32));

    int64_t i64;
    uint64_t ui64;
    printf("Size of int64_t is %zu bytes\n", sizeof(i64));
    printf("Size of uint64_t is %zu bytes\n", sizeof(ui64));
}
