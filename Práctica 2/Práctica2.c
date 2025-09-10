#include <stdio.h>

int main(void) {
    int a[5] = {2, 4, 6, 8, 10}; // Declara un arreglo de 5 enteros e inicializa sus valores

    int *p = a; // Declara un puntero a entero y lo inicializa apuntando al primer elemento del arreglo (a[0])

    printf("1) a[1] = %d\n", a[1]); 
    // Imprime el segundo elemento del arreglo (índice 1), que es 4

    printf("2) *(a+3) = %d\n", *(a+3)); 
    // Usa aritmética de punteros para acceder al cuarto elemento del arreglo (a[3]), que es 8

    printf("3) *p++ = %d\n", *p++); 
    // Imprime el valor apuntado por p (a[0] = 2), luego incrementa p para que apunte a a[1]

    printf("4) *++p = %d\n", *++p); 
    // Primero incrementa p (ahora apunta a a[2]), luego imprime el valor apuntado (6)

    printf("5) p[1] = %d\n", p[1]); 
    // Accede al elemento siguiente al que apunta p (p apunta a a[2], así que p[1] es a[3] = 8)

    printf("6) *(p+=2) = %d\n", *(p+=2)); 
    // Incrementa p en 2 posiciones (ahora apunta a a[4]), luego imprime el valor apuntado (10)

    printf("7) p - a = %ld\n", p - a); 
    // Calcula la diferencia entre las posiciones de p y a (a[4] - a[0] = 4)

    return 0; // Finaliza el programa
}
