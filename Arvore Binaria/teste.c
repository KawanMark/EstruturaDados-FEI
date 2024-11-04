#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
	int valor;
	struct Vertice* esq;
	struct Vertice* dir;
	struct Vertice* pai;
} Vertice;

typedef struct Arvore{
	Vertice* raiz;
	int qtde;
} Arvore;

void in_ordem(Vertice *raiz) {
    
}

void pre_ordem(Vertice *raiz) {
    // implementar
}

void pos_ordem(Vertice *raiz) {
    // implementar
}

Vertice *cria_vertice(int valor){
	Vertice* novo = malloc(sizeof(Vertice));
	novo->dir = NULL;
	novo->esq = NULL;
	novo->pai = NULL;
	novo->valor = valor;
	
	return novo;
}

Arvore *cria_arvore(){
	Arvore* arvore = malloc(sizeof(Arvore));
	arvore->raiz = NULL;
	arvore->qtde = 0;

	return arvore;
}

void inserir(Arvore* arvore, int valor){
	// implementar
}

int remover_vertice(Arvore* arvore, Vertice* vertice) {
    // implementar

}

Vertice *buscar_valor(Arvore* arvore, int valor){
	Vertice* atual = arvore->raiz;
	while(atual != NULL){
		if(valor < atual->valor){
			atual = atual->esq;
		}else if(valor > atual->valor){
			atual = atual->dir;
		}else{
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
  	
	for(int i = 0; i < 10; i++){
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

	for(int i = 0; i < 10; i++){
		Vertice *vertice = buscar_valor(arvore, dados[i]);
		if(vertice != NULL){
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
