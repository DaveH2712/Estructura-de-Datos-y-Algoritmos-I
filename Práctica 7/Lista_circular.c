
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

void insertarInicioCircular(Nodo **cabeza, Nodo **ultimo, int valor);
void recorrerCircular(Nodo *cabeza);
int eliminarCircular(Nodo **cabeza, Nodo **ultimo, int valor);
void liberarCircular(Nodo **cabeza, Nodo **ultimo);

int main(void) {
    Nodo *cabeza = NULL;
    Nodo *ultimo = NULL;
    int n = 0;

    printf("\nLista Circular - Inserciones al inicio\n");
    printf("¿Cuántos valores deseas insertar? ");
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        int v; 
        printf("Valor %d: ", i+1);
        if (scanf("%d", &v) != 1) { fprintf(stderr, "Entrada inválida.\n"); return 1; }
        insertarInicioCircular(&cabeza, &ultimo, v);
        printf("Lista tras insertar %d: ", v);
        recorrerCircular(cabeza);
    }

    printf("\nRecorrido circular completo: ");
    recorrerCircular(cabeza);

    if (cabeza) {
        int x; 
        printf("\n¿Qué valor deseas eliminar? ");
        if (scanf("%d", &x) == 1) {
            int ok = eliminarCircular(&cabeza, &ultimo, x);
            if (ok) printf("Se eliminó %d. Lista actualizada: ", x);
            else    printf("No se encontró %d. Lista sin cambios: ", x);
            recorrerCircular(cabeza);
        }
    }

    liberarCircular(&cabeza, &ultimo);
    printf("Memoria liberada correctamente\n");
    return 0;
}

void insertarInicioCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo) { fprintf(stderr, "Error: malloc()\n"); exit(1); }
    nuevo->dato = valor;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = nuevo;
    } else {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
        (*ultimo)->siguiente = *cabeza;
    }
}

void recorrerCircular(Nodo *cabeza) {
    if (!cabeza) { printf("(vacía)\n"); return; }
    Nodo *temp = cabeza;
    do {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != cabeza);
    printf("(vuelve a cabeza)\n");
}

int eliminarCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    if (!cabeza || !*cabeza) return 0;

    Nodo *curr = *cabeza;
    Nodo *prev = *ultimo;

    do {
        if (curr->dato == valor) {
            if (curr == prev) {
                free(curr);
                *cabeza = NULL;
                *ultimo = NULL;
                return 1;
            }
            if (curr == *cabeza) {
                *cabeza = curr->siguiente;
                (*ultimo)->siguiente = *cabeza;
            } else if (curr == *ultimo) {
                *ultimo = prev;
                (*ultimo)->siguiente = *cabeza;
            } else {
                prev->siguiente = curr->siguiente;
            }
            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->siguiente;
    } while (curr != *cabeza);

    return 0;
}

void liberarCircular(Nodo **cabeza, Nodo **ultimo) {
    if (!cabeza || !*cabeza) return;

    Nodo *curr = *cabeza;
    Nodo *stop = *cabeza;

    do {
        Nodo *sig = curr->siguiente;
        free(curr);
        curr = sig;
    } while (curr != stop);

    *cabeza = NULL;
    *ultimo = NULL;
}
