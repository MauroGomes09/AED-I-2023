#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char names[100] = "";
char str[15] = "";
int size = 0;
char * pointer;

int main () {

int opcao;

do {
printf ( "Escolha uma opcao( Para selecionar somente digite o numero da opcao que deseja)\n" );
printf ( "1 -> Adicionar nome\n" );
printf ( "2 -> Remover nome\n" );
printf ( "3 -> Listar nomes\n" );
printf ( "4 -> Sair do menu\n" );
printf ( "Opcao: " );
scanf ( "%d", &opcao );

switch ( opcao )
{
case 1:
    add_name();    
    break;
case 2:
    remove_name();
    break;
case 3:
    list_names();
    break;
case 4:
    printf ( "Opcao selecionada: Sair do menu\n" );
    break;
default:
    printf ( "Opcao invalida. Tente novamente" );
    break;
}
} while ( opcao != 4);

return 0;
}

void add_name () {
    printf ( "\n\nDigite um nome: " );
    scanf ( "%s", str );
    strcat ( str, "-" );
    strcat ( names, str );
};

void list_names() {
    char namesCpy [ 100 ];
    strcpy ( namesCpy, names );
    pointer = strtok ( namesCpy, "-" );
    while ( pointer != NULL ) {
        printf ( "%s\n", pointer );
        pointer = strtok ( NULL, "-" );
    }
};

void remove_name() {
    printf ( "\nDigite um nome para remover: " );
    scanf ( "%s", str );
    pointer = strstr ( names, str );
    if ( pointer != NULL ) {
        memmove ( pointer,
        pointer + strlen (str),
        strlen ( pointer ) + 1);
    }
};