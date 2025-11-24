#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

Nodo* crear_nodo(int valor) {
    Nodo *n = (Nodo *) malloc(sizeof(Nodo));
    if (!n) {
        perror("malloc falló en crear_nodo");
        return NULL;
    }
    n->dato = valor;
    n->sig = n;
    return n;
}

Nodo* insertar_final(Nodo *ultimo, int valor) {
    Nodo *nuevo = crear_nodo(valor);
    if (!nuevo) return ultimo;

    if (ultimo == NULL) {
        return nuevo;
    } else {
        nuevo->sig = ultimo->sig;
        ultimo->sig = nuevo;
        return nuevo;
    }
}

void mostrar_lista(Nodo *ultimo) {
    if (ultimo == NULL) {
        printf("Lista vacía.\n");
        return;
    }
    Nodo *actual = ultimo->sig;
    printf("Lista circular: ");
    do {
        printf("%d ", actual->dato);
        actual = actual->sig;
    } while (actual != ultimo->sig);
    printf("\n");
}

Nodo* eliminar_valor(Nodo *ultimo, int valor) {
    if (ultimo == NULL) return NULL;

    Nodo *prev = ultimo;
    Nodo *curr = ultimo->sig;

    do {
        if (curr->dato == valor) {
            if (curr == prev) {
                free(curr);
                return NULL;
            } else {
                prev->sig = curr->sig;
                if (curr == ultimo) {
                    ultimo = prev;
                }
                free(curr);
                return ultimo;
            }
        }
        prev = curr;
        curr = curr->sig;
    } while (curr != ultimo->sig);

    printf("Valor %d no encontrado.\n", valor);
    return ultimo;
}

void liberar_lista(Nodo *ultimo) {
    if (ultimo == NULL) return;
    Nodo *inicio = ultimo->sig;
    Nodo *curr = inicio;
    Nodo *next;
    do {
        next = curr->sig;
        free(curr);
        curr = next;
    } while (curr != inicio);
}

int main(void) {
    Nodo *ultimo = NULL;
    int opcion, valor;

    do {
        printf("\n--- Lista circular (dinámica) ---\n");
        printf("1. Insertar al final\n");
        printf("2. Mostrar lista\n");
        printf("3. Eliminar valor\n");
        printf("4. Liberar y salir\n");
        printf("Elige opción: ");
        if (scanf("%d", &opcion) != 1) {
            printf("Entrada inválida.\n");
            break;
        }
        switch (opcion) {
            case 1:
                printf("Valor a insertar: ");
                if (scanf("%d", &valor) != 1) { printf("Entrada inválida.\n"); break; }
                ultimo = insertar_final(ultimo, valor);
                break;
            case 2:
                mostrar_lista(ultimo);
                break;
            case 3:
                printf("Valor a eliminar: ");
                if (scanf("%d", &valor) != 1) { printf("Entrada inválida.\n"); break; }
                ultimo = eliminar_valor(ultimo, valor);
                break;
            case 4:
                liberar_lista(ultimo);
                ultimo = NULL;
                printf("Memoria liberada. Saliendo.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 4);

    return 0;
}
