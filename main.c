#include <stdio.h>

#define N 10  // Número de vértices no grafo

// Função para encontrar o vértice com o maior grau
void encontrarMaiorGrau(int grafo[N][N]) {
    int maxGrau = 0;
    int grau[N] = {0};

    // Calcula o grau de cada vértice
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grau[i] += grafo[i][j];
        }
        if (grau[i] > maxGrau) {
            maxGrau = grau[i];
        }
    }

    printf("--------------------------\n");
    printf("VERTICE(S) COM MAIOR GRAU: \n");
    for (int i = 0; i < N; i++) {
        if (grau[i] == maxGrau) {
            printf("d(%d) = %d\n", i+1, maxGrau);
        }
    }
    printf("--------------------------\n");

}

// Função para encontrar os vértices isolados
void encontrarVerticesIsolados(int grafo[N][N]) {
    printf("VERTICE(S) ISOLADO(S): ");
    for (int i = 0; i < N; i++) {
        int soma = 0;
        for (int j = 0; j < N; j++) {
            soma += grafo[i][j];
        }
        if (soma == 0) {
            printf("%d \n", i+1);
        }
    }
    printf("--------------------------\n");
}

int main() {
    int grafo[N][N];
    FILE *file = fopen("matriz_teste.txt", "r");

    if (file == NULL) {
        printf("Nao foi possível abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(file, "%d", &grafo[i][j]);
        }
    }

    fclose(file);

    // Chama a função para encontrar o vértice com o maior grau
    encontrarMaiorGrau(grafo);

    // Chama a função para encontrar os vértices isolados
    encontrarVerticesIsolados(grafo);

    return 0;
}