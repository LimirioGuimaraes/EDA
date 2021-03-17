#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LeituraDicionario.h"

int sair(){
    printf("Saindo do programa...\n\n");
}

int main(){

    int seletor = 1;
    FILE *dicionario;

    dicionario = NULL;

    do {
        printf("\n\tMenu de opções:\n\n");
        printf("1. Selecionar arquivo dicionário\n");
        printf("2. Selecionar texto de referência A\n");
        printf("3. Selecionar texto de referência B\n");
        printf("4. Comparar textos de referência e dicionário\n");
        printf("0. sair\n\n");
        printf("Digite a opção desejada: ");

        scanf("%d", &seletor);
        system ("cls || clear");

        switch (seletor){
            case 1:
                dicionario = LeituraDicionario(dicionario);
                printf("\n%p\n",dicionario);
                break;
            case 2:
                printf("\nVocê selecionou a opção 2\n");
                break;
            case 3:
                printf("\nVocê selecionou a opção 3\n");
                break;
            case 4:
                printf("\nVocê selecionou a opção 4\n");
                break;
            case 0:
                sair();
                break;

            default:
                printf("digite uma opção válida!\n");
        }
    } while (seletor);

    fclose(dicionario);

    return 0;
}
