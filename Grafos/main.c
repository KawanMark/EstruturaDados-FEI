#include <stdio.h>

#define V 6  // Número de vértices
#define E 12 // Número de arestas

// Função para obter o índice de um vértice a partir de um caractere
int get_index(char x) {
    return x - 97; // 'a' -> 0, 'b' -> 1, etc.
}

// Função para inicializar a matriz de adjacência
void inicia_arestas(int arestas[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            arestas[i][j] = 0; // Inicializa todas as arestas como 0 (sem conexão)
        }
    }
}

// Função para criar uma aresta entre dois vértices
void cria_arestas(int arestas[V][V], int v, int u) {
    arestas[v][u] = 1; // Define a aresta de v para u como 1 (conectado)
}

// Função para mostrar a matriz de adjacência
void mostra_arestas(int arestas[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", arestas[i][j]); // Imprime o valor da aresta
        }
        printf("\n");
    }
}

// Função para mostrar os vértices adjacentes a um dado vértice (a ser implementada)
void mostra_adjacentes(int arestas[V][V], char v) {
    int index = get_index(v);
    printf("Vértices adjacentes a %c: ", v);
    for (int i = 0; i < V; i++) {
        if (arestas[index][i] == 1) {
            printf("%c ", i + 97); // Converte o índice de volta para caractere
        }
    }
    printf("\n");
}

// Função para mostrar as distâncias dos vértices a partir de um dado vértice (a ser implementada)
void mostra_distancias(int arestas[V][V], char v) {
    int index = get_index(v);
    int distancias[V];
    int visitado[V] = {0};

    // Inicializa as distâncias
    for (int i = 0; i < V; i++) {
        distancias[i] = (arestas[index][i] == 1) ? 1 : -1;
    }
    distancias[index] = 0;
    visitado[index] = 1;

    // Calcula as distâncias
    for (int i = 0; i < V; i++) {
        if (distancias[i] == 1) {
            for (int j = 0; j < V; j++) {
                if (arestas[i][j] == 1 && !visitado[j]) {
                    distancias[j] = distancias[i] + 1;
                    visitado[j] = 1;
                }
            }
        }
    }

    // Imprime as distâncias
    printf("Distâncias a partir de %c:\n", v);
    for (int i = 0; i < V; i++) {
        printf("Distância até %c: %d\n", i + 97, distancias[i]);
    }
}