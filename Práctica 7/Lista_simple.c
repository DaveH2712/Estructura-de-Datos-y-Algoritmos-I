
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

void insertarInicio(Nodo **cabeza, int valor);
void recorrer(Nodo *cabeza);
int eliminar(Nodo **cabeza, int valor);
void liberar(Nodo *cabeza);

int main(void) {
    Nodo *cabeza = NULL;
    int n = 0;

    printf("\nLista Simple - Inserciones al inicio\n");
    printf("¿Cuántos valores deseas insertar? ");
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        int v; 
        printf("Valor %d: ", i+1);
        if (scanf("%d", &v) != 1) { fprintf(stderr, "Entrada inválida.\n"); return 1; }
        insertarInicio(&cabeza, v);
        printf("Lista tras insertar %d: ", v);
        recorrer(cabeza);
    }

    printf("\nRecorrido final: ");
    recorrer(cabeza);

    if (cabeza) {
        int x; 
        printf("\n¿Qué valor deseas eliminar? ");
        if (scanf("%d", &x) == 1) {
            int ok = eliminar(&cabeza, x);
            if (ok) printf("Se eliminó %d. Lista actualizada: ", x);
            else    printf("No se encontró %d. Lista sin cambios: ", x);
            recorrer(cabeza);
        }
    }

    liberar(cabeza);
    printf("Memoria liberada correctamente\n");
    return 0;
}

void insertarInicio(Nodo **cabeza, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo) { fprintf(stderr, "Error: malloc()\n"); exit(1); }
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void recorrer(Nodo *cabeza) {
    Nodo *temp = cabeza;
    while (temp) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

int eliminar(Nodo **cabeza, int valor) {
    if (!cabeza || !*cabeza) return 0;
    Nodo *curr = *cabeza;
    Nodo *prev = NULL;

    if (curr->dato == valor) {
        *cabeza = curr->siguiente;
        free(curr);
        return 1;
    }

    while (curr && curr->dato != valor) {
        prev = curr;
        curr = curr->siguiente;
    }

    if (!curr) return 0;

    prev->siguiente = curr->siguiente;
    free(curr);
    return 1;
}

void liberar(Nodo *cabeza) {
    Nodo *temp = cabeza;
    while (temp) {
        Nodo *sig = temp->siguiente;
        free(temp);
        temp = sig;
    }
}
