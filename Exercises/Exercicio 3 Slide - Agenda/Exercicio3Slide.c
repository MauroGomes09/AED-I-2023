/*
As funções incluir_pessoa, apagar_pessoa, buscar_pessoa e listar_pessoas recebem o endereço do buffer como argumento (por meio de um ponteiro duplo void **pBuffer) e manipulam as informações contidas nele para realizar as operações desejadas.
A função incluir_pessoa verifica se ainda há espaço no buffer para incluir uma nova pessoa (comparando o número atual de pessoas com o tamanho máximo do buffer), e se houver, pede ao usuário para inserir os dados da pessoa e adiciona as informações no final do buffer.
A função apagar_pessoa procura a pessoa a ser apagada pelo nome e, se encontrá-la, remove as informações do buffer movendo as informações das pessoas seguintes para o lugar da pessoa removida.
A função buscar_pessoa também procura a pessoa pelo nome e, se encontrá-la, mostra suas informações.
A função listar_pessoas simplesmente percorre o buffer mostrando as informações de todas as pessoas.
A função main exibe um menu com as opções disponíveis para o usuário e executa a operação escolhida até que a opção "0. Sair" seja selecionada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa uma pessoa
struct Pessoa {
    char nome[10];
    int idade;
    char telefone[20];
};

// Função para incluir uma pessoa na agenda
void incluir_pessoa ( void **pBuffer ) {
    int num_pessoas = *( ( int* ) *pBuffer ); // Obtém o número atual de pessoas
    num_pessoas++; // Incrementa o número de pessoas

    // Realoca o buffer com espaço para a nova pessoa
    *pBuffer = realloc ( *pBuffer, sizeof(int) + num_pessoas * sizeof ( struct Pessoa ));
    if ( *pBuffer == NULL ) {
        printf ( "Erro ao alocar memória.\n" );
        exit ( 1 );
    }

    // Obtém um ponteiro para a nova pessoa
    struct Pessoa *nova_pessoa = ( struct Pessoa* ) ( *pBuffer + sizeof(int) + (num_pessoas - 1) * sizeof(struct Pessoa));

    // Pede as informações da nova pessoa ao usuário
    printf ( "Nome da pessoa: " );
    scanf ( "%s", nova_pessoa->nome );
    printf ( "Idade da pessoa: " );
    scanf ( "%d", &nova_pessoa->idade );
    printf ( "Telefone da pessoa: " );
    scanf ( "%s", nova_pessoa->telefone );

    // Atualiza o número de pessoas na agenda
    *((int*) *pBuffer) = num_pessoas;
}

// Função para apagar uma pessoa da agenda
void apagar_pessoa ( void **pBuffer ) {
    int num_pessoas = *((int*) *pBuffer); // Obtém o número atual de pessoas

    if ( num_pessoas == 0 ) {
        printf ( "Não há pessoas na agenda.\n" );
        return;
    }

    // Pede o índice da pessoa a ser apagada ao usuário
    printf ( "Índice da pessoa a ser apagada (0 a %d): ", num_pessoas - 1 );
    int indice;
    scanf ( "%d", &indice );

    if ( indice < 0 || indice >= num_pessoas ) {
        printf ( "Índice inválido.\n" );
        return;
    }

    // Obtém um ponteiro para a pessoa a ser apagada
    struct Pessoa *pessoa = (struct Pessoa*) (*pBuffer + sizeof(int) + indice * sizeof(struct Pessoa));

    // Copia as outras pessoas para preencher o espaço vago
    memmove ( pessoa, pessoa + 1, (num_pessoas - indice - 1) * sizeof(struct Pessoa));

    num_pessoas--; // Decrementa o número de pessoas

    // Realoca o buffer com espaço para o novo número de pessoas
    *pBuffer = realloc(*pBuffer, sizeof(int) + num_pessoas * sizeof(struct Pessoa));
    if (*pBuffer == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    // Atualiza o número de pessoas na agenda
    *((int*) *pBuffer) = num_pessoas;
}

// Função para buscar uma pessoa na agenda
void buscar_pessoa ( void **pBuffer ) {
    int num_pessoas = *((int*) *pBuffer); // Obtém o número atual de pessoas

    if ( num_pessoas == 0 ) {
        printf( "Não há pessoas na agenda.\n" );
        return;
    }

   // Pede o nome da pessoa a ser buscada ao usuário
printf ( "Nome da pessoa a ser buscada: " );
char nome[10];
scanf ( "%s", nome );

// Procura a pessoa com o nome especificado
int i;
for ( i = 0; i < num_pessoas; i++ ) {
    struct Pessoa *pessoa = (struct Pessoa*) (*pBuffer + sizeof(int) + i * sizeof(struct Pessoa));
    if ( strcmp(pessoa->nome, nome) == 0) {
        // Se encontrou, mostra as informações da pessoa
        printf ( "Nome: %s\n", pessoa->nome );
        printf ( "Idade: %d\n", pessoa->idade );
        printf ( "Telefone: %s\n", pessoa->telefone );
        return;
    }
}

// Se não encontrou, mostra uma mensagem de erro
printf ( "Pessoa não encontrada.\n" );
}

// Função para listar todas as pessoas da agenda
void listar_pessoas ( void **pBuffer ) {
int num_pessoas = ((int) *pBuffer); // Obtém o número atual de pessoas
if ( num_pessoas == 0 ) {
    printf ( "Não há pessoas na agenda.\n" );
    return;
}

// Mostra as informações de todas as pessoas
printf ( "Pessoas na agenda:\n" );
int i; 
for ( i = 0; i < num_pessoas; i++ ) {
    struct Pessoa *pessoa = (struct Pessoa*) (*pBuffer + sizeof(int) + i * sizeof(struct Pessoa));
    printf( "%d: %s, %d anos, %s\n", i, pessoa->nome, pessoa->idade, pessoa->telefone);
}
}

int main() {
void *pBuffer = malloc(sizeof(int)); // Cria um buffer vazio com espaço para o número de pessoas
if ( pBuffer == NULL ) {
printf ( "Erro ao alocar memória.\n" );
exit(1);
}
*((int*) pBuffer) = 0; // Inicializa o número de pessoas como zero

int opcao;
do {
    // Mostra as opções de operação
    printf ( "\nAgenda de Pessoas\n" );
    printf ( "1. Incluir pessoa\n" );
    printf ( "2. Apagar pessoa\n" );
    printf ( "3. Buscar pessoa\n" );
    printf ( "4. Listar pessoas\n" );
    printf ( "0. Sair\n" );
    printf ( "Opção: " );
    scanf ( "%d", &opcao );

    // Executa a operação escolhida pelo usuário
    switch (opcao) {
        case 1:
            incluir_pessoa(&pBuffer);
            break;
        case 2:
            apagar_pessoa(&pBuffer);
            break;
        case 3:
            buscar_pessoa(&pBuffer);
            break;
        case 4:
            listar_pessoas(&pBuffer);
            break;
        case 0:
            break;
        default:
            printf ( "Opção inválida.\n" );
            break;
    }
} while ( opcao != 0 );

free ( pBuffer ); // Libera a memória alocada pelo buffer

return 0;
}