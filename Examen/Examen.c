#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    float *califs = NULL;
    int i;
    int agregar;
    int total_est;
    float suma = 0.0f;
    float promedio;

    printf("¿Cuántos estudiantes deseas registrar? ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Entrada inválida. Saliendo.
");
        return EXIT_FAILURE;
    }

    if (n <= 0) {
        printf("No se registrarán estudiantes. Fin del programa.
");
        return EXIT_SUCCESS;
    }

    califs = (float *) malloc(n * sizeof(float));
    if (califs == NULL) {
        fprintf(stderr, "Error: malloc devolvió NULL. No hay memoria suficiente.
");
        return EXIT_FAILURE;
    }

    for (i = 0; i < n; ++i) {
        printf("Calificación del estudiante %d: ", i + 1);
        if (scanf("%f", &califs[i]) != 1) {
            fprintf(stderr, "Entrada inválida. Liberando memoria y saliendo.
");
            free(califs);
            return EXIT_FAILURE;
        }
    }

    suma = 0.0f;
    for (i = 0; i < n; ++i) suma += califs[i];
    promedio = suma / n;
    printf("\nPromedio inicial: %.2f\n\n", promedio);

    printf("¿Deseas agregar más estudiantes? (cantidad, 0 para no): ");
    if (scanf("%d", &agregar) != 1) {
        fprintf(stderr, "Entrada inválida. Liberando memoria y saliendo.
");
        free(califs);
        return EXIT_FAILURE;
    }

    if (agregar < 0) {
        printf("Cantidad inválida. Se toma como 0.\n");
        agregar = 0;
    }

    if (agregar > 0) {
        int nuevo_tamano = n + agregar;
        float *tmp = (float *) realloc(califs, nuevo_tamano * sizeof(float));
        if (tmp == NULL) {
            fprintf(stderr, "Error: realloc devolvió NULL. No se pudo ampliar el arreglo.\n");
            free(califs);
            return EXIT_FAILURE;
        }
        califs = tmp;

        for (i = n; i < nuevo_tamano; ++i) {
            printf("Calificación del estudiante %d: ", i + 1);
            if (scanf("%f", &califs[i]) != 1) {
                fprintf(stderr, "Entrada inválida durante captura. Liberando memoria y saliendo.\n");
                free(califs);
                return EXIT_FAILURE;
            }
        }

        suma = 0.0f;
        for (i = 0; i < nuevo_tamano; ++i) suma += califs[i];
        promedio = suma / nuevo_tamano;
        total_est = nuevo_tamano;
    } else {
        total_est = n;
        suma = 0.0f;
        for (i = 0; i < total_est; ++i) suma += califs[i];
        promedio = suma / total_est;
    }

    printf("\n=== Calificaciones registradas ===\n\n");
    for (i = 0; i < total_est; ++i) {
        printf("Estudiante %d: %.2f\n\n", i + 1, califs[i]);
    }
    printf("Promedio general: %.2f\n\n", promedio);

    free(califs);
    califs = NULL;
    printf("Memoria liberada correctamente.\n");

    return EXIT_SUCCESS;
}
