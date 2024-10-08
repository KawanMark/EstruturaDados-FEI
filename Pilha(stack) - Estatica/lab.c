#include <stdio.h>
#include <stdbool.h>
#define CAP 10


typedef struct {
    int dados[CAP];
    int topo;
    
}Stack;

bool push(Stack *pilha, int valor){
    if(pilha->topo == CAP){
        printf("Stack overflow!\n");
        return false;
    }
    pilha->dados[pilha->topo++] = valor;
    return true;
}

int pop(Stack *pilha){
    if(pilha->topo == 0){
        printf("Stack underflow!\n");
        return -1;
    }
    return pilha->dados[--pilha->topo];
}

void show(Stack *pilha){
    printf("TOPO -> ");
    for(int i = pilha->topo -1; i >= 0; i--){
        printf("%d ", pilha->dados[i]);
    }
    printf(" <- BASE\n");
}


// Função que verifica se uma expressão possui parênteses, colchetes e chaves balanceados
int is_balanced(const char *expr) {
    // Inicializa uma pilha com capacidade para 100 elementos
    Stack *stack = start_stack(100); 

    // Percorre cada caractere da expressão
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        // Se o caractere for uma abertura de parênteses, colchetes ou chaves, empilha
        if (c == '{' || c == '[' || c == '(') {
            push(stack, c);
        } 
        // Se o caractere for um fechamento de parênteses, colchetes ou chaves
        else if (c == '}' || c == ']' || c == ')') {
            // Se a pilha estiver vazia, a expressão não está balanceada
            if (is_empty(stack)) {
                free(stack->dados);
                free(stack);
                return 0; 
            }
            // Desempilha o topo da pilha
            char topo = pop(stack);
            // Verifica se o topo da pilha corresponde ao fechamento atual
            if ((c == '}' && topo != '{') ||
                (c == ']' && topo != '[') ||
                (c == ')' && topo != '(')) {
                free(stack->dados);
                free(stack);
                return 0; 
            }
        }
    }

    // Verifica se a pilha está vazia após processar toda a expressão
    int balanced = is_empty(stack);
    // Libera a memória alocada para a pilha
    free(stack->dados);
    free(stack);
    // Retorna 1 se a expressão está balanceada, caso contrário, retorna 0
    return balanced;
}
int main(void) {
    Stack *stack = start_stack(100); 
    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    if (is_balanced(c)) {
        printf("correto\n");
    } else {
        printf("incorreto\n");
    }

    free(stack->dados);
    free(stack);
    return 0;
}