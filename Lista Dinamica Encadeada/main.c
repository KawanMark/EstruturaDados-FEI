#include <stdlib.h>
#include <stdio.h>

typedef struct Celula {
  int valor;
  struct Celula *proximo;
} Celula;

typedef struct{
  Celula *primeira;
  int qtde;
} Lista;

Lista *inicializa_lista(){
  Lista *lista = malloc(sizeof(Lista));
  lista->primeira = NULL;
  lista->qtde =  0;
  return lista;
}

Celula *inicializa_celula(int valor){
  Celula *celula = malloc(sizeof(Celula)); 
  celula -> proximo = NULL;
  celula -> valor = valor;
  return celula;
}

Celula *busca(Lista *lista, int valor){
  Celula *atual = lista -> primeira;
  while(atual != NULL){
    if(atual -> valor == valor){
      return atual;
    }
    atual = atual -> proximo;
  }
}




void inserir(Lista *lista, int valor){
  Celula *nova = inicializa_celula(valor);
  Celula *atual = lista -> primeira;
  Celula *anterior = NULL;

  if(valor % 2 != 0){
    while (atual != NULL && atual->valor % 2 != 0 &&       nova->valor >= atual->valor){
      anterior = atual;
      atual = atual -> proximo;
    }
  } else{
    while (atual != NULL && (atual->valor % 2 == 0 && nova->valor <= atual->valor || atual->valor % 2 != 0)){
      anterior = atual;
      atual = atual -> proximo;
    }
  }
  
  if(lista -> qtde == 0){
    lista -> primeira = nova;
    lista->qtde++;
  } else{
    while(atual != NULL && nova->valor >= atual->valor){
      anterior = atual;
      atual = atual->proximo;
    }
    if(anterior == NULL){
      nova->proximo = lista->primeira;
      lista->primeira = nova;
      lista->qtde++;
    } else{
      if(atual == NULL){
        anterior->proximo = nova;
        lista->qtde++;
      }else{
        anterior->proximo = nova;
        nova->proximo = atual;
        lista->qtde++;
      }
    }
  }
}

void mostrar(Lista *lista){
  Celula *atual = lista->primeira;
  while(atual != NULL){
    printf("%d ", atual->valor); 
    atual = atual->proximo;
  }
  printf("\n");
}


void remover(Lista *lista, int valor){
  Celula *atual = lista->primeira;
  Celula *anterior = NULL;
  while(atual != NULL && atual->valor != valor){
    anterior = atual;
    atual = atual->proximo;
  }
  if(anterior == NULL){
    lista->primeira = atual->proximo;
  }
  else if(atual == NULL){
    anterior->proximo = NULL;
  }
  else{
    anterior->proximo = atual->proximo;
  }
 
  
}

int main(void) {
    Lista *l = inicializa_lista();
    int valores[] = {2, 1, 0, 9, 3, 8, 5, 7, 6, 4};

    // Inserção
    for (int i = 0; i < 10; i++) {
        inserir(l, valores[i]);
        mostrar(l);
    }

    // Remoção
    for (int i = 0; i < 10; i++) {
        remover(l, valores[i]);
        mostrar(l);
    }

    free(l); // Liberar memória alocada para a lista
    return 0;
}