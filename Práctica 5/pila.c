#include <stdio.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int tope;
} Pila;

void inicializar(Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacía.\n");
}

int estaLlena(Pila *p) {
    return p->tope == MAX - 1;
}

int estaVacia(Pila *p) {
    return p->tope == -1;
}

void push(Pila *p, int valor) {
    if (estaLlena(p)) {
        printf("Error: La pila está llena, no se puede insertar.\n");
        return;
    }
    p->datos[++(p->tope)] = valor;
    printf("PUSH: %d\n", valor);
}

int pop(Pila *p) {
    if (estaVacia(p)) {
        printf("Error: La pila está vacía, no se puede sacar.\n");
        return -1;
    }
    int valor = p->datos[(p->tope)--];
    printf("POP: %d\n", valor);
    return valor;
}

void mostrar(Pila *p) {
    if (estaVacia(p)) {
        printf("Pila vacía.\n");
        return;
    }
    printf("Estado actual de la pila: ");
    for (int i = 0; i <= p->tope; i++) {
        printf("%d ", p->datos[i]);
    }
    printf("\n");
}

int main() {
    Pila p;
    int n, valor;

    inicializar(&p);

    printf("\n¿Cuántos elementos quieres apilar? (max 5): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor a push: ");
        scanf("%d", &valor);
        push(&p, valor);
        mostrar(&p);
    }

    printf("\n¿Cuántos elementos quieres hacer pop?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pop(&p);
        mostrar(&p);
    }

    return 0;
}
