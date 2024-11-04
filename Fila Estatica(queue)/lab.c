#include <stdio.h>
#define CAP 100

typedef struct{ //aqui vamos criar a estrutura da fila
    int dados[CAP]; //aqui vamos criar um array de inteiros com o tamanho da capacidade
    int head; //aqui vamos criar a cabeça da fila
    int tail; // aqui vamos criar a calda da fila
    int qtd; //aqui vamos criar a quantidade de elementos na fila
} Queue;

void inicializar(Queue *queue){ //aqui vamos inicializar a fila
    queue->head = 0; //aqui vamos inicializar a cabeça da fila
    queue->tail = 0; //aqui vamos inicializar a calda da fila
    queue->qtd = 0; //aqui vamos inicializar a quantidade de elementos na fila
}

int (is_full)(Queue *queue){ //aqui vamos verificar se a fila esta cheia
    return queue->qtd == CAP; // aqui vamos retornar se a quantidade de elementos na fila for igual a capacidade da fila
}

int (is_empty)(Queue *queue){ //aqui vamos verificar se a fila esta vazia
    return queue->qtd == 0; // aqui vamos retornar se a quantidade de elementos na fila for igual a zero 
}

int (enqueue)(Queue *queue, int valor){
    if(is_full(queue)){
        return 0;
    }
    queue->dados[queue->tail % CAP] = valor;
    queue->tail++;
    queue->qtd++;
    return 1;
}

int(dequeue)(Queue *queue){
    if(is_empty(queue)){
        return -1;
    }
    queue->qtd--;
    return queue->dados[queue->head++ % CAP];
}

int lilkaw(Queue *queue){ //precisamos verificar se esta balanceado igual o exercicio do beecrownd
    int n = 0; //aqui vamos usar para verificar se esta ok se n == 0
    
    for(int i = queue->head; i < queue->tail; i++){ // iteramos da cabeça ate a calda da queue.
        char x = queue->dados[i % CAP]; //iremos obter o char atual aq, garantindo que esta no limite da capacidade da fila 
        if( x == '('){ // aqui iremos usar o contador para verificar a esquerda
            n++;
        }
        else if( x == ')'){ // aqui iremos verificar a direita para fechar
            n--;
        }
        
        if(n < 0){ //se o n for menor que zero entao e verdadeiro, 
            return 0;
        }
    }
    
    return n == 0;
    
    
}


void mostrar(Queue *queue){
    for(int i = queue->head; i < queue->tail; i++){
        printf("%c", queue->dados[i % CAP]);
    }
}


int main()
{

    char s[CAP];
    Queue queue;
    inicializar(&queue);

    fgets(s, sizeof(s), stdin);

    for(int i = 0; s[i] != '\0'; i++){
        enqueue(&queue, s[i]);
    }
    
    while(!is_empty(&queue)){
        mostrar(&queue);
        dequeue(&queue);
    }

   if(lilkaw(&queue)){
        printf("incorreto\n");
    } else {
        printf("correto\n");
    }
   

    return 0;
}