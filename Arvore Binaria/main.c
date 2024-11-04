#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice {
    int valor;
    struct Vertice* esq;
    struct Vertice* dir;
    struct Vertice* pai;
} Vertice;

typedef struct Arvore {
    Vertice* raiz;
    int qtde;
} Arvore;

void in_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        in_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        in_ordem(raiz->dir);
    }
}

void pre_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

Vertice *cria_vertice(int valor) {
    Vertice* novo = malloc(sizeof(Vertice));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->pai = NULL;
    novo->valor = valor;
    return novo;
}

Arvore *cria_arvore() {
    Arvore* arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    arvore->qtde = 0;
    return arvore;
}

void inserir(Arvore* arvore, int valor) {
    Vertice* novo = cria_vertice(valor); // Crie um novo vértice com o valor recebido por parâmetro
    if (arvore->raiz == NULL) { // Se a árvore for vazia, faça do novo vértice a raíz da árvore
        arvore->raiz = novo;
    } else {
        Vertice* atual = arvore->raiz;
        Vertice* pai = NULL;
        // Percorra os vértices da árvore comparando o valor a ser inserido com o valor do vértice atual
        while (atual != NULL) {
            pai = atual;
            if (valor < atual->valor) { // Se o valor a ser inserido for menor que o valor do nó atual
                atual = atual->esq; // mover para a subárvore esquerda
            } else {
                atual = atual->dir; // caso contrário, mover para a subárvore direita
            }
        }
        // Após o final do percurso, verifique a posição de inserção, a partir do vértice anterior (pai), e insira o novo vértice nesta posição
        novo->pai = pai;
        if (valor < pai->valor) {
            pai->esq = novo;
        } else {
            pai->dir = novo;
        }
    }
    arvore->qtde++;
}

int remover_vertice(Arvore* arvore, Vertice* vertice) {
    // Verifique quantos filhos o vértice a ser removido possui;
    int filhos = (vertice->esq != NULL) + (vertice->dir != NULL);
    
    // Se o vértice não tiver 
    
    ilhos, verifique se ele é a raíz ou filho esquerdo ou direito de seu pai, faça NULL na posição correspondente;
    
   if (filhos == 0) { // Se o vértice não tiver filhos
        if (vertice->pai == NULL) { // Se o vértice for a raiz
            arvore->raiz = NULL;
        } else if (vertice == vertice->pai->esq) { // Se o vértice for filho esquerdo
            vertice->pai->esq = NULL;
        } else { // Se o vértice for filho direito
            vertice->pai->dir = NULL;
        }
    }
    
    //. Se o vértice tiver um filho, faça esse filho ser filho de seu pai considerando se o vértice é filho esquerdo ou direito;
    
    else if(filhos == 1){ //se o vertice tiver um filho
        Vertice* filho;
        if (vertice->esq != NULL) {
            filho = vertice->esq;
        } else {
            filho = vertice->dir;
        }
        
        if(vertice->pai == NULL){
            arvore->raiz = filho;
        }
    }



    
}

int remover_vertice(Arvore* arvore, Vertice* vertice) {
   
}

Vertice *buscar_valor(Arvore* arvore, int valor) {
    Vertice* atual = arvore->raiz;
    while (atual != NULL) {
        if (valor < atual->valor) {
            atual = atual->esq;
        } else if (valor > atual->valor) {
            atual = atual->dir;
        } else {
            return atual;
        }
    }
    return NULL;
}

void liberar_arvore(Vertice* vertice) {
    if (vertice != NULL) {
        liberar_arvore(vertice->esq);
        liberar_arvore(vertice->dir);
        free(vertice);
    }
}

int main(void) {
    int dados[] = {5, 3, 8, 2, 4, 7, 9, 1, 6, 10};
    Arvore *arvore = cria_arvore();

    for (int i = 0; i < 10; i++) {
        inserir(arvore, dados[i]);
        printf("Inseriu %d mostra em ordem -> ", dados[i]);
        in_ordem(arvore->raiz);
        printf("\n");
        printf("Inseriu %d mostra em pré-ordem -> ", dados[i]);
        pre_ordem(arvore->raiz);
        printf("\n");
        printf("Inseriu %d mostra em pós-ordem -> ", dados[i]);
        pos_ordem(arvore->raiz);
        printf("\n");
    }

    for (int i = 0; i < 10; i++) {
        Vertice *vertice = buscar_valor(arvore, dados[i]);
        if (vertice != NULL) {
            remover_vertice(arvore, vertice);
        }
        printf("Removeu %d mostra em ordem -> ", dados[i]);
        in_ordem(arvore->raiz);
        printf("\n");
        printf("Removeu %d mostra em pré-ordem -> ", dados[i]);
        pre_ordem(arvore->raiz);
        printf("\n");
        printf("Removeu %d mostra em pós-ordem -> ", dados[i]);
        pos_ordem(arvore->raiz);
        printf("\n");
    }

    liberar_arvore(arvore->raiz);
    free(arvore);

    return 0;
}