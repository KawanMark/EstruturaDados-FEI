#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó na lista duplamente encadeada
typedef struct no {
    int valor;
    struct no *anterior;
    struct no *proximo;
} No;

// Definição da estrutura da lista duplamente encadeada
typedef struct lista_duplamente_encadeada {
    int quantidade;
    No *inicio;
} ListaDuplamenteEncadeada;

/**
 * Cria uma nova lista duplamente encadeada e a inicializa.
 *
 * @return Um ponteiro para a nova lista criada.
 */
ListaDuplamenteEncadeada *criar_lista() {
    ListaDuplamenteEncadeada *lista = malloc(sizeof(ListaDuplamenteEncadeada));
    lista->inicio = NULL;
    lista->quantidade = 0;
    return lista;
}

/**
 * Cria um novo nó contendo o valor especificado.
 *
 * @param valor O valor a ser armazenado no nó.
 * @return Um ponteiro para o novo nó criado.
 */
No *criar_no(int valor) {
    No *novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->anterior = NULL;
    novo_no->proximo = NULL;
    return novo_no;
}

/**
 * Insere um valor na lista de forma ordenada.
 *
 * @param lista Ponteiro para a lista onde o valor será inserido.
 * @param valor O valor a ser inserido na lista.
 */
void inserir_valor(ListaDuplamenteEncadeada *lista, int valor) {
     No *novo = criar_no(valor);
    //insere no inicio	vazia
    if(lista->inicio == NULL){
        lista->inicio = novo;
    } else{
        No *atual = lista->inicio;
        No *anterior = NULL;

        while(atual != NULL && atual->valor <= novo->valor){
            anterior = atual;
            atual = atual->proximo;
        } 
        //insercao no inicio da lista
        if(anterior == NULL){
            lista->inicio = novo;
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
    lista->quantidade++;
}

/**
 * Exibe os valores da lista em ordem crescente.
 *
 * @param lista Ponteiro para a lista a ser exibida.
 */

//Primeiro = Inicio
//No = celula

void exibir_lista(ListaDuplamenteEncadeada *lista) {
    No *atual = lista->inicio;
    printf("Início -> ");
    //enquanto o atual nao for nulo
    while(atual != NULL){
        //imprime o valor do no
        printf("%d ", atual->valor);
        //atualiza o no atual para o proximo
        atual = atual->proximo;
    }
    //imprime o final po.
    printf("<- Final\n");
}

/**
 * Exibe os valores da lista em ordem decrescente.
 *
 * @param lista Ponteiro para a lista a ser exibida.
 */
void exibir_lista_invertida(ListaDuplamenteEncadeada *lista) {
    
    No *atual = lista->inicio;
    printf("Final -> ");
    //aq podemos indicar que ainda ha um proximo no
    while(atual != NULL && atual->proximo != NULL){
        //atualiza o no atual para o proximo ok
        atual = atual->proximo;
    }
    while(atual != NULL){
        
        printf("%d ", atual->valor);
        //atualiza para o no anterior 
        atual = atual->anterior;
    }
    printf("<- Início\n");
}

/**
 * Remove o nó que contém o valor especificado da lista.
 *
 * @param lista Ponteiro para a lista de onde o valor será removido.
 * @param valor O valor a ser removido da lista.
 */

// NO = CELULA
void remover_valor(ListaDuplamenteEncadeada *lista, int valor) {

    No *atual = lista-> inicio;
    No *anterior = NULL;
    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->proximo;
    }

    if(anterior == NULL && atual != NULL){
        lista->inicio = atual->proximo;
        if(atual->proximo != NULL){
            atual->proximo->anterior = NULL;
        }
    }
    
    else if(atual != NULL && atual-> proximo == NULL){
        anterior->proximo = NULL;
    } 

    else if(atual != NULL){
        anterior->proximo = atual->proximo;
        atual->proximo->anterior = anterior;
    }

    free(atual);

}

int main(void) {
    ListaDuplamenteEncadeada *lista = criar_lista();

    inserir_valor(lista, 10);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 5);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 20);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 15);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 5);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 15);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 20);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 10);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    for (int i = 1; i <= 10; i++) {
        inserir_valor(lista, i);
    }
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    for (int i = 1; i <= 10; i++) {
        remover_valor(lista, i);
    }
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 100);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 10);
    inserir_valor(lista, 10);
    inserir_valor(lista, 10);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    return 0;
}
