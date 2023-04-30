/* 2099. Encontre a subsequência de comprimento K com a maior soma
        -Você recebe um vetor de inteiro nums e um inteiro k. Você deseja encontrar uma subsequência em
nums de comprimento k que tenha a maior soma.
        -Retorne a subsequência como uma matriz de inteiros com comprimento k.
        -Uma subsequência é uma matriz que pode ser extraída de outra matriz excluindo alguns ou nenhum
elemento sem alterar a ordem dos elementos restantes.                          
Restrições:
     1 <= nums.comprimento <= 1000
     -105 <= num[i] <= 105
     1 <= k <= nums.comprimento
* Note: O vetor de retorno deve ser alocado internamente, assuma que quem chamou vai dar free
nele */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct par {
    int indice;
    int valor;
};

//Indice
int cmpParIndice ( const void* x, const void* y ) {
    const struct par* px = ( const struct par* )x;
    const struct par* py = ( const struct par* )y;
    return px->indice - py->indice;
}

//Valor
int cmpParValor ( const void* x, const void* y ) {
    const struct par* px = ( const struct par* )x;
    const struct par* py = ( const struct par* )y;
    return py->valor - px->valor;
}

//Subsequência
int* maxSubsequence ( int* nums, int numsSize, int k, int* returnSize ) {
    struct par* pairs = malloc(sizeof(struct par) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        pairs[i].indice = i;
        pairs[i].valor = nums[i];
    }

    //Ordenação
    qsort ( pairs, numsSize, sizeof(struct par), cmpParValor );
    qsort ( pairs, k, sizeof(struct par), cmpParIndice );
    int* res = malloc(sizeof(int) * k);

    //Length K para definir o tamanho da matriz extraída
    *returnSize = k;
    for ( int i = 0; i < k; i++ ) {
        res[i] = nums[pairs[i].indice];
    }

    free(pairs);
    return res;
}

int main() {
    int numsSize, k;
    printf ( "Informe o tamanho do vetor de entrada: " );
    scanf ( "%d", &numsSize );
    int nums[numsSize];
    for ( int i = 0; i < numsSize; i++ ) {
        printf ( "Informe o elemento %d do vetor: ", i );
        scanf ( "%d", &nums[i] );
    }
    printf ( "Informe o tamanho da subsequencia de saida: " );
    scanf ( "%d", &k );
    int returnSize = 0;
    int* res = maxSubsequence ( nums, numsSize, k, &returnSize );
    printf ( "Subsequencia de tamanho %d: ", k );
    for ( int i = 0; i < returnSize; i++ ) {
        printf ( "%d ", res[i] );
    }
    printf ( "\n" );
    free(res);
    return 0;
}