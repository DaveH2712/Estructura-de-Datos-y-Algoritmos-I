#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

void insertarInicio(Nodo **cabeza, int valor) {
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
    printf("Insertado al inicio: %d\n", valor);
}

void recorrer(Nodo *cabeza) {
    Nodo *temp = cabeza;
    printf("Lista: ");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void eliminar(Nodo **cabeza, int valor) {
    if (*cabeza == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    Nodo *temp = *cabeza;
    Nodo *anterior = NULL;

    while (temp != NULL && temp->dato != valor) {
        anterior = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        printf("Valor %d no encontrado.\n", valor);
        return;
    }

    if (anterior == NULL) {
        *cabeza = temp->siguiente;
    } else {
        anterior->siguiente = temp->siguiente;
    }

    printf("Eliminado: %d\n", temp->dato);
    free(temp);
}

void liberar(Nodo *cabeza) {
    Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
    printf("Memoria liberada correctamente.\n");
}

int main() {
    Nodo *cabeza = NULL;
    int n, valor;

    printf("¿Cuántos valores deseas insertar al inicio? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }

    printf("\nValor a eliminar: ");
    scanf("%d", &valor);

    eliminar(&cabeza, valor);
    recorrer(cabeza);

    liberar(cabeza);
    return 0;
}
