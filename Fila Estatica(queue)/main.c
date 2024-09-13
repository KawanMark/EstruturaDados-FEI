#include <stdio.h>
#define CAP 10

typedef struct{
    int dados[CAP];
    int head;
    int tail;
    int qtd;
} Queue;

void inicializar(Queue *queue){
    queue->head = 0;
    queue->tail = 0;
    queue->qtd = 0;
}

int (is_full)(Queue *queue){
    return queue->qtd == CAP;
}

int (is_empty)(Queue *queue){
    return queue->qtd == 0;
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



void mostrar(Queue *queue){
    printf("Head -> " );
    for(int i = queue->head; i < queue->tail; i++){
        printf("%d ", queue->dados[i % CAP]);
    }
    printf(" <- Tail\n");
}


int main()
{
    Queue queue;
    inicializar(&queue);

    for(int num = 89; num > 0; num-= 7){
        enqueue(&queue, num);
        mostrar(&queue);
    }

    for(int i = 0; i < 5; i++){
        printf("valor removido: %d\n", dequeue(&queue));
        mostrar(&queue);
    }

    return 0;
}