#include <stdio.h>
#include <string.h>

#define TAM 2       // Número de películas
#define NUM_DIR 2   // Número máximo de directores por película

struct pelicula {
    char nombre[20];
    char genero[20];
    int anio;
    int numDirectores;
    char directores[NUM_DIR][20];
};

int main() {
    struct pelicula videoteca[TAM];

    for (int i = 0; i < TAM; i++) {
        printf("Ingrese nombre de la película %d: ", i + 1);
        scanf(" %[^\n]", videoteca[i].nombre);

        printf("Ingrese género: ");
        scanf(" %[^\n]", videoteca[i].genero);

        printf("Ingrese año: ");
        scanf("%d", &videoteca[i].anio);

        printf("Ingrese número de directores (máximo %d): ", NUM_DIR);
        scanf("%d", &videoteca[i].numDirectores);

        if (videoteca[i].numDirectores <= 0 || videoteca[i].numDirectores > NUM_DIR) {
            printf("Número de directores inválido. Saliendo...\n");
            return 1;
        }

        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("Ingrese nombre del director %d: ", j + 1);
            scanf(" %[^\n]", videoteca[i].directores[j]);
        }
        printf("\n");
    }

    if (TAM <= 0) {
        printf("Cantidad de películas inválida.\n");
        return 1;
    }

    printf("\n--- Videoteca en orden inverso ---\n");
    for (int i = TAM - 1; i >= 0; i--) {
        printf("Película: %s\n", videoteca[i].nombre);
        printf("Género: %s\n", videoteca[i].genero);
        printf("Año: %d\n", videoteca[i].anio);
        printf("Directores (%d):\n", videoteca[i].numDirectores);
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("  - %s\n", videoteca[i].directores[j]);
        }
        printf("\n");
    }

    char criterio[20];
    int opcion;
    printf("Buscar por: 1) Nombre 2) Año 3) Director: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese nombre a buscar: ");
        scanf(" %[^\n]", criterio);
        for (int i = 0; i < TAM; i++) {
            if (strcmp(videoteca[i].nombre, criterio) == 0) {
                printf("Película encontrada: %s (%d)\n", videoteca[i].nombre, videoteca[i].anio);
            }
        }
    } else if (opcion == 2) {
        int anioBuscado;
        printf("Ingrese año a buscar: ");
        scanf("%d", &anioBuscado);
        for (int i = 0; i < TAM; i++) {
            if (videoteca[i].anio == anioBuscado) {
                printf("Película del año %d: %s\n", anioBuscado, videoteca[i].nombre);
            }
        }
    } else if (opcion == 3) {
        printf("Ingrese nombre del director a buscar: ");
        scanf(" %[^\n]", criterio);
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < videoteca[i].numDirectores; j++) {
                if (strcmp(videoteca[i].directores[j], criterio) == 0) {
                    printf("Película dirigida por %s: %s\n", criterio, videoteca[i].nombre);
                }
            }
        }
    }

    char generoBuscado[20];
    int contador = 0;
    printf("Ingrese género para contar: ");
    scanf(" %[^\n]", generoBuscado);
    for (int i = 0; i < TAM; i++) {
        if (strcmp(videoteca[i].genero, generoBuscado) == 0) {
            contador++;
        }
    }
    printf("Hay %d película(s) del género %s.\n", contador, generoBuscado);

    return 0;
}
