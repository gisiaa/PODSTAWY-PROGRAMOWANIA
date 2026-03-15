#include <stdio.h>

// Zmienne globalne
char g_char = 'A';
int g_int = 42;
long g_long = 123456789L;
float g_float = 3.14f;
double g_double = 2.718281828;

void PamiecSzesnastkowo(void *ptr, size_t size) {
    unsigned char *byte = (unsigned char *)ptr;
    for (size_t i = 0; i < size; ++i) {
        printf("0x%02X ", byte[i]);
    }
    printf("\n");
}

int main() {
    // Deklaracje zmiennych lokalnych
    char l_char = 'B';
    int l_int = 24;
    long l_long = 987654321L;
    float l_float = 1.61f;
    double l_double = 3.141592653;

    // Wyświetlanie adresów i wartości zmiennych globalnych
    printf("Zmienne globalne:\n");
    printf("g_char: Adres: %p, Wartość: %c, Bajty: ", (void *)&g_char, g_char);
    print_memory_hex(&g_char, sizeof(g_char));

    printf("g_int: Adres: %p, Wartość: %d, Bajty: ", (void *)&g_int, g_int);
    print_memory_hex(&g_int, sizeof(g_int));

    printf("g_long: Adres: %p, Wartość: %ld, Bajty: ", (void *)&g_long, g_long);
    print_memory_hex(&g_long, sizeof(g_long));

    printf("g_float: Adres: %p, Wartość: %.2f, Bajty: ", (void *)&g_float, g_float);
    print_memory_hex(&g_float, sizeof(g_float));

    printf("g_double: Adres: %p, Wartość: %.10f, Bajty: ", (void *)&g_double, g_double);
    print_memory_hex(&g_double, sizeof(g_double));

    // Wyświetlanie adresów i wartości zmiennych lokalnych
    printf("\nZmienne lokalne:\n");
    printf("l_char: Adres: %p, Wartość: %c, Bajty: ", (void *)&l_char, l_char);
    print_memory_hex(&l_char, sizeof(l_char));

    printf("l_int: Adres: %p, Wartość: %d, Bajty: ", (void *)&l_int, l_int);
    print_memory_hex(&l_int, sizeof(l_int));

    printf("l_long: Adres: %p, Wartość: %ld, Bajty: ", (void *)&l_long, l_long);
    print_memory_hex(&l_long, sizeof(l_long));

    printf("l_float: Adres: %p, Wartość: %.2f, Bajty: ", (void *)&l_float, l_float);
    print_memory_hex(&l_float, sizeof(l_float));

    printf("l_double: Adres: %p, Wartość: %.10f, Bajty: ", (void *)&l_double, l_double);
    print_memory_hex(&l_double, sizeof(l_double));

    // Zmiana wartości za pomocą wskaźników
    char *p_char = &l_char;
    *p_char = 'C';

    int *p_int = &l_int;
    *p_int = 48;

    long *p_long = &l_long;
    *p_long = 123123123L;

    float *p_float = &l_float;
    *p_float = 2.71f;

    double *p_double = &l_double;
    *p_double = 1.414213562;

    // Wyświetlanie zmienionych wartości
    printf("\nZmienne lokalne po zmianach:\n");
    printf("l_char: Adres: %p, Wartość: %c, Bajty: ", (void *)&l_char, l_char);
    print_memory_hex(&l_char, sizeof(l_char));

    printf("l_int: Adres: %p, Wartość: %d, Bajty: ", (void *)&l_int, l_int);
    print_memory_hex(&l_int, sizeof(l_int));

    printf("l_long: Adres: %p, Wartość: %ld, Bajty: ", (void *)&l_long, l_long);
    print_memory_hex(&l_long, sizeof(l_long));

    printf("l_float: Adres: %p, Wartość: %.2f, Bajty: ", (void *)&l_float, l_float);
    print_memory_hex(&l_float, sizeof(l_float));

    printf("l_double: Adres: %p, Wartość: %.10f, Bajty: ", (void *)&l_double, l_double);
    print_memory_hex(&l_double, sizeof(l_double));

    return 0;
}
