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
/**
* Note: O vetor de retorno deve ser alocado internamente, assuma que quem chamou vai dar free
nele */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct par {
    int indice;
    int valor;
};


//Indice
int cmpParIndice ( const void* x, const void *y ) {
    struct par px = *( const struct par* ) x;
    struct par py = *( const struct par* ) y;
    return px.indice - py.indice;
    }

//Valor
int cmpParValor ( const void* x, const void *y ) {
    struct par px = *( const struct par* ) x;
    struct par py = *( const struct par* ) y;
    return py.valor - px.valor;
    }

//Subsequência
int* maxSubsequence( int* nums, int numsSize, int k, int* returnSize ) {
    struct par * pairs = malloc(sizeof(struct par)*numsSize );
    for ( int i = 0; i < numsSize; i++ ) {
        pairs[i].indice = i;
        pairs[i].valor = nums[i];
    } 


//Ordenação
    qSort ( pairs,numsSize,sizeof(struct par),cmpParValor );
    qSort ( pairs,k,sizeof(struct par),cmpParIndice );
    int * res = (int*)malloc(sizeof(int)*k);

//Length K para definir o tamanho da matriz extraída
    if ( 1 => k && k <= nums.length ) {
    ( *returnSize ) = k; }
    for ( int i = 0; i < k ; i++ ) {
        res[i] = nums [ pairs[i].indice ];
    }

    free ( pairs );
    return res;

}