#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int front, rear;
    int items[MAX];
};

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Fila cheia!\n");
        return;
    } else {
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    if (q->front == q->rear) {
        printf("Fila vazia!\n");
        return -1;
    } else {
        q->front++;
        int value = q->items[q->front];
        return value;
    }
}

void display(struct Queue* q) {
    int i;
    if (q->front == q->rear) {
        printf("Fila vazia!\n");
        return;
    }
    for (i = q->front+1; i <= q->rear; i++) {
        printf("%d\n", q->items[i]);
    }
}

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    int opcao, valor;
    FILE* fp;
    fp = fopen("fila.txt", "w");

    do {
        printf("\n1 - Inserir na fila\n2 - Remover da fila\n3 - Mostrar fila\n4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                enqueue(&q, valor);
                fprintf(fp, "%d ", valor);
                break;
            case 2:
                valor = dequeue(&q);
                if (valor != -1) {
                    printf("Valor removido: %d\n", valor);
                }
                break;
            case 3:
                printf("Fila:\n");
                display(&q);
                break;
            case 4:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 4);

    fclose(fp);
    return 0;
}