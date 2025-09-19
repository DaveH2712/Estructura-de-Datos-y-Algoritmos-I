#include <stdio.h>

typedef struct {
    int dato;
} Nodo;

int main() {
    Nodo n1;          // Un nodo normal
    Nodo *p;          // Un puntero a Nodo
    p = &n1;          // 'p' apunta a 'n1'

    // 1) Guardar el valor 10 en 'dato' usando n1
    n1.dato = 10;   // (se usa . porque es acceso directo a una variable de estructura)

    // 2) Guardar el valor 20 en 'dato' usando p
    p->dato = 20;   // (se usa -> porque 'p' es un puntero a la estructura)

    // 3) Imprimir el contenido de 'dato' con n1
    printf("%d\n", n1.dato);  // (acceso directo con .)

    // 4) Imprimir el contenido de 'dato' con p
    printf("%d\n", p->dato);  // (acceso indirecto con ->)

    return 0;
}
