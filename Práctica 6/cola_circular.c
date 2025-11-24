#include <stdio.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size;
} ColaCircular;

void inicializar(ColaCircular *c) {
    c->frente = 0;
    c->final = 0;
    c->size = 0;
    printf("Cola circular inicializada.\n");
}

int isEmpty(ColaCircular *c) { return c->size == 0; }
int isFull(ColaCircular *c)  { return c->size == MAX; }

void enqueue(ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("ERROR: Cola llena. No se puede encolar %d.\n", valor);
        return;
    }

    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;
    c->size++;

    printf("ENQUEUE: %d\n", valor);
}

int dequeue(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("ERROR: Cola vacía. No hay elementos que desencolar.\n");
        return -1;
    }

    int valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;

    printf("DEQUEUE: %d\n", valor);
    return valor;
}

int peek(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("La cola está vacía.\n");
        return -1;
    }
    return c->datos[c->frente];
}

void printQueue(ColaCircular *c) {
    printf("Estado de la cola (size=%d, frente=%d, final=%d): ", c->size, c->frente, c->final);
    
    if (isEmpty(c)) {
        printf("[vacía]\n");
        return;
    }

    int i = c->frente;
    for (int k = 0; k < c->size; k++) {
        printf("%d ", c->datos[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    ColaCircular c;
    inicializar(&c);

    printf("\n-- Pruebas de la práctica --\n");

    enqueue(&c, 5);
    enqueue(&c, 10);
    enqueue(&c, 15);
    printQueue(&c);

    dequeue(&c);
    printQueue(&c);

    enqueue(&c, 20);
    enqueue(&c, 25);
    enqueue(&c, 30);
    printQueue(&c);

    return 0;
}
