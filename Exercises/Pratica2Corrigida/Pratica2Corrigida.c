#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
    // Conta o número de elementos na lista
    int count = 0;
    struct ListNode *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    
    // Armazena os elementos da lista em um array
    int *arr = (int*) malloc(count * sizeof(int));
    curr = head;
    for (int i = 0; i < count; i++) {
        arr[i] = curr->val;
        curr = curr->next;
    }
    
    // Verifica se o array é um palíndromo
    for (int i = 0; i < count/2; i++) {
        if (arr[i] != arr[count-1-i]) {
            free(arr);
            return false;
        }
    }
    
    free(arr);
    return true;
}

int main() {
    // Cria a lista encadeada
    struct ListNode *head = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->val = 2;
    head->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->next->next->next->val = 2;
    head->next->next->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 1;
    head->next->next->next->next->next = NULL;
    
    // Verifica se a lista é um palíndromo
    if (isPalindrome(head)) {
        printf("A lista e um palindromo.\n");
    } else {
        printf("A lista nao e um palindromo.\n");
    }
    
    // Libera a memória alocada pela lista encadeada
    struct ListNode *curr = head;
    while (curr != NULL) {
        struct ListNode *temp = curr->next;
        free(curr);
        curr = temp;
    }
    
    return 0;
}