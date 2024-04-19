#include <stdio.h>
#include <stdlib.h>

#define N 3633  // Número de vértices no grafo

// Função para encontrar o vértice com o maior grau
void encontrarMaiorGrau(int** grafo) {
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
void encontrarVerticesIsolados(int** grafo) {
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
void encontrarVerticeSumidouro(int** grafo) {
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
void encontrarVerticeFonte(int** grafo) {
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
void verificarConexao(int** grafo) {
    if (grafo[0][N-1] == 1 || grafo[N-1][0] == 1) {
        printf("O primeiro e o ultimo vertice estao conectados.\n");
        printf("---------------------------------------------------\n");

    } else {
        printf("O primeiro e o ultimo vertice NAO estao conectados.\n");
        printf("---------------------------------------------------\n");
    }
}

// Função para escrever o grau de cada vértice em um arquivo
void escreverGraus(int** grafo) {
    FILE *file = fopen("dados_grafos_graus.txt", "w");

    if (file == NULL) {
        printf("Nao foi possível abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        int grau = 0;
        for (int j = 0; j < N; j++) {
            grau += grafo[i][j];
        }
        fprintf(file, "d(%d) = %d\n", i+1, grau);
    }

    fclose(file);
}

int main() {
    // Aloca a matriz dinamicamente
    int** grafo = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        grafo[i] = (int*)malloc(N * sizeof(int));
    }

    FILE *file = fopen("dados_matriz.txt", "r");

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

    // Chama a função para escrever o grau de cada vértice em um arquivo
    escreverGraus(grafo);

    // Libera a memória alocada para a matriz
    for (int i = 0; i < N; i++) {
        free(grafo[i]);
    }
    free(grafo);

    return 0;
}