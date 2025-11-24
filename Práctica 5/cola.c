#include <stdio.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int cantidad;
} Cola;

void inicializar(Cola *c) {
    c->frente = 0;
    c->final = -1;
    c->cantidad = 0;
    printf("Cola inicializada vacía.\n");
}

int estaLlena(Cola *c) {
    return c->cantidad == MAX;
}

int estaVacia(Cola *c) {
    return c->cantidad == 0;
}

void enqueue(Cola *c, int valor) {
    if (estaLlena(c)) {
        printf("Error: La cola está llena, no se puede insertar.\n");
        return;
    }
    c->final = (c->final + 1) % MAX;
    c->datos[c->final] = valor;
    c->cantidad++;
    printf("ENQUEUE: %d\n", valor);
}

int dequeue(Cola *c) {
    if (estaVacia(c)) {
        printf("Error: La cola está vacía, no se puede sacar.\n");
        return -1;
    }
    int valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->cantidad--;
    printf("DEQUEUE: %d\n", valor);
    return valor;
}

void mostrar(Cola *c) {
    if (estaVacia(c)) {
        printf("Cola vacía.\n");
        return;
    }
    printf("Estado actual de la cola: ");
    int idx = c->frente;
    for (int i = 0; i < c->cantidad; i++) {
        printf("%d ", c->datos[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Cola c;
    int n, valor;

    inicializar(&c);

    printf("\n¿Cuántos elementos quieres encolar? (max 5): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor a enqueue: ");
        scanf("%d", &valor);
        enqueue(&c, valor);
        mostrar(&c);
    }

    printf("\n¿Cuántos elementos quieres hacer dequeue?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        dequeue(&c);
        mostrar(&c);
    }

    return 0;
}
