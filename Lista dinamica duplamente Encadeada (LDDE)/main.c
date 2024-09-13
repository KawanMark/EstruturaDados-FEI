#include <stdlib.h>
#include <stdio.h>

typedef struct Celula{
    struct Celula *anterior;
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct{
    Celula *primeiro;
    int qtde;
} Lista;

Celula *criar_celula(int valor){
    Celula *celula = malloc(sizeof(Celula));
    celula->anterior = NULL;
    celula->valor = valor;
    celula->proximo = NULL;
    return celula;
}

Lista *criar_lista(){
    Lista *lista = malloc(sizeof(Lista));
    lista->primeiro = NULL;
    lista->qtde = 0;
    return lista;
}

void inserir(Lista *lista, int valor){
    Celula *novo = criar_celula(valor);
    //insere no inicio	vazia
    if(lista->primeiro == NULL){
        lista->primeiro = novo;
    } else{
        Celula *atual = lista->primeiro;
        Celula *anterior = NULL;

        while(atual != NULL && atual->valor <= novo->valor){
            anterior = atual;
            atual = atual->proximo;
        } 
        //insercao no inicio da lista
        if(anterior == NULL){
            lista->primeiro = novo;
            novo->proximo = atual;
            atual->anterior = novo;
        }
        //insercao no final da lista
        else if(atual == NULL){
            anterior->proximo = novo;
            novo->anterior = anterior;
        }
        //insercao no meio
        else{
            anterior-> proximo = novo;
            novo->anterior = anterior;
            atual->anterior = novo;
            novo->proximo = atual;
        }
    }
    lista->qtde++;
}

void mostrar(Lista *lista){
    Celula *atual = lista->primeiro;
    printf("Inicio -> ");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("<- Final\n");
}

int main(void) {
    
    Lista *lista = criar_lista();
    for(int i = 0; i < 20; i++){
        inserir(lista, i);
        mostrar(lista);
    }

    

    return 0;
}