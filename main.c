#include <stdio.h>
#include <stdlib.h>

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
    printf("VERTICE(S) ISOLADO(S): \n");
    for (int i = 0; i < N; i++) {
        int somaLinha = 0;
        int somaColuna = 0;
        for (int j = 0; j < N; j++) {
            somaLinha += grafo[i][j];
            somaColuna += grafo[j][i];
        }
        if (somaLinha == 0 && somaColuna == 0) {
            printf("%d \n", i+1);
        }
    }
    printf("--------------------------\n");
}

// Função para encontrar o vértice sumidouro
void encontrarVerticeSumidouro(int grafo[N][N]) {
    printf("VERTICE(S) SUMIDOURO(S): \n");
    for (int i = 0; i < N; i++) {
        int somaLinha = 0;
        int somaColuna = 0;
        for (int j = 0; j < N; j++) {
            somaLinha += grafo[i][j];
            somaColuna += grafo[j][i];
        }
        if (somaLinha == 0 && somaColuna != 0) {
            printf("%d \n", i+1);
        }
    }
    printf("--------------------------\n");
}

// Função para encontrar o vértice fonte
void encontrarVerticeFonte(int grafo[N][N]) {
    printf("VERTICE(S) FONTE(S): \n");
    for (int j = 0; j < N; j++) {
        int somaColuna = 0;
        int somaLinha = 0;
        for (int i = 0; i < N; i++) {
            somaColuna += grafo[i][j];
            somaLinha += grafo[j][i];
        }
        if (somaColuna == 0 && somaLinha != 0) {
            printf("%d \n", j+1);
        }
    }
    printf("---------------------------------------------------\n");
}

// Função para verificar se o primeiro e o último vértice estão conectados
void verificarConexao(int grafo[N][N]) {
    if (grafo[0][N-1] == 1 || grafo[N-1][0] == 1) {
        printf("O primeiro e o ultimo vertice estao conectados.\n");
        printf("---------------------------------------------------\n");

    } else {
        printf("O primeiro e o ultimo vertice NAO estao conectados.\n");
        printf("---------------------------------------------------\n");
    }
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

    encontrarMaiorGrau(grafo);
    encontrarVerticesIsolados(grafo);
    encontrarVerticeSumidouro(grafo);
    encontrarVerticeFonte(grafo);
    verificarConexao(grafo);

    return 0;
}