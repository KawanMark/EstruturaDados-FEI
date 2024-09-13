#include <stdio.h>

#define TAM 10

typedef struct{
  int valores[TAM];
  int n;
}Lista;

int esta_cheia(Lista *lista){
  return lista->n == TAM;
}

int esta_vazia(Lista *lista){
  return lista->n == 0;
}

int encontrar_posicao(Lista *lista, int valor){
  for(int i = 0; i < lista->n; i++){
    if(lista->valores[i] == valor){
      return i;
    }
  }
  return -1;
}

void deslocar_direita(Lista *lista, int indice){
  for(int i = lista->n; i > indice; i--){
    lista->valores[i] = lista->valores[i-1];
  }
}

void deslocar_esquerda(Lista *lista, int indice){
  for(int i = indice; i < lista->n-1; i++){
    lista->valores[i] = lista->valores[i+1];
  }
}

int inserir(Lista *lista, int valor){
  if(esta_cheia(lista)){
    return 0;
  }
  int i = 0;
  while(i < lista->n && valor >= lista->valores[i]){
    i++;
  }
  deslocar_direita(lista, i);
  lista->valores[i] = valor;
  lista->n++;
  return 1;

}


int remover(Lista *lista, int valor){
  int idx = encontrar_posicao(lista, valor);
  if (idx >=0){
    deslocar_esquerda(lista, idx);
    lista->n--;
    return valor;
  }

  return -1;
  
}



void exibir_lista(Lista *lista){
  for(int i = 0; i < lista->n; i++)
    printf("%d ", lista->valores[i]);

  printf("\n");
}




int main(void) {

  Lista lista = { .n = 0};
  Lista *pl = &lista;
  int valores[] = {21, 14, 13, 10, 87, 35, 27, 56, 85, 29};

  for(int i = 0 ; 
  i < TAM ; i++){
    inserir(pl, valores[i]);
    exibir_lista(pl);
  }

  for(int i = 0; i < TAM; i++){
    printf("O valor %d está na posição %d\n", valores[i], encontrar_posicao(pl, valores[i]));
  }

  for(int i = 0; i < TAM; i++){
    remover(pl, valores[i]);
    exibir_lista(pl);
  }
  
  return 0;
}