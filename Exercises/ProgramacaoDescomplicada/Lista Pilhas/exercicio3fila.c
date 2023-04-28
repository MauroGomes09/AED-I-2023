#include <stdio.h>
#include <stdlib.h>

int main() {
    char **nomes = NULL; // declara um ponteiro para um array de strings
    int n = 0, i;
    char buffer[50];

    while (1) { // loop infinito
        printf("Digite um nome (ou 'sair' para encerrar): ");
        scanf("%s", buffer);

        if (strcmp(buffer, "sair") == 0) {
            break; // sai do loop se o usuário digitar 'sair'
        }

        n++; // incrementa o número de nomes digitados

        // aloca mais memória para o array de nomes
        nomes = (char **)realloc(nomes, n * sizeof(char *));
        if (nomes == NULL) {
            printf("Erro ao alocar memória\n");
            return 1;
        }

        // aloca memória para o nome atual
        nomes[n-1] = (char *)malloc(strlen(buffer) + 1);
        if (nomes[n-1] == NULL) {
            printf("Erro ao alocar memória\n");
            return 1;
        }

        // copia o nome digitado para o array
        strcpy(nomes[n-1], buffer);
    }

    // imprime todos os nomes
    printf("\nNomes digitados:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", nomes[i]);
    }

    // libera a memória alocada
    for (i = 0; i < n; i++) {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}