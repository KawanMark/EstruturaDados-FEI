#include <stdio.h>

#define TAM 10

typedef struct{ // aqui vamos criar a estrutura da lista
  int valores[TAM]; // aqui vamos criar um array de inteiros com o tamanho da capacidade
  int n; // aqui vamos criar a quantidade de elementos na lista
}Lista; // aqui vamos criar o nome da estrutura

int esta_cheia(Lista *lista){ //aqui vamos verificar se a lista esta cheia
  return lista->n == TAM; // aqui vamos retornar se a quantidade de elementos na lista for igual a capacidade da lista
}

int esta_vazia(Lista *lista){ //aqui vamos verificar se a lista esta vazia
  return lista->n == 0; // aqui vamos retornar se a quantidade de elementos na lista for igual a zero
}

int encontrar_posicao(Lista *lista, int valor){ // aqui vamos encontrar a posição do valor
  for(int i = 0; i < lista->n; i++){ // aqui vamos iterar sobre a lista
    if(lista->valores[i] == valor){ // aqui vamos verificar se o valor na posição i é igual ao valor
      return i; // aqui vamos retornar a posição do valor
    }
  }
  return -1; // aqui vamos retornar -1 se não encontrar o valor
}

void deslocar_direita(Lista *lista, int indice){ // aqui vamos deslocar para a direita
  for(int i = lista->n; i > indice; i--){ // aqui vamos iterar sobre a lista 
    lista->valores[i] = lista->valores[i-1]; // aqui vamos deslocar para a direita
  }
}

void deslocar_esquerda(Lista *lista, int indice){ // aqui vamos deslocar para a esquerda 
  for(int i = indice; i < lista->n-1; i++){ // aqui vamos iterar sobre a lista
    lista->valores[i] = lista->valores[i+1]; // aqui vamos deslocar para a esquerda
  }
}

int inserir(Lista *lista, int valor){ // aqui vamos inserir um valor na lista
  if(esta_cheia(lista)){ // aqui vamos verificar se a lista esta cheia
    return 0; // aqui vamos retornar 0 se a lista estiver cheia
  }
  int i = 0; // aqui vamos criar um contador
  while(i < lista->n && valor >= lista->valores[i]){
    i++;
  }
  deslocar_direita(lista, i); // aqui vamos deslocar para a direita
  lista->valores[i] = valor; // aqui vamos inserir o valor na posição i
  lista->n++;  // aqui vamos incrementar a quantidade de elementos na lista
  return 1; // aqui vamos retornar 1 se o valor foi inserido

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