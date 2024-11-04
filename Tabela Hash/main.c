#include <stdio.h>
#include <stdlib.h>

#define tam_hash 11

typedef struct Celula {
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct Lista {
    int qtde;
    Celula *primeiro;
} Lista;

typedef struct {
    Lista* tabela;
} Hash;

/**
 * @brief Insere um valor na lista de forma ordenada.
 *
 * @param l Ponteiro para a lista onde o valor será inserido.
 * @param valor O valor inteiro a ser inserido na lista.
 */
void inserir(Lista *l, int valor) {
    Celula *novo = malloc(sizeof(Celula));
    novo->proximo = NULL;
    novo->valor = valor;
    
    if(l->qtde == 0){
        l->primeiro = novo;
    } else{
        Celula *atual = l->primeiro;
        Celula *anterior = NULL;
        while(atual != NULL && atual->valor <= novo-> valor){
            anterior = atual;
            atual = atual->proximo;
        }
        if(anterior == NULL){
            novo->proximo = atual;
            l->primeiro = novo;
        }else if(atual == NULL){
            anterior->proximo = novo;
        } else{
            anterior->proximo = novo;
            novo->proximo = atual;
        }
    }
    l->qtde++;
}

/**
 * @brief Remove um valor da lista, se ele estiver presente.
 *
 * @param l Ponteiro para a lista de onde o valor será removido.
 * @param valor O valor inteiro a ser removido da lista.
 */
void remover(Lista *lista, int valor) {
  Celula *atual = lista->primeiro;
  Celula *anterior = NULL;
  while(atual != NULL && atual->valor != valor){
    anterior = atual;
    atual = atual->proximo;
  }
  if(anterior == NULL){
    lista->primeiro = atual->proximo;
  }
  else if(atual == NULL){
    anterior->proximo = NULL;
  }
  else{
    anterior->proximo = atual->proximo;
  }
  free(atual);
  lista->qtde--;
}

/**
 * @brief Inicializa uma nova lista vazia.
 *
 * @return Ponteiro para a nova lista inicializada.
 */
Lista *inicializa_lista() {
  Lista *lista = malloc(sizeof(Lista));
  lista->primeiro = NULL;
  lista->qtde =  0;
  return lista;
}

/**
 * @brief Inicializa uma nova tabela hash.
 *
 * @return Ponteiro para a nova tabela hash inicializada.
 */
Hash* start_hash() {
    Hash* hash = (Hash*)malloc(sizeof(Hash));
    hash->tabela = (Lista*)malloc(tam_hash * sizeof(Lista));
    for (int i = 0; i < tam_hash; i++) {
        hash->tabela[i] = *inicializa_lista();
    }
    return hash;
}

/**
 * @brief Calcula o índice da tabela hash para um dado valor.
 *
 * @param valor O valor inteiro para o qual calcular o índice.
 * @return O índice calculado.
 */
int hashing(int valor) {
    return valor % tam_hash;
}

/**
 * @brief Insere um valor na tabela hash.
 *
 * @param hash Ponteiro para a tabela hash onde o valor será inserido.
 * @param valor O valor inteiro a ser inserido na tabela hash.
 */
void inserir_hash(Hash* hash, int valor) {
    int indice = hashing(valor);
    inserir(&hash->tabela[indice], valor);
}

/**
 * @brief Remove um valor da tabela hash.
 *
 * @param hash Ponteiro para a tabela hash de onde o valor será removido.
 * @param valor O valor inteiro a ser removido da tabela hash.
 */
void remover_hash(Hash* hash, int valor) {
    int indice = hashing(valor);
    remover(&hash->tabela[indice], valor);
}

/**
 * @brief Imprime todos os valores da tabela hash.
 *
 * @param hash Ponteiro para a tabela hash a ser impressa.
 */
void imprimir(Hash* hash) {
    printf("---------------------\n");
    for (int i = 0; i < tam_hash; i++) {
        printf("%d -> ", i);
        Celula* atual = hash->tabela[i].primeiro;
        while (atual != NULL) {
            printf("%d ", atual->valor);
            atual = atual->proximo;
        }
        printf("\n");
    }
    printf("---------------------\n");
}

int main(void) {
    Hash* hash = start_hash();
    int valor;
    while (1) {
        scanf("%d", &valor);
        if (valor == 0)
            break;
        inserir_hash(hash, valor);
    }
    imprimir(hash);
    while (1) {
        scanf("%d", &valor);
        if (valor == 0)
            break;
        remover_hash(hash, valor);
    }
    imprimir(hash);
    return 0;
}