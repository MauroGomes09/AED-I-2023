/* 
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Nome: Mauro Artur Gomes de Oliveira - N de matrícula: 21102813 - AGENDA - Estrutura de código utilizada: Doom 3 Code Style Conventions
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10*sizeof(char)+4*sizeof(int)

int *pBuffer = NULL;

int *frenteRecebe ( int *pBuffer, void *pawn ) {//pawn aponta pro q estava sendo apontado pelo buffer, buffer aponta pra pawn
	if ( !pBuffer )
		return pawn;

	void *iniPerson = pawn;

	void **bufferBloco = (void*)&pBuffer;
	pawn+=10*sizeof(char)+3*sizeof(int);

	*(int *)pawn = (int)pBuffer;//pessoa q ta sendo adicionada aponta pro que o buffer apontava
	*(int*)(*bufferBloco+10*sizeof(char)+2*sizeof(int)) = (int)iniPerson;//o prev da pessoa q tava no buffer aponta pra q entrou

	return iniPerson;
}

void list(int *pBuffer){
	if (!pBuffer)
		return;

	void **bufferBloco = (void*)&pBuffer;
	void *prev;

	//No caso de apenas ter adicionado uma pessoa
	if (*(int*)(*bufferBloco+10*sizeof(char)+3*sizeof(int))==0){
		printf("\n===========================");
		printf("\nNome: %s",(char*)pBuffer);
		printf("\nIdade: %d",(int*)*(int*)(*bufferBloco+10*sizeof(char)));
		printf("\nTelefone: %d",(int*)*(int*)(*bufferBloco+10*sizeof(char)+sizeof(int)));
		system("pause");
	}

	printf("\nPercorrendo pelo inicio\n");
	while (pBuffer!=0){
		printf("\nNome: %s",(char*)pBuffer);
		printf("\nIdade: %d",(int*)*(int*)(*bufferBloco+10*sizeof(char)));
		printf("\nTelefone: %d",(int*)*(int*)(*bufferBloco+10*sizeof(char)+sizeof(int)));
		pBuffer = (int*)*(int*)(*bufferBloco+10*sizeof(char)+3*sizeof(int));
		if (pBuffer!=0)
			prev=pBuffer;
	} 
	pBuffer= prev;
	printf("\nPercorrendo pelo fim\n");
	while ((int*)pBuffer!=0){
		printf("\nNome: %s",(char*)pBuffer);
		printf("\nIdade: %d",(int*)*(int*)(*bufferBloco+10*sizeof(char)));
		printf("\nTelefone: %d",(int*)*(int*)(*bufferBloco+10*sizeof(char)+sizeof(int)));
		pBuffer = (int*)*(int*)(*bufferBloco+10*sizeof(char)+2*sizeof(int));
	} 
	printf("\n");
	system("pause");
}

int *Push (int *pBuffer, void *pawn){
	if (!pBuffer){
		pBuffer = frenteRecebe(pBuffer,pawn);
		return pBuffer;
	}

	//compara se o elemento deve vir como primeiro
	if (strcmp((char*)pBuffer,(char*)pawn)>=1){
		pBuffer = frenteRecebe(pBuffer,pawn);
		return pBuffer;
	}

	int *start = pBuffer;
	int *prev;
	void **bufferBloco = (void*)&pBuffer;
	void **prevPessoa = (void*)&prev;
	while ( 100 ){
		prev = pBuffer;
		if (strcmp((char*)pBuffer,(char*)pawn)>=1){
			prev = (int*)*(int*)(*prevPessoa+10*sizeof(char)+2*sizeof(int));//prev recebe a pessoa de tras
			*(int*)(*prevPessoa+10*sizeof(char)+3*sizeof(int)) = (int) pawn;
			//nó da frente da pessoa de tras = nova pessoa
	
			*(int*)(*bufferBloco+10*sizeof(char)+2*sizeof(int)) = (int) pawn;
			//nó de trás da ultima pessoa = pawn

			//atualizando os nós da nova pessoa
			pawn += SIZE-2*sizeof(int);
			*(int*)pawn = *(int*)prevPessoa;
			pawn += sizeof(int);
			*(int*)pawn = *(int*)bufferBloco;//o nó da frente da nova pessoa recebe a pessoa do buffer
			
			return start;
		}

		pBuffer = *(int**)(*bufferBloco+10*sizeof(char)+3*sizeof(int));//incrementa

		if (!pBuffer){//se for a ultima pessoa
			finalRecebe ( prev,pawn );
			return start;
		} 
		//só cai aqui se for no meio, então se a pessoa q eu to tentando adicionar vier antes da prox ele adiciona
	}
	return 0;
}

int *Pop ( int *pBuffer ) {//apaga o primeiro elemento pois segue as regras da fila
	void **bufferBloco = (void*)&pBuffer;
	void *exc = pBuffer;

	if (!pBuffer)
		return 0;
	if ( *(int*)(*bufferBloco+10*sizeof(char)+3*sizeof(int))==0 ) {
		free ( pBuffer );
		return 0; //caso tenha apenas um elemento
	}

	if ( *(int*)(*bufferBloco+10*sizeof(char)+2*sizeof(int))==0 ) {
		pBuffer = (int*)*(int*)(*bufferBloco+SIZE-sizeof(int));
		//pBuffer vai pra prox pessoa
		*(int*)(*bufferBloco+10*sizeof(char)+2*sizeof(int)) = 0;
		//limpa o prev da segunda pessoa
		free ( exc );
		return pBuffer;
	}
	return 0;
}

void finalRecebe(int *pBuffer, void *pawn){//faz o next da ultima receber pawn, e o prev de pawn receber essa ultima
	void **bufferBloco = (void*)&pBuffer;
	int *nextLastPerson = (int*)(*bufferBloco+10*sizeof(char)+3*sizeof(int));
	//.next da ultima pessoa do buffer

	*nextLastPerson = (int)pawn;
	pawn += SIZE-2*sizeof(int);//vai pro prev de pawn
	*(int*)pawn = (int)(int*)(*bufferBloco);//faz ele receber a ultima pessoa q tava no buffer
}

int main() {
	void *pawn,*exc,**bufferBloco = (void*)&pBuffer;
	while ( 1 ) { system ("cls");
        printf ( "\n------------------------------Menu-----------------------------" );
		printf ( "\n1 Adicionar bloco(info da pessoa)" );
        printf ( "\n2 Listar bloco com todas as pessoas" );
        printf ( "\n3 Remover bloco(info da pessoa)\n" );
        printf ( "\nDigite qualquer valor para sair do menu e encerrar o programa\n" );
        printf ( "-----------------------------------------------------------------" );
        printf ( "\nOpcao selecionada:" );
		switch ( getchar() ) {
			case '1':
				pawn = malloc ( SIZE );
				if ( !pawn )
					exit ( 0 );
				printf ( "\nNome da pessoa: " );
				scanf ( "%s",(char*)pawn );
				printf ( "\nIdade da pessoa: " );
				scanf ( "%d",(int*)(pawn+10*sizeof(char)) );
				printf ( "\nTelefone da pessoa: " );
				scanf ( "%d",(int*)(pawn+10*sizeof(char)+sizeof(int)) );
				*(int*)(pawn+10*sizeof(char)+2*sizeof(int))=0;
				*(int*)(pawn+10*sizeof(char)+3*sizeof(int))=0;

				pBuffer = Push (pBuffer,pawn);
				if ( !pBuffer )
				exit(1);
				getchar();
				break;
			case '2':
				list ( pBuffer );
				getchar();
				break;
			case '3':
				pBuffer = Pop ( pBuffer );
				getchar();
				break;
			default:
				if ( pBuffer ){
					while (1){
						exc = *(void**)(bufferBloco);
						if ( *(int*)(*bufferBloco+10*sizeof(char)+3*sizeof(int))==0 ){
							free ( exc );
							break;
						}
						pBuffer = (int*)*(int*)(*bufferBloco+10*sizeof(char)+3*sizeof(int));
						free ( exc );
						free ( pawn );
					}	
					printf ( "\nBuffer Limpo e saindo do menu!" );
				}
				exit ( 0 );
				break;
		}
	}
}