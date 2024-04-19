#include <stdio.h>
#include <stdlib.h>

#define MAX 3633

int grafo[MAX][MAX];

void lerGrafo() {
    FILE *file = fopen("dados_matriz.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for(int i=0; i<MAX; i++) {
        for(int j=0; j<MAX; j++) {
            if (fscanf(file, "%d", &grafo[i][j]) != 1) {
                printf("Erro ao ler os dados na linha %d, coluna %d\n", i+1, j+1);
                return;
            }
        }
    }
    fclose(file);
}