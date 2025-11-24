#include <stdio.h>

#define MAX 6

typedef struct {
    int datos[MAX];
    int front;
    int size;
} Deque;

void inicializar(Deque *d) {
    d->front = 0;
    d->size = 0;
    printf("Deque inicializado.\n");
}

int isEmpty(Deque *d) { return d->size == 0; }
int isFull(Deque *d)  { return d->size == MAX; }

int rearIndex(Deque *d) {
    return (d->front + d->size - 1 + MAX) % MAX;
}

void insert_front(Deque *d, int valor) {
    if (isFull(d)) {
        printf("ERROR: Deque lleno. No se puede insertar al frente.\n");
        return;
    }

    d->front = (d->front - 1 + MAX) % MAX;
    d->datos[d->front] = valor;
    d->size++;

    printf("INSERT_FRONT: %d\n", valor);
}

void insert_rear(Deque *d, int valor) {
    if (isFull(d)) {
        printf("ERROR: Deque lleno. No se puede insertar al final.\n");
        return;
    }

    int rear = (d->front + d->size) % MAX;
    d->datos[rear] = valor;
    d->size++;

    printf("INSERT_REAR: %d\n", valor);
}

int delete_front(Deque *d) {
    if (isEmpty(d)) {
        printf("ERROR: Deque vacío.\n");
        return -1;
    }

    int valor = d->datos[d->front];
    d->front = (d->front + 1) % MAX;
    d->size--;

    printf("DELETE_FRONT: %d\n", valor);
    return valor;
}

int delete_rear(Deque *d) {
    if (isEmpty(d)) {
        printf("ERROR: Deque vacío.\n");
        return -1;
    }

    int rear = rearIndex(d);
    int valor = d->datos[rear];
    d->size--;

    printf("DELETE_REAR: %d\n", valor);
    return valor;
}

void printDeque(Deque *d) {
    printf("Estado del deque (size=%d, front=%d, rear=%d): ",
           d->size, d->front, rearIndex(d));

    if (isEmpty(d)) {
        printf("[vacío]\n");
        return;
    }

    int idx = d->front;
    for (int i = 0; i < d->size; i++) {
        printf("%d ", d->datos[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque d;
    inicializar(&d);

    insert_front(10);
    insert_rear(15);
    insert_rear(20);
    insert_front(30);
    insert_rear(40);

    printDeque(&d);

    delete_front();
    delete_rear();

    printDeque(&d);

    insert_rear(50);
    insert_front(5);

    printDeque(&d);

    return 0;
}
