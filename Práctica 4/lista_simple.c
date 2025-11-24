#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i;
    int *arr = NULL;
    int *arr2 = NULL;

    printf("Práctica: Reservar memoria en tiempo de ejecución\n\n");

    printf("Paso 1 - malloc\n");
    printf("¿Cuántos enteros quieres reservar con malloc? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada inválida. Saliendo.\n");
        return 1;
    }

    arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("malloc falló");
        return 1;
    }

    printf("\nValores iniciales en arr (malloc) — pueden ser basura:\n");
    for (i = 0; i < n; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("\nPaso 2 - calloc\n");
    printf("¿Cuántos enteros quieres reservar con calloc? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada inválida. Saliendo.\n");
        free(arr);
        return 1;
    }

    arr2 = (int *) calloc(n, sizeof(int));
    if (arr2 == NULL) {
        perror("calloc falló");
        free(arr);
        return 1;
    }

    printf("\nValores iniciales en arr2 (calloc) — deberían ser 0:\n");
    for (i = 0; i < n; ++i) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    printf("\nPaso 3 - Llenar arr2\n");
    printf("Introduce %d valores enteros para arr2:\n", n);
    for (i = 0; i < n; ++i) {
        printf("valor para arr2[%d]: ", i);
        if (scanf("%d", &arr2[i]) != 1) {
            printf("Entrada inválida. Liberando memoria y saliendo.\n");
            free(arr);
            free(arr2);
            return 1;
        }
    }

    printf("\nContenido actual de arr2:\n");
    for (i = 0; i < n; ++i) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    printf("\nPaso 4 - realloc\n");
    int m;
    printf("¿A qué nuevo tamaño quieres cambiar arr2? (nuevo número de enteros): ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Entrada inválida. Liberando memoria y saliendo.\n");
        free(arr);
        free(arr2);
        return 1;
    }

    int old_n = n;
    n = m;
    int *tmp = (int *) realloc(arr2, n * sizeof(int));
    if (tmp == NULL) {
        perror("realloc falló");
        free(arr);
        free(arr2);
        return 1;
    }
    arr2 = tmp;

    if (n > old_n) {
        printf("\nEl nuevo tamaño es mayor. Introduce %d valores adicionales:\n", n - old_n);
        for (i = old_n; i < n; ++i) {
            printf("valor para arr2[%d]: ", i);
            if (scanf("%d", &arr2[i]) != 1) {
                printf("Entrada inválida. Liberando memoria y saliendo.\n");
                free(arr);
                free(arr2);
                return 1;
            }
        }
    } else if (n < old_n) {
        printf("\nEl nuevo tamaño es menor. Se han perdido los elementos con índice >= %d\n", n);
    } else {
        printf("\nEl tamaño no cambió.\n");
    }

    printf("\nContenido final de arr2 (después de realloc):\n");
    for (i = 0; i < n; ++i) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    free(arr);
    free(arr2);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
