#include <stdio.h>

int main(void) {
    int a[100], n, i;

    printf("Ingresa una cantidad (entre 1 y 100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Error: la cantidad debe estar entre 1 y 100.\n");
        return 1;
    }

    printf("Ingrese %d numeros:\n", n);
    for (i = 0; i < n; i++) {
        do {
            printf("Elemento %d: ", i);
            scanf("%d", &a[i]);
            if (a[i] < 0) {
                printf("Error: no se permiten numeros negativos.\n");
            }
        } while (a[i] < 0);
    }

    printf("Arreglo ingresado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
