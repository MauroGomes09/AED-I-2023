#include <stdio.h>
#include <stdlib.h>


//Entrada de dados
typedef long TipoChave;
typedef struct Registro {
TipoChave Chave;
/* outros componentes */
} Registro;
typedef struct No * Apontador;
typedef Apontador TipoDicionario;

typedef Struct No {
Registro Reg;
Apontador pEsq, pDir;
} No;


//Altura
int Altura(TNo* pRaiz) {
    int iEsq,iDir;
    if (pRaiz == NULL)
    return 0;
    iEsq = Altura(pRaiz->pEsq);
    iDir = Altura(pRaiz->pDir);
    if ( iEsq > iDir )
    return iEsq + 1;
else { return iDir + 1; }
}

//Fator de balanceamento
int FB (TNo* pRaiz)
{
if (pRaiz == NULL)
return 0;
return Altura(pRaiz->pEsq)-Altura(pRaiz->pDir);
}

//Balanceamento
int Balanceamento(TNo** ppRaiz)
{
int fb = FB(*ppRaiz);
if ( fb > 1)
return BalancaEsquerda(ppRaiz);
else if (fb <-1 )
return BalancaDireita(ppRaiz);
else { return 0};
}


//Inserção
int Insere(TNo** ppRaiz,Registro* x)
{
if (*ppRaiz == NULL)
{
*ppRaiz = (TNo*)malloc(sizeof(TNo));
(*ppRaiz)->Reg = *x;
(*ppRaiz)->pEsq = NULL;
(*ppRaiz)->pDir = NULL;
return 1;
}
else if ( (*ppRaiz)->Reg.chave> x->chave )
{
if ( Insere(&(*ppRaiz)->pEsq,x) )
{
if (Balanceamento(ppRaiz))
return 0;
else
return 1;
}
} 
}

//Inserção
else if ( (*ppRaiz)->Reg.chave< x->chave )
{
    if ( Insere(&(*ppRaiz)->pDir,x) )
{
    if (Balanceamento(ppRaiz))
return 0;
else
    return 1;
}
    else
    return 0;
}
    else {
    return 0; /* valor jah presente */
    }

//Verifica se a árvore é AVL
int EhArvoreArvl(TNo* pRaiz)
{
int fb;
if (pRaiz == NULL)
return 1;
if (!EhArvoreArvl(pRaiz->pEsq))
return 0;
if (!EhArvoreArvl(pRaiz->pDir))
return 0;
fb = FB (pRaiz);
if ( ( fb > 1 ) || ( fb <-1) )
return 0;
else
return 1;
}
