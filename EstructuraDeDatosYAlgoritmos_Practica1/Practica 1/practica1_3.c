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
        printf("Elemento %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("Arreglo original:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    printf("Arreglo invertido:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
