/*Plano em Pseudocódigo
Definir a estrutura de um nó da lista duplamente encadeada (LDE).
Definir a estrutura da tabela hash, que é um array de ponteiros para LDE.
Inicializar a tabela hash com listas vazias.
Implementar a função de hash usando o método da divisão.
Implementar a função para inserir um valor na tabela hash.
Implementar a função para remover um valor da tabela hash.
Implementar a função para imprimir a tabela hash (para fins de depuração).*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 15 // Tamanho da tabela hash

// Estrutura de um nó da lista duplamente encadeada
typedef struct No {
    int dado;
    struct No* proximo;
    struct No* anterior;
} No;

// Estrutura da tabela hash
typedef struct TabelaHash {
    No* tabela[TAM];
} TabelaHash;

// Função para criar um novo nó
No* criarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;
    return novoNo;
}

// Função de hash (método da divisão)
int funcaoHash(int chave) {
    return chave % TAM;
}

// Função para inicializar a tabela hash
void inicializarTabelaHash(TabelaHash* th) {
    for (int i = 0; i < TAM; i++) {
        th->tabela[i] = NULL;
    }
}

// Função para inserir um valor na tabela hash
void inserir(TabelaHash* th, int dado) {
    int indice = funcaoHash(dado);
    No* novoNo = criarNo(dado);
    if (th->tabela[indice] == NULL) {
        th->tabela[indice] = novoNo;
    } else {
        No* temp = th->tabela[indice];
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
        novoNo->anterior = temp;
    }
}

// Função para remover um valor da tabela hash
void remover(TabelaHash* th, int dado) {
    int indice = funcaoHash(dado);
    No* temp = th->tabela[indice];
    while (temp != NULL && temp->dado != dado) {
        temp = temp->proximo;
    }
    if (temp == NULL) {
        printf("Valor %d não encontrado na tabela hash.\n", dado);
        return;
    }
    if (temp->anterior != NULL) {
        temp->anterior->proximo = temp->proximo;
    } else {
        th->tabela[indice] = temp->proximo;
    }
    if (temp->proximo != NULL) {
        temp->proximo->anterior = temp->anterior;
    }
    free(temp);
}

// Função para imprimir a tabela hash
void imprimirTabelaHash(TabelaHash* th) {
    for (int i = 0; i < TAM; i++) {
        printf("Índice %d: ", i);
        No* temp = th->tabela[i];
        while (temp != NULL) {
            printf("%d -> ", temp->dado);
            temp = temp->proximo;
        }
        printf("NULL\n");
    }
}

int main() {
    TabelaHash th;
    inicializarTabelaHash(&th);

    int valores[] = {190, 322, 172, 89, 13, 4, 769, 61, 15, 76, 97, 28, 80, 76, 88};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        inserir(&th, valores[i]);
    }

    printf("Tabela Hash após inserções:\n");
    imprimirTabelaHash(&th);

    remover(&th, 76);
    printf("\nTabela Hash após remover 76:\n");
    imprimirTabelaHash(&th);

    return 0;
}