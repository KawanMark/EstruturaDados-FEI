#include <stdio.h>
#include <stdlib.h>

typedef struct Celula { //estrutura da celula
    int valor; //valor da celula
    struct Celula *proximo; //ponteiro para a proxima celula
    struct Celula *anterior; //ponteiro para a celula anterior
} Celula; //tipo da estrutura

typedef struct{ //estrutura da fila
    Celula *head; //ponteiro para a cabeça da fila
    Celula *tail;   //ponteiro para o final da fila
    int qtde; //quantidade de elementos na fila
} Queue;  //tipo da estrutura

Celula *criar_celula(int valor){ //função para criar uma celula
    Celula *celula = (Celula *)malloc(sizeof(Celula)); //alocando espaço na memoria para a celula
    celula->valor = valor; //setando o valor da celula
    celula->proximo = NULL;     //setando o proximo da celula como nulo
    celula->anterior = NULL;   //setando o anterior da celula como nulo
    return celula;  //retornando a celula
}

Queue *cria_queue(){ //função para criar uma fila
    Queue *queue = (Queue *)malloc(sizeof(Queue)); //alocando espaço na memoria para a fila
    queue->head = NULL; //setando a cabeça da fila como nulo
    queue->tail = NULL;  //setando o final da fila como nulo
    queue->qtde = 0; //setando a quantidade de elementos na fila como 0
    return queue; //retornando a fila
}

void enqueue(Queue *queue, int valor){ //função para adicionar um elemento na fila
    Celula *novo = criar_celula(valor); //criando uma nova celula
    if(queue->qtde == 0){ //se a fila estiver vazia
        queue->head = novo; //seta a cabeça da fila como a nova celula
    }else{ //se a fila não estiver vazia
        queue->tail->proximo = novo; //seta o proximo da ultima celula como a nova celula
        novo->anterior = queue->tail; //seta o anterior da nova celula como a ultima celula
    }

    queue->tail = novo; //seta o final da fila como a nova celula
    queue->qtde++;  //incrementa a quantidade de elementos na fila
}

int dequeue(Queue *queue){ //função para remover um elemento da fila
    if(queue->qtde == 0){ //se a fila estiver vazia
        return -1; //retorna -1
    }

    int valor = queue->head->valor; //pega o valor da cabeça da fila
    Celula *temp = queue->head; //cria uma celula temporaria
    queue->head = queue->head->proximo; //seta a cabeça da fila como o segundo

    if(queue -> qtde == 1){ //fila unitaria
        queue->tail = NULL; //seta o final da fila como nulo
    }
    else{
        queue->head->anterior = NULL; //pega a cabeça da fila e seta o anterior como nulo
    }
    free(temp); //libera a celula temporaria
    queue->qtde--; //decrementa a quantidade de elementos na fila
    return valor; //retorna o valor
}

void show(Queue * queue){   //função para mostrar a fila
    Celula *atual = queue->head; //cria uma celula atual e seta como a cabeça da fila
    while(atual != NULL){ //enquanto a celula atual não for nula
        printf("%d ", atual->valor); //printa o valor da celula atual
        atual = atual->proximo; //seta a celula atual como a proxima celula
    }
    printf("\n");
}

void show_invertido(Queue *queue){
    Celula *atual = queue->tail; //cria uma celula atual e seta como o final da fila
    while(atual != NULL){ //enquanto a celula atual não for nula
        printf("%d ", atual->valor); //printa o valor da celula atual
        atual = atual->anterior; //seta a celula atual como a celula anterior
    }
    printf("\n");
}

void somar(Queue *qnum1, Queue *qnum2, Queue *res){ // função para somar os primeiros elemtnos da fila 
    int carry = 0; //variavel para guardar o carry
    while(qnum1->qtde > 0 || qnum2->qtde > 0){ //enquanto as filas não estiverem vazias
        int n1 = dequeue(qnum1); //pega o primeiro elemento da fila 1
        int n2 = dequeue(qnum2); //pega o primeiro elemento da fila 2

        int soma = n1 + n2 + carry; //soma os dois elementos e o carry
        carry = soma / 10; //calcula o carry
        enqueue(res, soma % 10); //adiciona o resto da soma na fila resultado
    }
    if(carry > 0){ //se o carry for maior que 0
        enqueue(res, carry); //adiciona o carry na fila resultado
    }
}





int main(void) {
	Queue *qnum1 = cria_queue();
	Queue *qnum2 = cria_queue();
	Queue *res = cria_queue();
	
	char num1[100];
	char num2[100];
	fgets(num1, sizeof(num1), stdin);
	fgets(num2, sizeof(num2), stdin);

	int i = 0;
	while(num1[i] != '\n'){		
		enqueue(qnum1, (int)(num1[i]) - 48);
		enqueue(qnum2, (int)(num2[i]) - 48);
		i++;
		}

	// implementar
}