
#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct {
  int valores[LEN];
  int qtde;
} heap;

int filho_esq(int pai) { 
    //O filho esquerdo de um nó de índice i é dado por: fe = 2.i + 1
    return 2 * pai + 1;
   
}

int filho_dir(int pai) { 
    // O filho direito de um nó de índice i é dado por: f d = 2.i + 2
    return 2 * pai + 2;
}

int pai(int filho) { 
    //O pai de um nó de índice i é dado por: p = ⌊(i − 1)/2⌋
    return (filho-1) / 2;
}

int ultimo_pai(heap *h) { 
    //O último pai de um nó de índice i é dado por: up = ⌊n/2⌋ − 1
    return (h->qtde / 2) - 1;
}
int max(int a, int b, int c){
    int valores[] = {a,b,c};
    int maior = -1000;
    for(int x =0  ;x < 3;x++){
        if(valores[x]>maior){
            maior = valores[x];
        }
    }
    return maior;
}
void peneirar(heap *h, int pai) {//os nos dos filhos nao podem ser maior que dos pais
  int maior = pai;
  int esq = filho_esq(pai);
  int dir = filho_dir(pai);
  
  if(esq < h->qtde && h->valores[esq] > h->valores[maior]){
      maior = esq;
  }
  
  if(dir < h->qtde && h->valores[dir] > h->valores[maior]){
      maior = dir;
  }
  
  if( maior != pai){
      int temporaria = h->valores[maior];
      h->valores[maior] = h->valores[pai];
      h->valores[pai] = temporaria;
      peneirar(h, maior);
  }
}


void mostrar(heap *h) {
  for(int i = 0; i < h->qtde; i++){
      printf("%d ", h->valores[i]);
  }
  printf("\n");
}

void construir(heap *h) {
  for (int i = (h->qtde - 1) / 2; i >= 0; i--) {
        peneirar(h, i);
    }
}

void inserir(heap *h, int valor) {
    if (h->qtde == LEN) { // se minha quantidade for menor que o tamanho retorna
        return;
    }
    h->valores[h->qtde] = valor; //posiciona o valor na primeira livre do array
    h->qtde++;
    if(valor > pai(h->qtde-1)){ // se o valor for maior que o pai dele, constroi
        construir(h);
    }
}

void remover(heap *h) {
     if (h->qtde > 0) {
        h->valores[0] = h->valores[h->qtde - 1];
        h->qtde--;
        construir(h);
    } else {
        printf("Heap vaziua\n");
    }
}

int main(void) {
  heap *h = malloc(sizeof(heap));
  int valor;
  h->qtde = 0;
  for (int i = 0; i < LEN; i++) {
    scanf("%d", &valor);
    inserir(h, valor);
    mostrar(h);
  }
  for (int i = 0; i < LEN; i++) {
    remover(h);
    mostrar(h);
  }

  return 0;
}