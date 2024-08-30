#include <stdio.h>
#include <stdlib.h>

#define TAM 10


typedef struct {
  int valores[TAM];
  int qtd;
} LES;

void inserir_inicio(LES *les, int valor){
  if(les->qtd == 0){
    les->valores[0] = valor;
    les->qtd++;
  } else if(les->qtd < TAM){
      for(int i = les->qtd; i > 0; i--){
        les->valores[i] = les->valores[i-1];
      }
    les -> valores[0] = valor;
    les->qtd++;
  }
}

void printar(LES *les){
  for(int i = 0; i < les->qtd; i++){
    printf("%d ", les->valores[i]);
  }
}


int main(void) {
  LES *les = malloc(sizeof(LES));
  les->qtd = 0;

  inserir_inicio(les, 6);
  inserir_inicio(les, 3);
  inserir_inicio(les, 5);
  inserir_inicio(les, 8);

  printar(les);

  inserir_inicio(les, 0);

  printar(les);

  
  
  return 0;
}