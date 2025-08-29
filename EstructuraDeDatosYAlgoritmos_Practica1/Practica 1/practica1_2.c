#include <stdio.h>

int main(void) {
    int a[100], n, i;
    int suma = 0, resta, min, max, idx_min = 0, idx_max = 0;
    float promedio;

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

    min = max = a[0];
    for (i = 0; i < n; i++) {
        suma += a[i];
        if (a[i] < min) { min = a[i]; idx_min = i; }
        if (a[i] > max) { max = a[i]; idx_max = i; }
    }

    resta = a[n-1];
    for (i = n - 2; i >= 0; i--) {
        resta -= a[i];
    }

    promedio = (float)suma / n;

    printf("\n--- Resultados ---\n");
    printf("Suma = %d\n", suma);
    printf("Resta = %d\n", resta);
    printf("Promedio = %.2f\n", promedio);
    printf("Minimo = %d (indice %d)\n", min, idx_min);
    printf("Maximo = %d (indice %d)\n", max, idx_max);

    return 0;
}
