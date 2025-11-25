#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

void insertarCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    nuevo->dato = valor;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = nuevo;
    } else {
        nuevo->siguiente = *cabeza;
        (*ultimo)->siguiente = nuevo;
        *cabeza = nuevo;
    }

    printf("Insertado en lista circular: %d\n", valor);
}

void recorrerCircular(Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    Nodo *temp = cabeza;
    printf("Lista circular: ");

    do {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != cabeza);

    printf("(regresa al inicio)\n");
}

void eliminarCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    Nodo *actual = *cabeza;
    Nodo *anterior = *ultimo;

    do {
        if (actual->dato == valor) {
            if (actual == *cabeza) {
                *cabeza = actual->siguiente;
                (*ultimo)->siguiente = *cabeza;

                if (actual == *ultimo) {
                    *cabeza = NULL;
                    *ultimo = NULL;
                }
            } else {
                anterior->siguiente = actual->siguiente;
                if (actual == *ultimo)
                    *ultimo = anterior;
            }

            printf("Eliminado (circular): %d\n", actual->dato);
            free(actual);
            return;
        }

        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    printf("Valor %d no encontrado.\n", valor);
}

int main() {
    Nodo *cabeza = NULL;
    Nodo *ultimo = NULL;
    int n, valor;

    printf("¿Cuántos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarCircular(&cabeza, &ultimo, valor);
        recorrerCircular(cabeza);
    }

    printf("\nValor a eliminar: ");
    scanf("%d", &valor);

    eliminarCircular(&cabeza, &ultimo, valor);
    recorrerCircular(cabeza);

    return 0;
}
