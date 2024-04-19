#include <stdio.h>

#define N 10  // Número de vértices no grafo

int main() {
    int grafo[N][N];
    FILE *file = fopen("matriz_teste.txt", "r");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(file, "%d", &grafo[i][j]);
        }
    }

    fclose(file);

    // Imprime a matriz para verificar se a leitura do arquivo está correta
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         printf("%d ", grafo[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}