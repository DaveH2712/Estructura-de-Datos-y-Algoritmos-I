#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
} Nodo;

void insertarInicio(Nodo **inicio, int valor) {
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = *inicio;

    if (*inicio != NULL)
        (*inicio)->anterior = nuevo;

    *inicio = nuevo;

    printf("Insertado al inicio: %d\n", valor);
}

void insertarFinal(Nodo **inicio, int valor) {
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (*inicio == NULL) {
        nuevo->anterior = NULL;
        *inicio = nuevo;
        printf("Insertado al final (único nodo): %d\n", valor);
        return;
    }

    Nodo *temp = *inicio;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;

    temp->siguiente = nuevo;
    nuevo->anterior = temp;

    printf("Insertado al final: %d\n", valor);
}

void recorrerAdelante(Nodo *inicio) {
    Nodo *temp = inicio;
    printf("Recorrido adelante: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void recorrerAtras(Nodo *inicio) {
    if (inicio == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    Nodo *temp = inicio;

    while (temp->siguiente != NULL)
        temp = temp->siguiente;

    printf("Recorrido atrás: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->dato);
        temp = temp->anterior;
    }
    printf("NULL\n");
}

void eliminar(Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    Nodo *temp = *inicio;

    while (temp != NULL && temp->dato != valor)
        temp = temp->siguiente;

    if (temp == NULL) {
        printf("Valor %d no encontrado.\n", valor);
        return;
    }

    if (temp->anterior == NULL) {
        *inicio = temp->siguiente;
        if (*inicio != NULL)
            (*inicio)->anterior = NULL;
    } else if (temp->siguiente == NULL) {
        temp->anterior->siguiente = NULL;
    } else {
        temp->anterior->siguiente = temp->siguiente;
        temp->siguiente->anterior = temp->anterior;
    }

    printf("Eliminado: %d\n", temp->dato);
    free(temp);
}

void liberar(Nodo *inicio) {
    Nodo *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }
    printf("Memoria liberada correctamente.\n");
}

int main() {
    Nodo *inicio = NULL;
    int n, valor;

    printf("¿Cuántos valores deseas insertar al inicio? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
        recorrerAdelante(inicio);
    }

    printf("\n¿Cuántos valores deseas insertar al final? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
        recorrerAdelante(inicio);
    }

    printf("\nValor a eliminar: ");
    scanf("%d", &valor);
    eliminar(&inicio, valor);
    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    liberar(inicio);
    return 0;
}
