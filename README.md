# Projeto de Grafos - Laboratório de Algoritmos e Estruturas de Dados II

Este projeto foi desenvolvido como parte da avaliação para a 3ª unidade da disciplina Laboratório de Algoritmos e Estruturas de Dados II. O projeto envolve a manipulação de grafos representados como matrizes de adjacência.

## Funcionalidades

O projeto inclui as seguintes funcionalidades:

1. **Leitura de Grafos**: Lê um grafo de um arquivo chamado 'dados_matriz.txt'. O grafo é representado como uma matriz de adjacência em um arquivo de texto, onde cada linha do arquivo representa uma linha da matriz.

2. **Cálculo do Grau dos Vértices**: Calcula o grau de cada vértice do grafo e escreve os resultados em um arquivo chamado 'dados_grafos_graus.txt'.

3. **Identificação de Vértices Isolados**: Identifica os vértices isolados no grafo.

4. **Identificação de Vértices Sumidouros**: Identifica os vértices sumidouros no grafo.

5. **Identificação de Vértices Fonte**: Identifica os vértices fonte no grafo.

6. **Verificação de Conexão entre Vértices**: Verifica se o primeiro e o último vértice estão conectados.

7. **Criação do Grafo Complementar**: Cria o grafo complementar do grafo original e escreve a matriz de adjacência do grafo complementar em um arquivo chamado 'dados_grafo_complementar.txt'.

8. **Inversão de Arestas**: Inverte todas as arestas do grafo original e escreve a matriz de adjacência do grafo invertido em um arquivo chamado 'dados_grafo_invertido.txt'.

9. **Criação de Subgrafo**: Cria um subgrafo contendo apenas os vértices que são múltiplos de 5 e escreve a matriz de adjacência do subgrafo em um arquivo chamado 'dados_grafo_gerador.txt'.

## Como Executar

Para compilar o código, use o seguinte comando:

```
gcc -o main main.c
```

Para executar o programa, use o seguinte comando:

```
./main
```