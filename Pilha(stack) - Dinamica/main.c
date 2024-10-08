#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *proximo;
    int valor;
} Celula;

typedef struct {
    Celula *topo;
    int qtd;
} Stack;

Celula *criar_celula(int valor){
    Celula *celula = malloc(sizeof(Celula));
    celula->valor = valor;
    celula->proximo = NULL;
    return celula;
}

Stack *criar_pilha(){
    Stack *pilha = malloc(sizeof(Stack));
    pilha-> topo = NULL;
    pilha -> qtd = 0;
    return pilha;
}

void push(Stack *pilha, int valor){
    Celula *novo = criar_celula(valor);
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->qtd++;
}

int pop(Stack *pilha){
    if(pilha->qtd == 0){
        printf("Stack underflow!\n");
        return -1;
    }
    int valor = pilha->topo->valor; 
    Celula *temp = pilha->topo;
    
    pilha->topo = temp->proximo;
    pilha->qtd--;
    free(temp);
    return valor;
}

void show(Stack *pilha){
    Celula *atual = pilha->topo;
    printf("TOPO -> ");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("<- BASE\n");
}



int main() {
    
    Stack *pilha = criar_pilha();
    for(int num = 0; num < 15; num++){
        push(pilha, num);
        show(pilha);
    }

    for(int i = 0; i < 15; i++){
        printf("POP: %d\n", pop(pilha));
        show(pilha);
    }

    return 0;
}