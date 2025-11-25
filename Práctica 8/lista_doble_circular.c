#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
} Nodo;

void insertarFinalCircular(Nodo **inicio, int valor) {
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    nuevo->dato = valor;

    if (*inicio == NULL) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *inicio = nuevo;
        printf("Insertado (circular, único): %d\n", valor);
        return;
    }

    Nodo *ultimo = (*inicio)->anterior;

    nuevo->siguiente = *inicio;
    nuevo->anterior = ultimo;

    ultimo->siguiente = nuevo;
    (*inicio)->anterior = nuevo;

    printf("Insertado circular al final: %d\n", valor);
}

void recorrerCircular(Nodo *inicio) {
    if (inicio == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    Nodo *temp = inicio;
    printf("Recorrido circular: ");

    do {
        printf("%d <-> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != inicio);

    printf("(vuelve al inicio)\n");
}

void eliminarCircular(Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    Nodo *temp = *inicio;

    do {
        if (temp->dato == valor) {

            if (temp->siguiente == temp) {
                printf("Eliminado (último nodo): %d\n", temp->dato);
                free(temp);
                *inicio = NULL;
                return;
            }

            if (temp == *inicio)
                *inicio = temp->siguiente;

            temp->anterior->siguiente = temp->siguiente;
            temp->siguiente->anterior = temp->anterior;

            printf("Eliminado circular: %d\n", temp->dato);
            free(temp);
            return;
        }

        temp = temp->siguiente;

    } while (temp != *inicio);

    printf("Valor %d no encontrado.\n", valor);
}

int main() {
    Nodo *inicio = NULL;
    int n, valor;

    printf("¿Cuántos valores deseas insertar (circular)? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinalCircular(&inicio, valor);
        recorrerCircular(inicio);
    }

    printf("\nValor a eliminar: ");
    scanf("%d", &valor);

    eliminarCircular(&inicio, valor);
    recorrerCircular(inicio);

    return 0;
}
